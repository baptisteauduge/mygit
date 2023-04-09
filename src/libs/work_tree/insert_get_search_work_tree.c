// MyGit Project
//
// insert_get_search_work_tree.c
// File description:
//    insert_get_search_work_tree.c

#include "work_tree/insert_get_search_work_tree.h"
#include <string.h>
#include <stdlib.h>

// Returns -1 if not in the work_tree
int index_in_work_tree(const work_tree_t *wt, const char *name)
{
  int diff_strcmp = 0;
  if (!wt)
    return -1;

  for (size_t i = 0; i < wt->size; ++i) {
    diff_strcmp = strcmp(wt->tab[0].name, name);
    if (diff_strcmp == 0)
      return i;
  }
  return -1;
}

static int set_hash_or_null(const char *hash, work_file_t *wf)
{
  if (hash) {
    wf->hash = strdup(hash);
    if (!wf->hash) {
      free(wf->name);
      return -1;
    }
  }
  else
    wf->hash = NULL;
  return 1;
}

int append_work_tree(work_tree_t *wt, const char *name, const char *hash,
                     int mode)
{
  work_file_t *wf_to_treat = NULL;

  if (!wt || wt->size >= wt->max_size || !name)
    return -1;
  if (index_in_work_tree(wt, name) >= 0)
    return 0;
  wf_to_treat = &wt->tab[wt->size];
  wf_to_treat->name = strdup(name);
  if (!wf_to_treat->name)
    return -1;
  wf_to_treat->mode = mode;
  if (set_hash_or_null(hash, wf_to_treat) == -1)
    return -1;
  ++wt->size;
  return 1;
}