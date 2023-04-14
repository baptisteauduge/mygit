// MyGit Project
//
// save_content_and_work_tree.h
// File description
//    save_content_and_work_tree.h

#ifndef SAVE_CONTENT_AND_WORK_TREE_H
#define SAVE_CONTENT_AND_WORK_TREE_H

#include "libs/work_tree/work_tree.h"

/**
 * @brief Create blob of all the files in the work_tree, put the hash of the
 * blob in the work_tree and save the work_tree.
 *
 * @param wt The work_tree to save.
 * @param path The path where the work_tree must be saved. (usually the path of
 * the repository (or ".")
 * @return char* The hash of the blob of the work_tree.
 */
char *save_content_and_work_tree(work_tree_t *wt, const char *path);

#endif
