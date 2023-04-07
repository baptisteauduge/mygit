// MyGit Project
//
// convert_str_list.h
// File description:
//    convert_str_list.h

#ifndef CONVERT_STR_LIST_H
#define CONVERT_STR_LIST_H

#define SEPARATOR_LIST_STRING "|"

#include "list/list.h"
#include <stddef.h>

size_t size_list_to_str(list_t *list);
char *list_to_str(list_t *list);
list_t *str_to_list(const char *str);

#endif
