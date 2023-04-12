// MyGit Project
//
// work_tree.h
// File description:
//    work_tree.h

#ifndef WORK_TREE_H
#define WORK_TREE_H

#define WORK_TREE_MAX_SIZE 100

#include "libs/work_file/work_file.h"
#include <stddef.h>

typedef struct work_tree_s
{
  work_file_t *tab;
  size_t max_size;
  size_t size;
} work_tree_t;

work_tree_t *create_and_init_work_tree();
void free_work_tree(work_tree_t *wt);

#endif
