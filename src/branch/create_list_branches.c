// MyGit Project
//
// create_list_branches.c
// File description:
//    create_list_branches.c

#include "branch/create_list_branches.h"
#include "branch/get_branch_commit_tree.h"
#include "commit/mygit_commit_pre_checks.h"
#include "libs/commit/commit.h"
#include "libs/commit/get_work_tree_commit.h"
#include "libs/file/read_write_file.h"
#include "refs/refs.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

int does_branch_exists(const char *branch)
{
  char *ref_content = NULL;

  if (!branch)
    return 0;
  ref_content = get_ref(branch);
  if (!ref_content)
    return 0;
  free(ref_content);
  return 1;
}

int create_branch_if_not_exists(const char *branch)
{
  char *head_hash = NULL;

  if (!branch || does_branch_exists(branch))
    return -1;
  head_hash = get_ref(MYGIT_FILE_REF_HEAD);
  if (!head_hash)
    return 0;
  create_or_update_ref(branch, head_hash);
  free(head_hash);
  return 1;
}

char *get_current_branch(void)
{
  char *current_branch = NULL;

  current_branch = get_file_content(MYGIT_PATH_CURRENT_BRANCH);
  return current_branch;
}

work_tree_t *get_work_tree_from_branch(const char *branch)
{
  char *commit_hash = NULL;
  work_tree_t *wt_branch = NULL;

  if (!branch)
    return NULL;
  commit_hash = get_ref(branch);
  if (!commit_hash)
    return NULL;
  wt_branch = get_work_tree_from_commit_hash(commit_hash);
  free(commit_hash);
  return wt_branch;
}

work_tree_t *get_work_tree_current_branch(void)
{
  char *current_branch = NULL;
  work_tree_t *wt_current_branch = NULL;

  current_branch = get_current_branch();
  if (!current_branch)
    return NULL;
  if (!check_if_head_is_in_branch(current_branch)) {
    free(current_branch);
    return NULL;
  }
  wt_current_branch = get_work_tree_from_branch(current_branch);
  free(current_branch);
  return wt_current_branch;
}
