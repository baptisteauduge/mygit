// MyGit Project
//
// mygit_add.c
// File description:
//    mygit_add.c

#include "add/mygit_add.h"
#include "libs/file/list_files.h"
#include "libs/work_tree/convert_str_work_tree.h"
#include "libs/work_tree/insert_get_search_work_tree.h"
#include "libs/work_tree/save_get_file_work_tree.h"
#include "libs/work_tree/work_tree.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: List files in a directory
// TODO: Print only the filename
char *mygit_list_add_str(void)
{
  work_tree_t *work_tree = file_to_work_tree(MYGIT_PATH_ADD);
  char *str = NULL;

  if (!work_tree)
    return NULL;
  str = convert_work_tree_to_str(work_tree);
  free_work_tree(work_tree);
  return str;
}

static work_tree_t *get_add_work_tree_or_init(void)
{
  if (!does_file_exists(MYGIT_PATH_ADD))
    return create_and_init_work_tree();
  return file_to_work_tree(MYGIT_PATH_ADD);
}

int mygit_add(const char *file)
{
  work_tree_t *work_tree = NULL;
  int append_wt_ret = 0;

  if (!file || !does_file_exists(file))
    return 0;
  work_tree = get_add_work_tree_or_init();
  if (!work_tree)
    return 0;
  append_wt_ret = append_work_tree(work_tree, file, NULL, 0);
  if (append_wt_ret) {
    work_tree_to_file(work_tree, MYGIT_PATH_ADD);
    free_work_tree(work_tree);
    return 1;
  }
  if (append_wt_ret == 0)
    fprintf(stderr, "Error: file '%s' already added\n", file);
  else
    fprintf(stderr, "Error: could not add file '%s'\n", file);
  free_work_tree(work_tree);
  return 0;
}
