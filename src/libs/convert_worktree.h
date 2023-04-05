// Sorbonne University, 2022 - 2023
// MyGit Project
//
// convert_worktree.h
// File description:
//     This file contains the signatures of the functions to convert a
//     worktree in another format.

#ifndef CONVERT_WORKTREE_H
#define CONVERT_WORKTREE_H

#include "worktree.h"

/**
 * @brief Return a string representing the WorkTree. Each WorkFile is separated
 * by a newline.
 *
 * @param wt
 * @return char*
 */
char *worktree_to_string(const WorkTree *wt);

/**
 * @brief Return the WorkTree corresponding to a String. Refer to
 * worktree_to_string and workfile_to_string
 *
 * @param str
 * @return WorkTree*
 */
WorkTree *string_to_worktree(const char *str);

/**
 * @brief Write the WorkTree in a file, return 0 if everything went well, -1
 * otherwise.
 *
 * @param wt
 * @param file
 * @return int
 */
int worktree_to_file(const WorkTree *wt, const char *file);

/**
 * @brief Create a WorkTree from a file. If any error, the function will return
 * NULL
 *
 * @param file
 * @return WorkTree*
 */
WorkTree *file_to_worktree(const char *file);

#endif