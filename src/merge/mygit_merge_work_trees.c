// MyGit Project
//
// mygit_merge_work_trees.c
// File description:
//    mygit_merge_work_trees.c

#include "merge/mygit_merge_work_trees.h"
#include "libs/list/insert_get_search_list.h"
#include "libs/list/list.h"
#include "libs/work_tree/insert_get_search_work_tree.h"
#include "libs/work_tree/work_tree.h"
#include <string.h>

static int is_in_conflict(work_tree_t *wt, work_file_t *wf)
{
  if (!wt || !wf)
    return 0;
  for (size_t i = 0; i < wt->size; ++i) {
    if (strcmp(wt->tab[i].name, wf->name) == 0 &&
        (strcmp(wt->tab[i].hash, wf->hash) != 0 ||
         wt->tab[i].mode != wf->mode)) {
      return 1;
    }
  }
  return 0;
}

// Note that append work_tree is safe about duplicates
// if a file is in both work trees, it will be appended only once
// in the work tree without conflicts
static void browse_and_append_wt_or_conflicts(work_tree_t *wt1,
                                              work_tree_t *wt2,
                                              list_t **conflicts,
                                              work_tree_t *wt_without_conflicts)
{
  work_file_t *current_wf = NULL;

  if (!wt1 || !wt2 || !conflicts || !wt_without_conflicts)
    return;
  for (size_t i = 0; i < wt1->size; ++i) {
    current_wf = wt1->tab + i;
    if (is_in_conflict(wt2, current_wf) &&
        !search_data_in_list(*conflicts, current_wf->name)) {
      create_and_insert_cell_in_list(*conflicts, current_wf->name);
    }
    else {
      append_work_tree(wt_without_conflicts, current_wf->name, current_wf->hash,
                       current_wf->mode);
    }
  }
}

work_tree_t *mygit_merge_work_trees(work_tree_t *wt1, work_tree_t *wt2,
                                    list_t **conflicts)
{
  work_tree_t *wt_without_conflicts = NULL;

  if (!wt1 || !wt2 || !conflicts)
    return NULL;
  wt_without_conflicts = create_and_init_work_tree();
  if (!wt_without_conflicts)
    return NULL;
  browse_and_append_wt_or_conflicts(wt1, wt2, conflicts, wt_without_conflicts);
  browse_and_append_wt_or_conflicts(wt2, wt1, conflicts, wt_without_conflicts);
  return wt_without_conflicts;
}
