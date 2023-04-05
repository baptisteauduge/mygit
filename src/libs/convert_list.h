// Sorbonne University, 2022 - 2023
// MyGit Project
//
// convert_list.h
// File description:
//     This file contains the signatures of the functions to convert a list in
//     another format.

#ifndef CONVERT_LIST_H
#define CONVERT_LIST_H

#define MAX_FILES 100
#define SEPARATOR_LIST_STRING "|"
#define MAX_LEN_DATA 100

#include "list.h"

/**
 * @brief Function used to create a List using a string,
 * format must be : "firstCell|secondCell| ... | lastCell"
 * WHERE "|" is the SEPARATOR_LIST_STRING (in a define)
 *
 * @param str
 * @return List**
 */
List **string_to_list(const char *str);

/**
 * @brief List to string, return NULL if error
 *
 * @param list
 * @return char*
 */
char *list_to_string(List **list);

/**
 * @brief Function used to save a list into a file
 *
 * @param list
 * @param path
 */
void list_to_file(List **list, const char *path);

/**
 * @brief Function used to load a list from a file
 *
 * @param path
 * @return List**
 */
List **file_to_list(const char *path);

#endif
