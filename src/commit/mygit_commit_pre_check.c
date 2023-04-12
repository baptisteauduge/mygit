// MyGit Project
//
// mygit_commit_pre_checks.c
// File description:
//    mygit_commit_pre_checks.c

#include "commit/mygit_commit_pre_checks.h"
#include "libs/file/get_path_absolute.h"
#include "libs/file/list_files.h"
#include "libs/file/read_write_file.h"
#include "refs/refs_utils.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if refs exists print error message if not
int check_if_refs_exists(void)
{
  if (!does_file_exists(MYGIT_DIR_REFS)) {
    LOG_ERROR("Error: no refs found, please init a repository first\n");
    return 0;
  }
  return 1;
}

// Check if branch exists print error message if not
int check_if_branch_exists(const char *branch_name)
{
  char *branch_path = NULL;

  branch_path = get_path_absolute(MYGIT_DIR_REFS, branch_name);
  if (!branch_path)
    return 0;
  if (!does_file_exists(branch_path)) {
    fprintf(stderr, "Error: branch `%s` does not exists\n", branch_name);
    free(branch_path);
    return 0;
  }
  free(branch_path);
  return 1;
}

static int get_head_and_branch_hash(char **head_hash, char **branch_hash,
                                    const char *branch_name)
{
  char *branch_path = NULL;

  *head_hash = get_file_content(MYGIT_DIR_REFS "/" MYGIT_FILE_REF_HEAD);
  if (!head_hash)
    return 0;
  branch_path = get_path_absolute(MYGIT_DIR_REFS, branch_name);
  if (!branch_path) {
    free(*head_hash);
    return 0;
  }
  *branch_hash = get_file_content(branch_path);
  if (!*branch_hash) {
    free(*head_hash);
    free(branch_path);
    return 0;
  }
  free(branch_path);
  return 1;
}

// Check if HEAD is in provided branch print error message if not
int check_if_head_is_in_branch(const char *branch_name)
{
  char *head_hash = NULL;
  char *branch_hash = NULL;

  if (!get_head_and_branch_hash(&head_hash, &branch_hash, branch_name))
    return 0;
  if (strcmp(head_hash, branch_hash) != 0) {
    fprintf(stderr, "Error: HEAD is not in branch `%s`\n", branch_name);
    free(head_hash);
    free(branch_hash);
    return 0;
  }
  free(head_hash);
  free(branch_hash);
  return 1;
}