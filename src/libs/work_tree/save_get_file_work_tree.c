// MyGit Project
//
// save_get_file_work_tree.c
// File description:
//    save_get_file_work_tree.c

#include "libs/work_tree/save_get_file_work_tree.h"
#include "libs/file/constants_file.h"
#include "libs/file/read_write_file.h"
#include "libs/work_tree/convert_str_work_tree.h"
#include <stdio.h>
#include <stdlib.h>

int work_tree_to_file(const work_tree_t *wt, const char *path)
{
  FILE *f = NULL;
  char *work_tree_str = NULL;

  if (!wt || !path)
    return -1;
  f = fopen(path, WRITE_MODE);
  if (!f)
    return -1;
  work_tree_str = convert_work_tree_to_str(wt);
  if (!work_tree_str) {
    fclose(f);
    return -1;
  }
  fprintf(f, "%s\n", work_tree_str);
  fclose(f);
  free(work_tree_str);
  return 0;
}

work_tree_t *file_to_work_tree(const char *path)
{
  char *file_content;
  work_tree_t *wt = NULL;

  if (!path)
    return NULL;
  file_content = get_file_content(path);
  if (!file_content)
    return NULL;
  wt = convert_str_to_work_tree(file_content);
  free(file_content);
  return wt;
}
