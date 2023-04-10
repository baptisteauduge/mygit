// MyGit Project
//
// save_content_and_work_tree.c
// File description
//    save_content_and_work_tree.c

#include "work_tree/save_content_and_work_tree.h"
#include "file/create_blob.h"
#include "file/get_path_absolute.h"
#include "file/list_files.h"
#include "file/rights_file.h"
#include "list/add_prefix_all_list.h"
#include "work_tree/create_blob_of_work_tree.h"
#include "work_tree/insert_get_search_work_tree.h"
#include <stdlib.h>
#include <string.h>

static void save_content_file_get_mode_and_hash(work_file_t *wf,
                                                const char *path_absolute)
{
  if (!wf || !path_absolute)
    return;
  wf->mode = get_chmod(path_absolute);
  wf->hash = create_blob_file_and_get_hash(path_absolute, NULL);
}

static void fill_work_tree(work_tree_t *wt, list_t *list, const char *path)
{
  cell_t *tmp = NULL;
  char *path_relative = NULL;

  if (!wt || !list)
    return;
  tmp = *list;
  for (size_t i = 0; i < wt->max_size && tmp; ++i) {
    path_relative = get_path_absolute(path, tmp->data);
    if (!path_relative)
      return;
    append_work_tree(wt, tmp->data, NULL, 0);
    tmp = tmp->next;
    free(path_relative);
  }
}

static void create_work_tree_and_iterate(work_tree_t *wt, work_file_t *wf,
                                         const char *path,
                                         const char *path_absolute, int index)
{
  work_tree_t *wt2 = NULL;

  if (!wt || !wf || !path_absolute)
    return;
  wt2 = create_and_init_work_tree();
  if (!wt2)
    return;
  list_t *list = get_list_files_and_dir(path_absolute);
  if (!list)
    return;
  add_prefix_all_list(list, "/");
  add_prefix_all_list(list, wf->name);
  fill_work_tree(wt2, list, path_absolute);
  wt->tab[index].mode = get_chmod(path_absolute);
  wt->tab[index].hash = save_content_and_work_tree(wt2, path);
  free_work_tree(wt2);
  free_list(list);
}

char *save_content_and_work_tree(work_tree_t *wt, const char *path)
{
  work_file_t *wf = NULL;
  char *path_absolute = NULL;

  if (!wt || !path)
    return NULL;
  for (size_t i = 0; i < wt->size; ++i) {
    wf = &wt->tab[i];
    path_absolute = get_path_absolute(path, wf->name);
    if (!path_absolute)
      return NULL;
    if (is_file(path_absolute))
      save_content_file_get_mode_and_hash(wf, path_absolute);
    else
      create_work_tree_and_iterate(wt, wf, path, path_absolute, i);
    free(path_absolute);
  }
  return create_blob_of_work_tree(wt);
}
