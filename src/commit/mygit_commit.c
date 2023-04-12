// MyGit Project
//
// mygit_commit.c
// File description:
//    mygit_commit.c

#include "commit/mygit_commit.h"
#include "branch/get_branch_commit_tree.h"
#include "commit/mygit_commit_pre_checks.h"
#include "libs/commit/commit.h"
#include "libs/commit/create_blob_of_commit.h"
#include "libs/commit/insert_key_val_in_commit.h"
#include "libs/file/list_files.h"
#include "libs/file/read_write_file.h"
#include "libs/list/insert_get_search_list.h"
#include "libs/work_tree/save_content_and_work_tree.h"
#include "libs/work_tree/save_get_file_work_tree.h"
#include "refs/refs_utils.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static work_tree_t *get_added_work_tree_and_delete(void)
{
  work_tree_t *work_tree = NULL;

  if (!does_file_exists(MYGIT_PATH_ADD)) {
    LOG_ERROR("Error: no files added\n");
    return NULL;
  }
  work_tree = file_to_work_tree(MYGIT_PATH_ADD);
  remove(MYGIT_PATH_ADD);
  return work_tree;
}

static commit_t *get_commit_from_added(void)
{
  commit_t *commit = NULL;
  work_tree_t *work_tree = NULL;
  char *hash_work_tree = NULL;

  work_tree = get_added_work_tree_and_delete();
  if (!work_tree)
    return NULL;
  hash_work_tree = save_content_and_work_tree(work_tree, PREFIX_PATH);
  if (!hash_work_tree) {
    free_work_tree(work_tree);
    return NULL;
  }
  commit = create_commit_with_tree_key_val(hash_work_tree);
  free(hash_work_tree);
  free_work_tree(work_tree);
  return commit;
}

static char *fill_new_commit_create_blob_and_get_hash(commit_t *new_commit,
                                                      const char *message,
                                                      const char *branch_name)
{
  char *hash_last_commit = NULL;

  hash_last_commit = get_hash_from_last_commit_in_branch(branch_name);
  if (!hash_last_commit)
    return NULL;
  if (strcmp(hash_last_commit, "") != 0)
    insert_key_val_in_commit(new_commit, COMMIT_KEY_PARENT, hash_last_commit);
  free(hash_last_commit);
  if (message)
    insert_key_val_in_commit(new_commit, COMMIT_KEY_MESSAGE, message);
  return create_blob_of_commit(new_commit);
}

char *mygit_commit(const char *branch_name, const char *message)
{
  int pre_checks = 0;
  commit_t *new_commit = NULL;
  char *hash_new_commit = NULL;

  if (!branch_name)
    return NULL;
  pre_checks = check_if_refs_exists() && check_if_branch_exists(branch_name) &&
               check_if_head_is_in_branch(branch_name);
  if (!pre_checks)
    return NULL;
  new_commit = get_commit_from_added();
  if (!new_commit)
    return NULL;
  hash_new_commit = fill_new_commit_create_blob_and_get_hash(
      new_commit, message, branch_name);
  free_commit(new_commit);
  if (!hash_new_commit)
    return NULL;
  set_head_and_branch_hash_last_commit(branch_name, hash_new_commit);
  return hash_new_commit;
}

static int get_commits_from_ref_and_append_list(list_t **list_all_commits,
                                                const char *ref)
{
  list_t *list_current_commits = NULL;
  list_t *tmp = NULL;

  list_current_commits = get_commit_from_branch_list(ref);
  if (!list_current_commits)
    return 0;
  tmp = concat_list_without_duplicate(*list_all_commits, list_current_commits);
  if (!tmp) {
    free_list(list_current_commits);
    return 0;
  }
  free_list(*list_all_commits);
  free_list(list_current_commits);
  *list_all_commits = tmp;
  return 1;
}

list_t *get_list_all_commits(void)
{
  list_t *list_all_refs = get_list_files_and_dir(MYGIT_DIR_REFS);
  cell_t *current_ref = NULL;
  list_t *list_all_commits = NULL;

  if (!list_all_refs)
    return NULL;
  current_ref = *list_all_refs;
  while (current_ref) {
    if (!get_commits_from_ref_and_append_list(&list_all_commits,
                                              current_ref->data)) {
      free_list(list_all_refs);
      free_list(list_all_commits);
      return NULL;
    }
    current_ref = current_ref->next;
  }
  free_list(list_all_refs);
  return list_all_commits;
}
