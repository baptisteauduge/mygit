// MyGit Project
//
// mygit_create_delation_commit.h
// File description:
//    mygit_create_delation_commit.h

#ifndef MYGIT_CREATE_DELATION_COMMIT_H
#define MYGIT_CREATE_DELATION_COMMIT_H

#include "libs/list/list.h"

/**
 * @brief Create a deletion commit on the branch with the provided message.
 * It means that the function is committing the files that are not in conflict.
 * (i.e. the files that are not in the conflicts list)
 *
 * @param branch The name of the branch on which the commit will be created.
 * @param conflicts The list of the files in conflict.
 * @param message (Optional) The message of the commit. (Default: "mygit:
 * deletion commit")
 */
void mygit_create_deletion_commit(const char *branch, const list_t *conflicts,
                                  const char *message);

#endif
