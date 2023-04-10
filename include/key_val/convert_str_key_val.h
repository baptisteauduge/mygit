// MyGit Project
//
// convert_str_key_val.h
// File description:
//    convert_str_key_val.h

#ifndef CONVERT_STR_KEY_VAL_H
#define CONVERT_STR_KEY_VAL_H

#include "key_val/key_val.h"

char *convert_key_val_to_str(key_val_t *key_val);
key_val_t *convert_str_to_key_val(const char *str);

#endif
