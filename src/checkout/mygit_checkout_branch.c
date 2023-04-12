// MyGit Project
//
// mygit_checkout_branch.c
// File description:
//    mygit_checkout_branch.c

#include "checkout/mygit_checkout_branch.h"
#include "branch/create_list_branches.h"
#include "libs/commit/restore_commit.h"
#include "libs/file/get_path_absolute.h"
#include "libs/file/read_write_file.h"
#include "utils/utils.h"
#include <stdlib.h>

void mygit_checkout_branch(const char *branch_name)
{
  char *hash_last_commit = NULL;
  char *new_branch_path = NULL;

  if (!branch_name || !does_branch_exists(branch_name))
    return;
  write_file_content(MYGIT_PATH_CURRENT_BRANCH, branch_name);
  new_branch_path = get_path_absolute(MYGIT_DIR_REFS, branch_name);
  if (!new_branch_path)
    return;
  hash_last_commit = get_file_content(new_branch_path);
  if (!hash_last_commit) {
    free(new_branch_path);
    return;
  }
  write_file_content(MYGIT_FILE_REF_HEAD, hash_last_commit);
  restore_commit_from_hash(hash_last_commit);
  free(hash_last_commit);
  free(new_branch_path);
  return;
}
