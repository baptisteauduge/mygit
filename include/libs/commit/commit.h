// MyGit Project
//
// commit.h
// File description:
//    commit.h

#ifndef COMMIT_H
#define COMMIT_H

#define COMMIT_KEY_VAL_MAX_SIZE 10
#define COMMIT_KEY_HASH "tree"
#define COMMIT_KEY_PARENT "predecessor"
#define COMMIT_KEY_MESSAGE "message"
#define COMMIT_KEY_MERGED_PARENT "merged_predecessor"

#include "libs/key_val/key_val.h"
#include <stddef.h>

typedef struct hash_table_s {
  key_val_t **key_val;
  size_t max_size;
  size_t size;
} hash_table_t;

/**
 * @brief A commit is a hash table. The key is the name of the key, i.e. the
 * hash of the work tree is associated with the key "COMMIT_KEY_HASH" (that is
 * defined in commit.h).
 *
 * @param key_val The array of key_val_t pointers
 * @param max_size The maximum size of the array (i.e. the number of key_val_t
 * pointers that can be stored in the array)
 * @param size The current size of the array (i.e. the number of key_val_t
 * pointers that are currently stored in the array, and that are not NULL)
 */
typedef hash_table_t commit_t;

/**
 * @brief Create a and init empty commit object (i.e. a commit with no key_val_t
 * pointers set to other than NULL)
 *
 * @return commit_t* The commit created, NULL if an error occurred
 */
commit_t *create_and_init_empty_commit(void);

/**
 * @brief Create a commit object with the hash provided. The commit object will
 * contain a key_val_t pointer with the key "COMMIT_KEY_HASH" (that is defined
 * in commit.h) and the value provided as hash.
 *
 * @param hash The hash of the the Work Tree related to the commit
 * @return commit_t* The commit created, NULL if an error occurred
 */
commit_t *create_commit_with_tree_key_val(const char *hash);

/**
 * @brief Free the commit provided. The key_val_t pointers contained in the
 * commit are also freed (using @ref free_key_val). (So, the value associated
 * as values are also freed)
 *
 * @param commit The commit to free
 */
void free_commit(commit_t *commit);

#endif