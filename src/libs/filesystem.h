// Sorbonne University, 2022 - 2023
// MyGit Project
// 
// filesystem.h
// File description:
//    This file contains the signatures of the filesystem functions.

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#define SIZE_BUFFER_READ_LINE 512

#include "list.h"

/**
 * @brief Function that return a list of all the files and directories in the
 * directory rootDir
 *
 * @param rootDir
 * @return List**
 */
List **get_list_files_and_dir(const char *rootDir);

/**
 * @brief Function that return 1 if the file exist, 0 otherwise
 *
 * @param file
 * @return int
 */
int does_file_exists(const char *file);

/**
 * @brief Function that copy the file from to the file to
 *
 * @param to
 * @param from
 */
void copy_file(const char *to, const char *from);

/**
 * @brief Function used to get the path of the file from the hash
 *
 * @param hash
 * @return char*
 */
char *get_path_from_hash(const char *hash);

/**
 * @brief Function used to create a blob file from a filename
 *
 * @param filename
 */
void create_blob(const char *filename);

#endif
