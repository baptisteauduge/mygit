// MyGit Project
//
// create_blob_of_commit.h
// File description:
//    create_blob_of_commit.h

#ifndef CREATE_BLOB_OF_COMMIT_H
#define CREATE_BLOB_OF_COMMIT_H

#include "libs/commit/commit.h"

/**
 * @brief Create a blob of commit object. The function is based on the
 * @ref convert_commit_to_str function and the @ref
 * create_blob_file_and_get_hash function.
 *
 * @param commit The commit to convert to a blob.
 * @return char* The hash of the blob. NULL if an error occurred.
 */
char *create_blob_of_commit(commit_t *commit);

#endif