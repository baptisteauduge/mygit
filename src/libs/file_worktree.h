// Sorbonne University, 2022 - 2023
// MyGit Project
//
// file_worktree.h
// File description:
//      This file contains the signatures of the functions used to treat
//      worktrees and files

#ifndef FILE_WORKTREE_H
#define FILE_WORKTREE_H

#include "worktree.h"

/**
 * @brief Create a blob file representing the WorkTree. The function is using
 * tmp file to get the hash of the file. The function returns the hash of the
 * content of the WorkTree file.
 *
 * @param wt
 * @return char*
 */
char *create_blob_of_worktree(WorkTree *wt);

#endif