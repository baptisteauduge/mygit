// MyGit Project
//
// convert_str_key_val.h
// File description:
//    convert_str_key_val.h

#ifndef CONVERT_STR_KEY_VAL_H
#define CONVERT_STR_KEY_VAL_H

#include "libs/key_val/key_val.h"

/**
 * @brief Convert a key_val_t to a string, the string is allocated
 * and must be freed. The format is "key:value"
 *
 * @param key_val The key_val_t to convert
 * @return char* The string converted
 */
char *convert_key_val_to_str(key_val_t *key_val);

/**
 * @brief Convert a string to a key_val_t, the key_val_t is allocated
 * and must be freed. The required format is "key:value"
 *
 * @param str The string to convert
 * @return key_val_t* The key_val_t converted or NULL if any error occurred
 */
key_val_t *convert_str_to_key_val(const char *str);

#endif
