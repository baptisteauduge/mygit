// MyGit Project
//
// list_files.h
// File description:
//    list_files.h

#ifndef LIST_FILES_H
#define LIST_FILES_H

#include "libs/list/list.h"

/**
 * @brief Get the list files and dir in the provided path
 *
 * @param path The path to the directory
 * @return list_t* The list of files and directories in the path provided
 * or NULL if any error occured
 */
list_t *get_list_files_and_dir(const char *path);

/**
 * @brief Check if the file exists or not (or the directory)
 * 
 * @param path The path to the file
 * @return int 1 if the file exists, 0 otherwise
 */
int does_file_exists(const char *path);

/**
 * @brief Check if the provided path is a file (or a directory)
 * 
 * @param file The path to the file
 * @return int 1 if the path is a file, 0 otherwise
 */
int is_file(const char *file);

#endif
