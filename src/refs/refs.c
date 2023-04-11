// MyGit Project
//
// refs.c
// File description:
//    refs.c

#include "refs/refs.h"
#include "file/constants_file.h"
#include "utils/constants.h"
#include "file/read_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_or_update_ref(const char *ref_name, const char *hash)
{
  char *refs_path = NULL;
  size_t refs_path_size = 0;
  FILE *refs_file = NULL;

  if (ref_name == NULL || hash == NULL)
    return;
  refs_path_size = strlen(MYGIT_DIR_REFS) + strlen(ref_name) + 1;
  refs_path = calloc(refs_path_size, sizeof(char));
  if (refs_path == NULL)
    return;
  strncpy(refs_path, MYGIT_DIR_REFS, refs_path_size);
  strncat(refs_path, ref_name, refs_path_size);
  refs_file = fopen(refs_path, WRITE_MODE);
  if (refs_file == NULL)
    return;
  fprintf(refs_file, "%s", hash);
  fclose(refs_file);
  free(refs_path);
}

void delete_ref(const char *ref_name)
{
  char *refs_path = NULL;
  size_t refs_path_size = 0;

  if (!ref_name)
    return;
  refs_path_size = strlen(MYGIT_DIR_REFS) + strlen(ref_name) + 1;
  refs_path = calloc(refs_path_size, sizeof(char));
  if (!refs_path)
    return;
  strncpy(refs_path, MYGIT_DIR_REFS, refs_path_size);
  strncat(refs_path, ref_name, refs_path_size);
  remove(refs_path);
  free(refs_path);
}

char *get_ref(const char *ref_name)
{
  char *refs_path = NULL;
  size_t refs_path_size = 0;
  char *ref_content = NULL;

  if (!ref_name)
    return NULL;
  refs_path_size = strlen(MYGIT_DIR_REFS) + strlen(ref_name) + 1;
  refs_path = calloc(refs_path_size, sizeof(char));
  if (!refs_path)
    return NULL;
  strncpy(refs_path, MYGIT_DIR_REFS, refs_path_size);
  strncat(refs_path, ref_name, refs_path_size);
  ref_content = get_file_content(refs_path);
  free(refs_path);
  return ref_content;
}
