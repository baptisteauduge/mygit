// MyGit Project
//
// get_work_tree_commit.h
// File description:
//    get_work_tree_commit.h

#include "libs/commit/get_work_tree_commit.h"
#include "branch/get_branch_commit_tree.h"
#include "libs/commit/insert_key_val_in_commit.h"
#include "libs/file/create_blob.h"
#include "libs/work_tree/save_get_file_work_tree.h"
#include <stdlib.h>

work_tree_t *get_work_tree_from_commit(commit_t *commit)
{
  char *hash_wt = NULL;
  char *path_wt = NULL;
  work_tree_t *wt = NULL;

  if (!commit)
    return NULL;
  hash_wt = get_value_from_key_in_commit(commit, COMMIT_KEY_HASH);
  if (!hash_wt)
    return NULL;
  path_wt = get_path_from_hash(hash_wt);
  if (!path_wt) {
    free(hash_wt);
    return NULL;
  }
  wt = file_to_work_tree(path_wt);
  free(hash_wt);
  free(path_wt);
  return wt;
}

work_tree_t *get_work_tree_from_commit_hash(const char *commit_hash)
{
  commit_t *commit = NULL;
  work_tree_t *wt = NULL;

  if (!commit_hash)
    return NULL;
  commit = get_commit_from_hash(commit_hash);
  if (!commit)
    return NULL;
  wt = get_work_tree_from_commit(commit);
  free_commit(commit);
  return wt;
}
