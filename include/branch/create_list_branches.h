// MyGit Project
//
// create_list_branches.h
// File description:
//    create_list_branches.h

#ifndef CREATE_LIST_BRANCHES_H
#define CREATE_LIST_BRANCHES_H

#include "libs/work_tree/work_tree.h"

/**
 * @brief Function used to check if a branch exists
 *
 * @param branch The name of the branch
 * @return int 1 if the branch exists, 0 otherwise
 */
int does_branch_exists(const char *branch);

/**
 * @brief Create a branch if it does not exists
 *
 * @param branch The name of the branch
 * @return int -1 if the branch already exists, 0 if there is an error, 1 if the
 * branch has been created
 */
int create_branch_if_not_exists(const char *branch);

/**
 * @brief Get the current branch name (the branch pointed by HEAD)
 *
 * @return char* The name of the current branch
 */
char *get_current_branch(void);

/**
 * @brief Get the work tree from branch name i.e. the work tree of the last
 * commit of the branch.
 *
 * @param branch
 * @return work_tree_t*
 */
work_tree_t *get_work_tree_from_branch(const char *branch);

/**
 * @brief Get the work tree of the current branch. Means that it will returns
 * the work tree of the branch pointed by HEAD (the work tree of the last commit
 * of this branch).
 * Note that the function will check if the HEAD is in a branch. If not, it will
 * return NULL and print an error message.
 *
 * @return work_tree_t The work tree of the current branch
 */
work_tree_t *get_work_tree_current_branch(void);

#endif