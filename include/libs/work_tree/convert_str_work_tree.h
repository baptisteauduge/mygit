// MyGit Project
//
// convert_str_work_tree.h
// File description:
//    convert_str_work_tree.h

#ifndef CONVERT_STR_WORK_TREE_H
#define CONVERT_STR_WORK_TREE_H

#include "libs/work_tree/work_tree.h"
#include <stddef.h>

/**
 * @brief Get the size required to store the work_tree in a string. The size is
 * calculated with the size of the elements of the work_tree and the size of the
 * separator.
 *
 * @param wf The work_tree to get the size from.
 * @return size_t The size required to store the work_tree in a string.
 */
size_t size_work_tree_to_str(const work_tree_t *wf);

/**
 * @brief Convert a work_tree to a string, the format is
 * "name|hash|mode\nname|hash|mode" where the separator is defined by @ref
 * SEPARATOR_WORK_FILE_STRING constant. If the hash is NULL, the string will
 * contain "name|-|mode". (With a single dash). The format is based on the @ref
 * work_file_to_str function.
 *
 * @param wt The work_tree to convert.
 * @return char* The string containing the work_tree or NULL if an error
 * occurred.
 */
char *convert_work_tree_to_str(const work_tree_t *wt);

/**
 * @brief Convert a string to a work_tree. The required format is
 * "name|hash|mode\nname|hash|mode" where the separator is defined by @ref
 * SEPARATOR_WORK_FILE_STRING constant.
 *
 * @param str The string to convert.
 * @return work_tree_t* The work_tree created or NULL if an error occurred.
 */
work_tree_t *convert_str_to_work_tree(const char *str);

#endif