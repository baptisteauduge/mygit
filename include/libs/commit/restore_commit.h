// MyGit Project
//
// restore_commit.h
// File description:
//    restore_commit.h

#ifndef RESTORE_COMMIT_H
#define RESTORE_COMMIT_H

#include "libs/commit/commit.h"

void restore_commit(commit_t *commit);
void restore_commit_from_hash(const char *hash_commit);

#endif
