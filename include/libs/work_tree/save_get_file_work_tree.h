// MyGit Project
//
// save_get_file_work_tree.h
// File description:
//    save_get_file_work_tree.h

#ifndef SAVE_GET_FILE_WORK_TREE_H
#define SAVE_GET_FILE_WORK_TREE_H

#include "libs/work_tree/work_tree.h"

int work_tree_to_file(const work_tree_t *wt, const char *path);
work_tree_t *file_to_work_tree(const char *path);

#endif
