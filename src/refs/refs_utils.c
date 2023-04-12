// MyGit Project
//
// refs_utils.c
// File description:
//    refs_utils.c

#include "refs/refs_utils.h"
#include "file/get_path_absolute.h"
#include "file/read_write_file.h"
#include "utils/utils.h"
#include <stdlib.h>
#include <string.h>

char *get_hash_from_last_commit_in_branch(const char *branch_name)
{
  char *branch_path = NULL;
  char *hash = NULL;

  if (!branch_name)
    return NULL;
  branch_path = get_path_absolute(MYGIT_DIR_REFS, branch_name);
  if (!branch_path)
    return NULL;
  hash = get_file_content(branch_path);
  free(branch_path);
  return hash;
}

void set_head_and_branch_hash_last_commit(const char *branch_name,
                                          const char *hash)
{
  char *branch_path = NULL;

  if (!branch_name || !hash)
    return;
  branch_path = get_path_absolute(MYGIT_DIR_REFS, branch_name);
  if (!branch_path)
    return;
  write_file_content(branch_path, hash);
  write_file_content(MYGIT_DIR_REFS "/" MYGIT_FILE_REF_HEAD, hash);
  free(branch_path);
}
