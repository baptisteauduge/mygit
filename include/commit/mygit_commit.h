// MyGit Project
//
// mygit_commit.h
// File description:
//    mygit_commit.h

#ifndef MYGIT_COMMIT_H
#define MYGIT_COMMIT_H

#include "libs/list/list.h"

/**
 * @brief Commit the files in the staging area to the branch provided. The
 * function will create a new commit object, and update the branch to point to
 * the new commit. The function will also update the HEAD to point to the new
 * commit.
 * To commit, you must be in the branch you want to commit to. If you are not,
 * the function will print a message, to inform the user that he is not in the
 * branch he wants to commit to. If the branch does not exist, the function will
 * print a message, to inform the user that the branch does not exist. If the
 * staging area is empty, the function will print a message, to inform the user
 * that there is nothing to commit.
 * If you don't want to provide a message, let the message parameter to NULL.
 *
 * @param branch_name The name of the branch to commit to
 * @param message Optional message to add to the commit (can be NULL)
 * @return char* The hash of the new commit if the commit was successful, NULL
 * otherwise (the commit was not successful)
 */
char *mygit_commit(const char *branch_name, const char *message);

/**
 * @brief Get the list of all commits in the repository. There is no order in
 * the list. The list doesn't contains duplicates.
 *
 * @return list_t* The list of all commits in the repository, NULL if an error
 * occurred
 */
list_t *get_list_all_commits(void);

#endif
