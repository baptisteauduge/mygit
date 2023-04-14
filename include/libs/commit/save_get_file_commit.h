// MyGit Project
//
// save_get_file_commit.h
// File description:
//    save_get_file_commit.h

#ifndef SAVE_GET_FILE_COMMIT_H
#define SAVE_GET_FILE_COMMIT_H

#include "libs/commit/commit.h"

/**
 * @brief Save the commit object to a file. The function is based on the
 * @ref convert_commit_to_str function.
 *
 * @param commit The commit to save.
 * @param path The path to save the commit to.
 */
void save_commit_to_file(commit_t *commit, const char *path);

/**
 * @brief Get the commit object from a file. The function is based on the
 * @ref convert_str_to_commit function.
 *
 * @param path The path to get the commit from.
 * @return commit_t* The commit. NULL if an error occurred.
 */
commit_t *get_commit_from_file(const char *path);

#endif