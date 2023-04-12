// MyGit Project
//
// convert_str_work_tree.c
// File description:
//    convert_str_work_tree.c

#include "libs/work_tree/convert_str_work_tree.h"
#include "libs/work_file/convert_str_work_file.h"
#include "libs/work_tree/insert_get_search_work_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size_work_tree_to_str(const work_tree_t *wf)
{
  size_t size_wt = 0;

  if (!wf || !wf->tab)
    return 0;
  size_wt = size_work_file_to_str(wf->tab) * wf->size;
  size_wt += wf->size;
  return size_wt;
}

static int browse_wt_and_convert(const work_tree_t *wt, char *str_wt, size_t str_wt_size)
{
  char *str_wf = NULL;

  if (!wt || !str_wt)
    return 0;
  for (size_t i = 0; i < wt->size; i++) {
    str_wf = convert_work_file_to_str(&wt->tab[i]);
    if (!str_wf)
      return 0;
    strlcat(str_wt, str_wf, str_wt_size);
    free(str_wf);
    if (i != wt->size - 1)
      strlcat(str_wt, "\n", str_wt_size);
  }
  return 1;
}

char *convert_work_tree_to_str(const work_tree_t *wt)
{
  size_t str_wt_size = 0;
  char *str_wt = NULL;

  if (!wt)
    return NULL;
  str_wt_size = size_work_tree_to_str(wt) + 1;
  str_wt = calloc(str_wt_size, sizeof(char));
  if (!str_wt)
    return NULL;
  if (!browse_wt_and_convert(wt, str_wt, str_wt_size)) {
    free(str_wt);
    return NULL;
  }
  return str_wt;
}

static int browse_string_and_append_wt(work_tree_t *wt, char **str_cpy)
{
  char *token = NULL;
  char *name = NULL;
  char *hash = NULL;
  mode_t mode = 0;

  token = strsep(str_cpy, "\n");
  while (token && strcmp(token, "") != 0) {
    if (!get_content_str_work_file(token, &name, &hash, &mode))
      return 0;
    if (append_work_tree(wt, name, hash, mode) == -1) {
      free(name);
      free(hash);
      return 0;
    }
    free(name);
    free(hash);
    token = strsep(str_cpy, "\n");
  }
  return 1;
}

work_tree_t *convert_str_to_work_tree(const char *str)
{
  work_tree_t *wt = NULL;
  char *str_cpy = NULL;
  char *str_cpy_pointer = NULL;

  if (!str)
    return NULL;
  str_cpy = strdup(str);
  str_cpy_pointer = str_cpy;
  if (!str_cpy)
    return NULL;
  wt = create_and_init_work_tree();
  if (!wt) {
    free(str_cpy);
    return NULL;
  }
  if (!browse_string_and_append_wt(wt, &str_cpy)) {
    free_work_tree(wt);
    wt = NULL;
  }
  free(str_cpy_pointer);
  return wt;
}