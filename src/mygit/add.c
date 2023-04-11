// MyGit Project
//
// add.c
// File description:
//    add.c
#include "mygit/add.h"
#include "utils/constants.h"
#include "work_tree/insert_get_search_work_tree.h"
#include "work_tree/save_get_file_work_tree.h"
#include "work_tree/work_tree.h"
#include "file/list_files.h"
#include <stdio.h>
#include <stdlib.h>

static work_tree_t *get_add_work_tree(void)
{
  if (!does_file_exists(MYGIT_PATH_ADD))
    return create_and_init_work_tree();
  return file_to_work_tree(MYGIT_PATH_ADD);
}

void mygit_add(const char *file)
{
  work_tree_t *work_tree = NULL;
  int append_wt_ret = 0;

  if (!file || !does_file_exists(file))
    return;
  work_tree = get_add_work_tree();
  if (!work_tree)
    return;

  append_wt_ret = append_work_tree(work_tree, file, NULL, 0);
  if (append_wt_ret)
    work_tree_to_file(work_tree, MYGIT_PATH_ADD);
  else if (append_wt_ret == 0)
    fprintf(stderr, "Error: file %s already added", file);
  else
    fprintf(stderr, "Error: could not add file %s", file);
  free_work_tree(work_tree);
}
