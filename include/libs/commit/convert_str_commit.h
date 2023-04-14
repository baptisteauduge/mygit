// MyGit Project
//
// convert_str_commit.h
// File description:
//    convert_str_commit.h

#ifndef CONVERT_STR_COMMIT_H
#define CONVERT_STR_COMMIT_H

#include "libs/commit/commit.h"

/**
 * @brief Convert the commit provided to a string. The string is allocated, and
 * must be freed by the caller. The string is formatted as follow:
 * "KEY1:VALUE1\nKEY2=VALUE2\nKEY3=VALUE3\n" etc. The format between newlines is
 * defined in the @ref convert_key_val_to_str function.
 *
 * @param commit The commit to convert to a string.
 * @return char* The string representing the commit. NULL if an error occurred.
 */
char *convert_commit_to_str(commit_t *commit);

/**
 * @brief Convert the string provided to a commit. The string must be formatted
 * as follow:
 * "KEY1:VALUE1\nKEY2=VALUE2\nKEY3=VALUE3\n"
 *
 * @param str The string to convert to a commit.
 * @return commit_t* The commit representing the string. NULL if an error
 * occurred.
 */
commit_t *convert_str_to_commit(const char *str);

#endif
