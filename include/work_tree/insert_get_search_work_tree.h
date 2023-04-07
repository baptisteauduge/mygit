// MyGit Project
//
// insert_get_search_work_tree.h
// File description:
//    insert_get_search_work_tree.h

#ifndef INSERT_GET_SEARCH_WORK_TREE_H
#define INSERT_GET_SEARCH_WORK_TREE_H

#include "work_tree/work_tree.h"

int append_work_tree(work_tree_t *wt, const char *name, const char *hash,
                     int mode);
int index_in_work_tree(const work_tree_t *wt, const char *name);

#endif