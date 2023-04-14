// MyGit Project
//
// convert_str_list.h
// File description:
//    convert_str_list.h

#ifndef CONVERT_STR_LIST_H
#define CONVERT_STR_LIST_H

#define SEPARATOR_LIST_STRING "|"

#include "libs/list/list.h"
#include <stddef.h>

/**
 * @brief The size required to store the list in a string. The size is
 * calculated with the size of the elements of the list and the size of the
 * separator.
 *
 * @param list The list to get the size from.
 * @return size_t The size required to store the list in a string.
 */
size_t size_list_to_str(list_t *list);

/**
 * @brief Convert a list to a string, the string is allocated and must be freed.
 * The format is "element1|element2|element3|..." where the separator is
 * defined by @ref SEPARATOR_LIST_STRING constant.
 *
 * @param list The list to convert
 * @return char* The string converted or NULL if any error occurred
 */
char *list_to_str(list_t *list);

/**
 * @brief Convert a string to a list. The required format is
 * "element1|element2|element3|..." where the separator is defined by @ref
 * SEPARATOR_LIST_STRING constant.
 *
 * @param str The string to convert
 * @return list_t* The list converted or NULL if any error occurred
 */
list_t *str_to_list(const char *str);

#endif
