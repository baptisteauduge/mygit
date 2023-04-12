// MyGit Project
//
// refs.c
// File description:
//    refs.c

#include "refs/refs.h"
#include "file/constants_file.h"
#include "file/get_path_absolute.h"
#include "file/list_files.h"
#include "file/read_write_file.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_or_update_ref(const char *ref_name, const char *hash)
{
  char *refs_path = NULL;
  FILE *refs_file = NULL;

  if (ref_name == NULL || hash == NULL)
    return;
  refs_path = get_path_absolute(MYGIT_DIR_REFS, ref_name);
  if (refs_path == NULL)
    return;
  refs_file = fopen(refs_path, WRITE_MODE);
  if (refs_file == NULL)
    return;
  fprintf(refs_file, "%s", hash);
  fclose(refs_file);
  free(refs_path);
}

int delete_ref(const char *ref_name)
{
  char *refs_path = NULL;
  int ret = 0;

  if (!ref_name)
    return 0;
  refs_path = get_path_absolute(MYGIT_DIR_REFS, ref_name);
  if (!refs_path)
    return 0;
  ret = remove(refs_path);
  free(refs_path);
  return ret == 0;
}

char *get_ref(const char *ref_name)
{
  char *refs_path = NULL;
  char *ref_content = NULL;

  if (!ref_name)
    return NULL;
  refs_path = get_path_absolute(MYGIT_DIR_REFS, ref_name);
  if (!refs_path)
    return NULL;
  ref_content = get_file_content(refs_path);
  free(refs_path);
  return ref_content;
}

static int concat_ref_name_hash(char **str_all_ref, size_t *size_str_all_ref,
                                char *ref_name)
{
  char *hash_ref = NULL;

  hash_ref = get_ref(ref_name);
  *size_str_all_ref += strlen(ref_name) + 1;
  if (!hash_ref)
    return 0;
  *size_str_all_ref += strlen(hash_ref) + 1;
  if (!*str_all_ref)
    *str_all_ref = malloc(*size_str_all_ref * sizeof(char));
  else
    *str_all_ref = realloc(*str_all_ref, *size_str_all_ref * sizeof(char));
  strncat(*str_all_ref, ref_name, *size_str_all_ref);
  strncat(*str_all_ref, "\t", *size_str_all_ref);
  strncat(*str_all_ref, hash_ref, *size_str_all_ref);
  strncat(*str_all_ref, "\n", *size_str_all_ref);
  free(hash_ref);
  return 1;
}

char *get_str_all_ref()
{
  list_t *list_ref_path = get_list_files_and_dir(MYGIT_DIR_REFS);
  cell_t *iter = NULL;
  char *str_name_ref = NULL;
  char *str_all_ref = NULL;
  size_t size_str_all_ref = 0;

  if (!list_ref_path)
    return NULL;
  iter = *list_ref_path;
  while (iter) {
    str_name_ref = iter->data;
    if (!concat_ref_name_hash(&str_all_ref, &size_str_all_ref, str_name_ref)) {
      free_list(list_ref_path);
      return str_all_ref;
    }
    iter = iter->next;
  }
  free_list(list_ref_path);
  return str_all_ref;
}
