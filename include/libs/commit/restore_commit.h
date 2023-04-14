// MyGit Project
//
// restore_commit.h
// File description:
//    restore_commit.h

#ifndef RESTORE_COMMIT_H
#define RESTORE_COMMIT_H

#include "libs/commit/commit.h"

/**
 * @brief Restore the working directory from the commit object.
 *
 * @param commit The commit object to restore the working directory from.
 */
void restore_commit(commit_t *commit);

/**
 * @brief Restore the working directory from the commit hash. (The commit hash
 * must exists as a blob in the repository.)
 *
 * @param hash_commit The commit hash to restore the working directory from.
 */
void restore_commit_from_hash(const char *hash_commit);

#endif
