// MyGit Project
//
// get_branch_commit_tree.c
// File description:
//    get_branch_commit_tree.c

#include "branch/get_branch_commit_tree.h"
#include "branch/create_list_branches.h"
#include "libs/commit/insert_key_val_in_commit.h"
#include "libs/commit/save_get_file_commit.h"
#include "libs/file/create_blob.h"
#include "libs/list/insert_get_search_list.h"
#include "refs/refs.h"
#include "utils/realloc_and_concat.h"
#include <stdio.h>
#include <stdlib.h>

commit_t *get_commit_from_hash(const char *hash)
{
  char *commit_path = NULL;
  commit_t *commit = NULL;

  if (!hash)
    return NULL;
  commit_path = get_path_from_hash(hash);
  if (!commit_path)
    return NULL;
  commit = get_commit_from_file(commit_path);
  free(commit_path);
  return commit;
}

static void get_predecessors_and_concat_rec(char **branch_str, const char *hash)
{
  commit_t *commit = NULL;
  char *predecessor_hash = NULL;
  char *message = NULL;

  if (!hash || !branch_str)
    return;
  commit = get_commit_from_hash(hash);
  if (!commit)
    return;
  realloc_and_concat_after(branch_str, hash);
  predecessor_hash = get_value_from_key_in_commit(commit, COMMIT_KEY_PARENT);
  message = get_value_from_key_in_commit(commit, COMMIT_KEY_MESSAGE);
  if (message) {
    realloc_and_concat_after(branch_str, "\t");
    realloc_and_concat_after(branch_str, message);
    free(message);
  }
  realloc_and_concat_after(branch_str, "\n");
  get_predecessors_and_concat_rec(branch_str, predecessor_hash);
  if (predecessor_hash)
    free(predecessor_hash);
  free_commit(commit);
}

char *get_branch_commits_tree_str(const char *branch_name)
{
  char *current_branch_head = NULL;
  char *branch_str = NULL;

  if (!branch_name)
    return NULL;
  current_branch_head = get_ref(branch_name);
  if (!current_branch_head)
    return NULL;
  branch_str = malloc(sizeof(char));
  if (!branch_str) {
    free(current_branch_head);
    return NULL;
  }
  get_predecessors_and_concat_rec(&branch_str, current_branch_head);
  free(current_branch_head);
  return branch_str;
}

void print_branch_commit_tree(char *branch)
{
  char *branch_commit_tree_str = NULL;

  if (!branch)
    return;
  branch_commit_tree_str = get_branch_commits_tree_str(branch);
  if (!branch_commit_tree_str)
    return;
  printf("%s\n", branch_commit_tree_str);
  free(branch_commit_tree_str);
}

static void append_list_commit_parent_rec(list_t *list, const char *hash)
{
  commit_t *commit = NULL;
  char *parent_hash = NULL;

  if (!hash || !list)
    return;
  commit = get_commit_from_hash(hash);
  if (!commit)
    return;
  create_and_insert_cell_in_list(list, hash);
  parent_hash = get_value_from_key_in_commit(commit, COMMIT_KEY_PARENT);
  free_commit(commit);
  append_list_commit_parent_rec(list, parent_hash);
  if (parent_hash)
    free(parent_hash);
}

list_t *get_commit_from_branch_list(const char *branch_name)
{
  char *current_branch_head = NULL;
  list_t *list_commit = NULL;

  if (!branch_name)
    return NULL;
  current_branch_head = get_ref(branch_name);
  if (!current_branch_head)
    return NULL;
  list_commit = create_init_list();
  if (!list_commit) {
    free(current_branch_head);
    return NULL;
  }
  append_list_commit_parent_rec(list_commit, current_branch_head);
  free(current_branch_head);
  return list_commit;
}

commit_t *get_last_commit_from_branch(const char *branch_name)
{
  char *hash_commit = NULL;
  commit_t *commit = NULL;

  if (!branch_name || !does_branch_exists(branch_name))
    return NULL;
  hash_commit = get_ref(branch_name);
  if (!hash_commit)
    return NULL;
  commit = get_commit_from_hash(hash_commit);
  free(hash_commit);
  return commit;
}
