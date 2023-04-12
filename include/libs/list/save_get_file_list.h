// MyGit Project
//
// save_get_file_list.h
// File description:
//    save_get_file_list.h

#ifndef SAVE_GET_FILE_LIST_H
#define SAVE_GET_FILE_LIST_H

#include "libs/list/list.h"

void save_list_to_file(list_t *list, const char *path);
list_t *get_list_from_file(const char *path);

#endif
