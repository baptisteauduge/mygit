// MyGit Project
//
// work_tree.c
// File description:
//    work_tree.c

#include "libs/work_tree/work_tree.h"
#include <stdlib.h>

work_tree_t *create_and_init_work_tree()
{
  work_tree_t *new_wt = NULL;

  new_wt = malloc(sizeof(work_tree_t));
  if (!new_wt)
    return NULL;
  new_wt->max_size = WORK_TREE_MAX_SIZE;
  new_wt->size = 0;
  new_wt->tab = malloc(sizeof(work_file_t) * new_wt->max_size);
  if (!new_wt->tab) {
    free(new_wt);
    return NULL;
  }
  return new_wt;
}

void free_work_tree(work_tree_t *wf)
{
  if (!wf)
    return;
  for (size_t i = 0; i < wf->size; i++) {
    free(wf->tab[i].hash);
    free(wf->tab[i].name);
  }
  free(wf->tab);
  free(wf);
}
