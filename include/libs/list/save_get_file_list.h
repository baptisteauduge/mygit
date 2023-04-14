// MyGit Project
//
// save_get_file_list.h
// File description:
//    save_get_file_list.h

#ifndef SAVE_GET_FILE_LIST_H
#define SAVE_GET_FILE_LIST_H

#include "libs/list/list.h"

/**
 * @brief Save a list to a file using the @ref list_to_str function.
 *
 * @param list The list to save.
 * @param path The path to the file.
 */
void save_list_to_file(list_t *list, const char *path);

/**
 * @brief Get the list from file using the @ref str_to_list function.
 *
 * @param path The path to the file.
 * @return list_t* The list from the file or NULL if an error occurred.
 */
list_t *get_list_from_file(const char *path);

#endif
