// MyGit Project
//
// create_list_branches.h
// File description:
//    create_list_branches.h

#ifndef CREATE_LIST_BRANCHES_H
#define CREATE_LIST_BRANCHES_H

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

#endif