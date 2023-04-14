// MyGit Project
//
// insert_get_search_work_tree.h
// File description:
//    insert_get_search_work_tree.h

#ifndef INSERT_GET_SEARCH_WORK_TREE_H
#define INSERT_GET_SEARCH_WORK_TREE_H

#include "libs/work_tree/work_tree.h"
#include <sys/stat.h>

/**
 * @brief Append a work_tree with given in parameter. The work_tree must be
 * created with the @ref create_and_init_work_tree function. Please provide a
 * NULL hash if the file is not tracked.
 *
 * @param wt The work_tree to append.
 * @param name The name of the file.
 * @param hash Optional, the hash of the file. (NULL if the file is not tracked)
 * @param mode The mode of the file. (See @ref stat, provide 0 if the file is
 * not tracked)
 * @return int 1 if the work_tree was appended, 0 if the work_file was already
 * in the work_tree, -1 if an error occurred.
 */
int append_work_tree(work_tree_t *wt, const char *name, const char *hash,
                     mode_t mode);

/**
 * @brief Returns the index of the work_file with the name "name" in the
 * work_tree. Returns -1 if the work_file is not in the work_tree.
 *
 * @param wt The work_tree to search in.
 * @param name The name of the work_file to search.
 * @return int The index of the work_file or -1 if the work_file is not in th
 * work_tree.
 */
int index_in_work_tree(const work_tree_t *wt, const char *name);

#endif