// MyGit Project
//
// restore_work_tree.c
// File description:
//    restore_work_tree.c

#include "work_tree/restore_work_tree.h"
#include "file/copy_file.h"
#include "file/create_blob.h"
#include "file/get_path_absolute.h"
#include "file/list_files.h"
#include "file/rights_file.h"
#include "work_tree/save_get_file_work_tree.h"
#include <stdlib.h>
#include <string.h>

static int is_save_file(const char *path)
{
  size_t len = 0;

  if (!path)
    return 0;
  if (!is_file(path))
    return 0;
  len = strlen(path);
  if (path[len - 2] == '.' && path[len - 1] == 't')
    return 0;
  return 1;
}

static void set_content_file_mode_and_hash(work_file_t *wf,
                                           const char *path_blob,
                                           const char *path)
{
  char *path_absolue_file = NULL;
  if (!wf || !path_blob || !path)
    return;
  path_absolue_file = get_path_absolute(path, wf->name);
  copy_file(path_absolue_file, path_blob);
  set_chmod(path_absolue_file, wf->mode);
}

static void load_work_tree_and_iterate(const char *path_absolute_blob,
                                       const char *path)
{
  work_tree_t *wt_new = NULL;

  wt_new = file_to_work_tree(path_absolute_blob);
  if (!wt_new)
    return;
  restore_work_tree(wt_new, path);
  free_work_tree(wt_new);
}

void restore_work_tree(work_tree_t *wt, const char *path)
{
  work_file_t *wf = NULL;
  char *path_absolute_blob = NULL;
  char *path_blob = NULL;

  if (!wt || !path)
    return;
  for (size_t i = 0; i < wt->size; ++i) {
    wf = &wt->tab[i];
    path_blob = get_path_from_hash(wf->hash);
    if (!path_blob)
      return;
    path_absolute_blob = get_path_absolute(path, path_blob);
    free(path_blob);
    if (!path_absolute_blob)
      return;
    if (is_save_file(path_absolute_blob))
      set_content_file_mode_and_hash(wf, path_absolute_blob, path);
    else
      load_work_tree_and_iterate(path_absolute_blob, path);
  }
}