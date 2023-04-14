// MyGit Project
//
// convert_str_work_file.c
// File description:
//    convert_str_work_file.c

#include "libs/work_file/convert_str_work_file.h"
#include "libs/work_file/work_file.h"
#include "utils/get_content_or_dash_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size_work_file_to_str(const work_file_t *wf)
{
  size_t size_wf = 2 * TAB_SIZE;
  const char *name = NULL;
  const char *hash = NULL;

  if (!wf)
    return 0;
  name = get_content_or_dash_str(wf->name);
  hash = get_content_or_dash_str(wf->hash);
  size_wf += strlen(name);
  size_wf += strlen(hash);
  size_wf += MODE_MAX_SIZE_STR;
  return size_wf;
}

char *convert_work_file_to_str(const work_file_t *wf)
{
  size_t size_wf_str = size_work_file_to_str(wf);
  char *wf_str = NULL;
  const char *name = NULL;
  const char *hash = NULL;

  if (!wf)
    return NULL;
  wf_str = calloc(sizeof(char), size_wf_str);
  if (!wf_str)
    return NULL;
  name = get_content_or_dash_str(wf->name);
  hash = get_content_or_dash_str(wf->hash);
  if (snprintf(wf_str, size_wf_str, "%s\t%s\t%ho", name, hash, wf->mode) < 0) {
    free(wf_str);
    return NULL;
  }
  return wf_str;
}

static void set_to_null_if_dash(char **str)
{
  if (strcmp(*str, "-") == 0) {
    free(*str);
    *str = NULL;
  }
}

// Due to a non support in MacOS of %ms, in sscanf
// we use %s and we allocate the memory
int get_content_str_work_file(const char *str, char **name, char **hash,
                              mode_t *mode)
{
  if (!name || !hash || !mode || !str)
    return 0;
  *name = malloc(BUFFER_SIZE * sizeof(char));
  if (!*name)
    return 0;
  *hash = malloc(BUFFER_SIZE * sizeof(char));
  if (!*hash) {
    free(*name);
    return 0;
  }
  if (sscanf(str, "%s\t%s\t%ho", *name, *hash, mode) < 2)
    return 0;
  set_to_null_if_dash(name);
  set_to_null_if_dash(hash);
  return 1;
}

work_file_t *convert_str_to_work_file(const char *str)
{
  work_file_t *wf = NULL;
  char *name = NULL;
  char *hash = NULL;
  mode_t mode = 0;

  if (!str)
    return NULL;
  if (!get_content_str_work_file(str, &name, &hash, &mode))
    return NULL;
  wf = create_work_file(name, hash, mode);
  free(name);
  free(hash);
  return wf;
}
