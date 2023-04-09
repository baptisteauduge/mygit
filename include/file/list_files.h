// MyGit Project
//
// list_files.h
// File description:
//    list_files.h

#ifndef LIST_FILES_H
#define LIST_FILES_H

#include "list/list.h"

list_t *get_list_files_and_dir(const char *path);
int does_file_exists(const char *path);
int is_file(const char *file);

#endif
