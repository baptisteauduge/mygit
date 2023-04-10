// MyGit Project
//
// key_val.h
// File description:
//    key_val.h

#ifndef KEY_VAL_H
#define KEY_VAL_H

typedef struct key_val_s {
  char *key;
  char *value;
} key_val_t;

key_val_t *create_key_val(const char *key, const char *value);
void free_key_val(key_val_t *key_val);

#endif
