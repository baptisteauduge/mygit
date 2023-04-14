// MyGit Project
//
// mygit_checkout_branch.h
// File description:
//    mygit_checkout_branch.h

#ifndef MYGIT_CHECKOUT_BRANCH_H
#define MYGIT_CHECKOUT_BRANCH_H

/**
 * @brief Function used to checkout to a branch (i.e. change the current branch,
 * i.e. change the HEAD and restore the working directory)
 *
 * @param branch_name The name of the branch
 * @return int -1 if the branch does not exists, 0 if there is an error, 1 if
 * the branch has been checked out
 */
int mygit_checkout_branch(const char *branch_name);

#endif
