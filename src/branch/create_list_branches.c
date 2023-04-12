// MyGit Project
//
// create_list_branches.c
// File description:
//    create_list_branches.c

#include "branch/create_list_branches.h"
#include "file/read_write_file.h"
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
    return 0;
  head_hash = get_ref(MYGIT_FILE_REF_HEAD);
  if (!head_hash)
    return 0;
  create_or_update_ref(branch, head_hash);
  return 1;
}

char *get_current_branch(void)
{
  char *current_branch = NULL;

  current_branch = get_file_content(MYGIT_PATH_CURRENT_BRANCH);
  return current_branch;
}
