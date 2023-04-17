// MyGit Project
//
// work_tree.h
// File description:
//    work_tree.h

#ifndef WORK_TREE_H
#define WORK_TREE_H

#define WORK_TREE_MAX_SIZE 10000

#include "libs/work_file/work_file.h"
#include <stddef.h>

/**
 * @brief The work_tree structure. It contains a table of work_file_t and the
 * size of the table.
 * @param tab The table of work_file_t.
 * @param max_size The maximum size of the table.
 * @param size The size of the table. (the number of work_file_t in the table)
 */
typedef struct work_tree_s {
  work_file_t *tab;
  size_t max_size;
  size_t size;
} work_tree_t;

/**
 * @brief Create a and init work tree with the @ref WORK_TREE_MAX_SIZE
 * constant as max_size (tab is allocated at this size).
 *
 * @return work_tree_t* The work_tree or NULL if an error occurred.
 */
work_tree_t *create_and_init_work_tree();

/**
 * @brief Free the work_tree and all the work_file_t in the table.
 * The work_files are freed cleanly, and the data contained in the work_files
 * are freed.
 *
 * @param wt The work_tree to free.
 */
void free_work_tree(work_tree_t *wt);

#endif
