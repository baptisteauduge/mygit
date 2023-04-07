// MyGit Project
//
// convert_str_work_tree.h
// File description:
//    convert_str_work_tree.h

#ifndef CONVERT_STR_WORK_TREE_H
#define CONVERT_STR_WORK_TREE_H

#include "work_tree/work_tree.h"
#include <stddef.h>

size_t size_work_tree_to_str(const work_tree_t *wf);
char *convert_work_tree_to_str(const work_tree_t *wt);
work_tree_t *convert_str_to_work_tree(const char *str);

#endif