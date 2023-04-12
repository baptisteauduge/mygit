// MyGit Project
//
// restore_work_tree.c
// File description:
//    restore_work_tree.c

#include "libs/work_tree/restore_work_tree.h"
#include "libs/file/copy_file.h"
#include "libs/file/create_blob.h"
#include "libs/file/get_path_absolute.h"
#include "libs/file/list_files.h"
#include "libs/file/rights_file.h"
#include "libs/work_tree/save_get_file_work_tree.h"
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
  free(path_absolue_file);
}

static void create_dir_if_doesnt_exist(const char *path, const char *name,
                                       mode_t mode)
{
  char *path_absolute_dir = NULL;

  if (!path || !name)
    return;
  path_absolute_dir = get_path_absolute(path, name);
  if (!does_file_exists(path_absolute_dir))
    mkdir(path_absolute_dir, mode);
  free(path_absolute_dir);
}

static void load_work_tree_and_iterate(const work_file_t *wf,
                                       const char *path_absolute_blob,
                                       const char *path)
{
  work_tree_t *wt_new = NULL;

  if (!wf || !path_absolute_blob || !path)
    return;
  wt_new = file_to_work_tree(path_absolute_blob);
  if (!wt_new)
    return;
  create_dir_if_doesnt_exist(path, wf->name, wf->mode);
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
      load_work_tree_and_iterate(wf, path_absolute_blob, path);
    free(path_absolute_blob);
  }
}