// MyGit Project
//
// save_get_file_commit.h
// File description:
//    save_get_file_commit.h

#ifndef SAVE_GET_FILE_COMMIT_H
#define SAVE_GET_FILE_COMMIT_H

#include "commit/commit.h"

void save_commit_to_file(commit_t *commit, const char *path);

#endif