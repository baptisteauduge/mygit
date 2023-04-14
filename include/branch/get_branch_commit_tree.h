// MyGit Project
//
// get_branch_commit_tree.h
// File description:
//    get_branch_commit_tree.h

#ifndef GET_BRANCH_COMMIT_TREE_H
#define GET_BRANCH_COMMIT_TREE_H

#include "libs/list/list.h"

/**
 * @brief Get a list of all the commits of a branch, from the last to the first,
 * the result is a string
 *
 * @param branch_name The name of the branch
 * @return char* The string containing all the commits of the branch
 */
char *get_branch_commits_tree_str(const char *branch_name);

/**
 * @brief Print the the commits of a branch (from the last to the first)
 * the function is based on @ref get_branch_commits_tree_str
 *
 * @param branch The name of the branch
 */
void print_branch_commit_tree(char *branch);

/**
 * @brief Get the commit from branch as list_t (from the last to the first)
 *
 * @param branch_name The name of the branch
 * @return list_t* The list of commits of the branch
 */
list_t *get_commit_from_branch_list(const char *branch_name);

#endif
