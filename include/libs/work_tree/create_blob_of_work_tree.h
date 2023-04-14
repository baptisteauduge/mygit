// MyGit Project
//
// create_blob_of_work_tree.h
// File description:
//    create_blob_of_work_tree.h

#ifndef CREATE_BLOB_OF_WORK_TREE_H
#define CREATE_BLOB_OF_WORK_TREE_H

#include "libs/work_tree/work_tree.h"

/**
 * @brief Create a blob of work tree. The blob is stored at the location given
 * by the @ref BLOB_PATH constant and the name of the blob is the hash of the
 * work tree. The blob is created with the @ref convert_work_tree_to_str
 * function.
 *
 * @param wt The work tree to create the blob from.
 * @return char* The hash of the blob or NULL if an error occurred.
 */
char *create_blob_of_work_tree(work_tree_t *wt);

#endif
