// MyGit Project
//
// insert_key_val_in_commit.h
// File description:
//    insert_key_val_in_commit.h

#ifndef INSERT_KEY_VAL_IN_COMMIT_H
#define INSERT_KEY_VAL_IN_COMMIT_H

#include "libs/commit/commit.h"

/**
 * @brief Insert a key value pair in the commit object. The key and value are
 * copied in the commit object. The key and the value are copied in the commit
 * object. We are using a hash table implementation with linear probing to
 * resolve collisions.
 *
 * @param commit The commit to insert the key value pair in.
 * @param key The key to insert.
 * @param value The value to insert.
 */
void insert_key_val_in_commit(commit_t *commit, const char *key,
                              const char *value);

/**
 * @brief Get the value from key in commit object. The function is based on the
 * hash table implementation with linear probing to resolve collisions.
 *
 * @param commit The commit to get the value from.
 * @param key The key to get the value from.
 * @return char* The value. NULL if an error occurred.
 */
char *get_value_from_key_in_commit(commit_t *commit, char *key);

#endif
