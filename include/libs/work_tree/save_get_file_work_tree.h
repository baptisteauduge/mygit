// MyGit Project
//
// save_get_file_work_tree.h
// File description:
//    save_get_file_work_tree.h

#ifndef SAVE_GET_FILE_WORK_TREE_H
#define SAVE_GET_FILE_WORK_TREE_H

#include "libs/work_tree/work_tree.h"

/**
 * @brief Save the work_tree at the given path using the @ref work_tree_to_str
 * function.
 *
 * @param wt The work_tree to save.
 * @param path The path where the work_tree must be saved.
 * @return int -1 if an error occurred, 0 otherwise.
 */
int work_tree_to_file(const work_tree_t *wt, const char *path);

/**
 * @brief Get the work_tree from the given path using the @ref
 * str_to_work_tree function.
 *
 * @param path The path where the work_tree is saved.
 * @return work_tree_t* The work_tree or NULL if an error occurred.
 */
work_tree_t *file_to_work_tree(const char *path);

#endif
