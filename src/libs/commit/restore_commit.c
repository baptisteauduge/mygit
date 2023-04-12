// MyGit Project
//
// restore_commit.c
// File description:
//    restore_commit.c

#include "libs/commit/restore_commit.h"
#include "libs/commit/commit.h"
#include "libs/commit/get_work_tree_commit.h"
#include "libs/commit/insert_key_val_in_commit.h"
#include "libs/commit/save_get_file_commit.h"
#include "libs/file/create_blob.h"
#include "libs/work_tree/restore_work_tree.h"
#include "libs/work_tree/save_get_file_work_tree.h"
#include "libs/work_tree/work_tree.h"
#include "utils/utils.h"
#include <stdlib.h>

void restore_commit(commit_t *commit)
{
  work_tree_t *wt = NULL;

  if (!commit)
    return;
  wt = get_work_tree_from_commit(commit);
  if (!wt)
    return;
  restore_work_tree(wt, PREFIX_PATH);
  free_work_tree(wt);
}

void restore_commit_from_hash(const char *hash_commit)
{
  commit_t *commit = NULL;
  char *commit_path = NULL;

  if (!hash_commit)
    return;
  commit_path = get_path_from_hash(hash_commit);
  if (!commit_path)
    return;
  commit = get_commit_from_file(commit_path);
  if (!commit) {
    free(commit_path);
    return;
  }
  free(commit_path);
  restore_commit(commit);
  free_commit(commit);
}
