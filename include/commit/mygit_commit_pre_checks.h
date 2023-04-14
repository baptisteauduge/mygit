// MyGit Project
//
// mygit_commit_pre_checks.h
// File description:
//    mygit_commit_pre_checks.h

#ifndef MYGIT_COMMIT_PRE_CHECKS_H
#define MYGIT_COMMIT_PRE_CHECKS_H

/**
 * @brief Check if the refs directory exists. If it does not, the function will
 * print a message, to inform the user that the repository is not initialized.
 *
 * @return int 1 if the refs directory exists, 0 otherwise
 */
int check_if_refs_exists(void);

/**
 * @brief Check if the branch exists. If it does not, the function will print a
 * message, to inform the user that the branch does not exists.
 *
 * @param branch_name The name of the branch
 * @return int 1 if the branch exists, 0 otherwise (i.e. the branch does not
 * exist or there is an error)
 */
int check_if_branch_exists(const char *branch_name);

/**
 * @brief Check if the HEAD is in the branch provided.
 *
 * @param branch_name The name of the branch
 * @return int 1 if the HEAD is in the branch, 0 otherwise.
 */
int check_if_head_is_in_branch(const char *branch_name);

#endif
