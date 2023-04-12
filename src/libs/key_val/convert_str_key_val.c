// MyGit Project
//
// convert_str_key_val.c
// File description:
//    convert_str_key_val.c

#include "key_val/convert_str_key_val.h"
#include "utils/get_content_or_dash_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert_key_val_to_str(key_val_t *key_val)
{
  char *str_key_val = NULL;
  size_t size_key_val_str = 0;
  const char *key = NULL;
  const char *value = NULL;
  int nb_set = 0;

  if (!key_val)
    return NULL;
  key = get_content_or_dash_str(key_val->key);
  value = get_content_or_dash_str(key_val->value);
  size_key_val_str = strlen(key) + strlen(value) + 3;
  str_key_val = calloc(sizeof(char), size_key_val_str);
  if (!str_key_val)
    return NULL;
  nb_set = snprintf(str_key_val, size_key_val_str, "%s:%s", key, value);
  if (nb_set < 0) {
    free(str_key_val);
    return NULL;
  }
  return str_key_val;
}

static void set_to_null_if_dash(char **str)
{
  if (strcmp(*str, "-") == 0) {
    free(*str);
    *str = NULL;
  }
}

key_val_t *convert_str_to_key_val(const char *str)
{
  key_val_t *key_val = NULL;
  char *key = NULL;
  char *value = NULL;
  char *str_cpy = NULL;

  if (!str)
    return NULL;
  str_cpy = strdup(str);
  if (!str_cpy)
    return NULL;
  key = strsep(&str_cpy, ":");
  set_to_null_if_dash(&key);
  value = str_cpy;
  set_to_null_if_dash(&value);
  key_val = create_key_val(key, value);
  free(key);
  free(str_cpy);
  return key_val;
}
