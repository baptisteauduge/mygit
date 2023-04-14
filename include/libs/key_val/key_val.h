// MyGit Project
//
// key_val.h
// File description:
//    key_val.h

#ifndef KEY_VAL_H
#define KEY_VAL_H

/**
 * @brief A pair key/value
 * @param key The key
 * @param value The value associated to the key
 */
typedef struct key_val_s {
  char *key;
  char *value;
} key_val_t;

/**
 * @brief Create a key value pair (key and value will be copied)
 *
 * @param key The key of the pair
 * @param value The value of the pair
 * @return key_val_t* The key value pair created or NULL if any error occurred
 */
key_val_t *create_key_val(const char *key, const char *value);

/**
 * @brief Free the key value pair. The key and value will be freed.
 *
 * @param key_val The key value pair to free
 */
void free_key_val(key_val_t *key_val);

#endif
