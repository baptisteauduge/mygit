// MyGit Project
//
// key_val.c
// File description:
//    key_val.c

#include "key_val/key_val.h"
#include <stdlib.h>
#include <string.h>

key_val_t *create_key_val(const char *key, const char *value)
{
  key_val_t *key_val = NULL;

  if (!key || !value)
    return NULL;
  key_val = malloc(sizeof(key_val_t));
  if (!key_val)
    return NULL;
  key_val->key = strdup(key);
  if (!key_val->key) {
    free(key_val);
    return NULL;
  }
  key_val->value = strdup(value);
  if (!key_val->value) {
    free(key_val->key);
    free(key_val);
    return NULL;
  }
  return key_val;
}

void free_key_val(key_val_t *key_val)
{
  if (!key_val)
    return;
  free(key_val->key);
  free(key_val->value);
  free(key_val);
}
