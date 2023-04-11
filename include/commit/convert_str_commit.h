// MyGit Project
//
// convert_str_commit.h
// File description:
//    convert_str_commit.h

#ifndef CONVERT_STR_COMMIT_H
#define CONVERT_STR_COMMIT_H

#include "commit/commit.h"

char *convert_commit_to_str(commit_t *commit);
commit_t *convert_str_to_commit(const char *str);

#endif
