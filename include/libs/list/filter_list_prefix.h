// MyGit Project
//
// filter_list_prefix.h
// File description:
//    filter_list_prefix.h

#ifndef FILTER_LIST_PREFIX_H
#define FILTER_LIST_PREFIX_H

#include "libs/list/list.h"

/**
 * @brief Filter the list to get only the elements that start with the pattern
 * provided. The returned list is a new one and msut be freed. The given list is
 * not modified.
 *
 * @param list The list to filter
 * @param pattern The pattern to filter the list
 * @return list_t* The filtered list or NULL if any error occurred
 */
list_t *filter_list_prefix(const list_t *list, char *pattern);

#endif
