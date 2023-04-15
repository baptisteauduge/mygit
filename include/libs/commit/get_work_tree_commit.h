// MyGit Project
//
// get_work_tree_commit.h
// File description:
//    get_work_tree_commit.h

#ifndef GET_WORK_TREE_COMMIT_H
#define GET_WORK_TREE_COMMIT_H

#include "libs/commit/commit.h"
#include "libs/work_tree/work_tree.h"

/**
 * @brief Get the work tree from commit object. The function is based on the
 * @ref get_value_from_key_in_commit function the @ref file_to_work_tree
 * function. Note that the work tree hash must be stored in the commit object
 * with the key @ref COMMIT_KEY_HASH.
 *
 * @param commit The commit to get the work tree from.
 * @return work_tree_t* The work tree. NULL if an error occurred.
 */
work_tree_t *get_work_tree_from_commit(commit_t *commit);

/**
 * @brief Get the work tree from commit hash.
 * 
 * @param commit_hash The hash of the commit to get the work tree from.
 * @return work_tree_t* The work tree. NULL if an error occurred.
 */
work_tree_t *get_work_tree_from_commit_hash(const char *commit_hash);

#endif
