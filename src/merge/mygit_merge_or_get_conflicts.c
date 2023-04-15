// MyGit Project
//
// mygit_merge_or_get_conflicts.c
// File description:
//    mygit_merge_or_get_conflicts.c

#include "merge/mygit_merge_or_get_conflicts.h"
#include "branch/create_list_branches.h"
#include "libs/commit/commit.h"
#include "libs/commit/create_blob_of_commit.h"
#include "libs/commit/insert_key_val_in_commit.h"
#include "libs/work_tree/restore_work_tree.h"
#include "libs/work_tree/save_content_and_work_tree.h"
#include "libs/work_tree/work_tree.h"
#include "merge/mygit_merge_work_trees.h"
#include "refs/refs.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

// We can safely don't verify the return value of all the functions
// because all functions don't raise errors if they receives bad parameters
// and for the "homemade" free_functions, we don't care if the pointer is NULLs
// This functions doesn't respect the 25 lines rule because it's a little bit
// complicated to split it in multiple functions. It's not a good practice to
// split a function in multiple functions if it's not possible to do it without
// losing the readability of the code
list_t *mygit_merge_or_get_conflicts(const char *remote_branch, const char *message)
{
  work_tree_t *wt_curr_br = NULL;
  work_tree_t *wt_remote_br = NULL;
  work_tree_t *wt_merged = NULL;
  char *hash_wt_merged = NULL;
  char *curr_branch = NULL;
  list_t *conflicted_files = NULL;
  commit_t *commit_merge = NULL;
  char *ref_curr_branch = NULL;
  char *ref_remote_branch = NULL;
  char *hash_commit = NULL;

  if (!remote_branch)
    return NULL;
  // Get the current branch and init the conflicted files list
  curr_branch = get_current_branch();
  wt_curr_br = get_work_tree_from_branch(curr_branch);
  wt_remote_br = get_work_tree_from_branch(remote_branch);
  conflicted_files = create_init_list();
  wt_merged =
      mygit_merge_work_trees(wt_curr_br, wt_remote_br, &conflicted_files);
  // If there is conflict, we returns the list of conflicted files and free
  // memory
  if (*conflicted_files) {
    free_work_tree(wt_curr_br);
    free_work_tree(wt_remote_br);
    free_work_tree(wt_merged);
    free(curr_branch);
    return conflicted_files;
  }
  // If there is no conflict, we can save the work tree and create the merge
  // commit
  hash_wt_merged = save_content_and_work_tree(wt_merged, PREFIX_PATH);
  commit_merge = create_commit_with_tree_key_val(hash_wt_merged);
  // We update the keys of the commit to match with the merge commit
  ref_remote_branch = get_ref(remote_branch);
  ref_curr_branch = get_ref(curr_branch);
  if (message)
    insert_key_val_in_commit(commit_merge, COMMIT_KEY_MESSAGE, message);
  insert_key_val_in_commit(commit_merge, COMMIT_KEY_MERGED_PARENT,
                           ref_remote_branch);
  insert_key_val_in_commit(commit_merge, COMMIT_KEY_PARENT, ref_curr_branch);
  // We create the blob of the commit and update the refs
  hash_commit = create_blob_of_commit(commit_merge);
  create_or_update_ref(curr_branch, hash_commit);
  create_or_update_ref(MYGIT_FILE_REF_HEAD, hash_commit);
  // We delete the merged branch and restore the work tree of the current branch
  delete_ref(remote_branch);
  restore_work_tree(wt_merged, PREFIX_PATH);
  // We free memory and return NULL because there is no conflict
  free_work_tree(wt_curr_br);
  free_work_tree(wt_remote_br);
  free_work_tree(wt_merged);
  free_commit(commit_merge);
  free(hash_wt_merged);
  free(hash_commit);
  free(ref_curr_branch);
  free(ref_curr_branch);
  free(curr_branch);
  free(conflicted_files);
  return NULL;
}