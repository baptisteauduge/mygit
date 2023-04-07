// MyGit Project
//
// convert_str_work_file.c
// File description:
//    convert_str_work_file.c

#include "work_file/convert_str_work_file.h"
#include "work_file/work_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *get_content_or_empty_str(const char *str)
{
  if (!str)
    return "";
  return str;
}

size_t size_work_file_to_str(const work_file_t *wf)
{
  size_t size_wf = 2 * TAB_SIZE;
  const char *name = NULL;
  const char *hash = NULL;

  if (!wf)
    return 0;
  name = get_content_or_empty_str(wf->name);
  hash = get_content_or_empty_str(wf->hash);
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
  name = get_content_or_empty_str(wf->name);
  hash = get_content_or_empty_str(wf->hash);
  if (snprintf(wf_str, size_wf_str, "%s\t%s\t%d", name, hash, wf->mode) < 0) {
    free(wf_str);
    return NULL;
  }
  return wf_str;
}

static void set_to_null_if_empty(char **str)
{
  if (strcmp(*str, "") == 0) {
    free(*str);
    *str = NULL;
  }
}

work_file_t *convert_str_to_work_file(const char *str)
{
  work_file_t *wf = NULL;
  char *name = NULL;
  char *hash = NULL;
  int mode = 0;

  if (!str)
    return NULL;
  if (sscanf(str, "%ms\t%ms\t%d", &name, &hash, &mode) != 3)
    return NULL;
  set_to_null_if_empty(&name);
  set_to_null_if_empty(&hash);
  wf = create_work_file(name, hash, mode);
  free(name);
  free(hash);
  return wf;
}
