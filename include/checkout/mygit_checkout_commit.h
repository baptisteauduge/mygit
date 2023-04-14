// MyGit Project
//
// mygit_checkout_commit.h
// File description:
//    mygit_checkout_commit.h

#ifndef MYGIT_CHECKOUT_COMMIT_H
#define MYGIT_CHECKOUT_COMMIT_H

/**
 * @brief Function used to checkout to a commit (i.e. change the current branch,
 * i.e. change the HEAD and restore the working directory) using a pattern, the
 * pattern should match the first characters of the commit hash. If the pattern
 * matches more than one commit, the functions will not checkout to any commit,
 * but will print the list of commits matching the pattern. If the pattern
 * matches only one commit, the function will checkout to this commit. If the
 * pattern does not match any commit, the function will not do anything, will
 * print an error message.
 *
 * @param pattern The pattern of the commit
 * @return int 1 if the commit as been checked out, 0 otherwise
 */
int mygit_checkout_commit(char *pattern);

#endif
