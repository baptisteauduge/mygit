// MyGit Project
//
// mygit_create_delation_commit.c
// File description:
//    mygit_create_delation_commit.c

#include "merge/mygit_create_delation_commit.h"
#include "add/mygit_add.h"
#include "branch/create_list_branches.h"
#include "branch/get_branch_commit_tree.h"
#include "checkout/mygit_checkout_branch.h"
#include "commit/mygit_commit.h"
#include "libs/commit/commit.h"
#include "libs/commit/get_work_tree_commit.h"
#include "libs/list/insert_get_search_list.h"
#include "libs/list/list.h"
#include "libs/work_tree/work_tree.h"
#include "utils/utils.h"
#include <stdio.h>

static void add_files_not_in_conflict(const list_t *conflicts,
                                      const work_tree_t *work_tree)
{
  if (!conflicts || !work_tree)
    return;

  for (size_t i = 0; i < work_tree->size; ++i) {
    if (!search_data_in_list(conflicts, work_tree->tab[i].name)) {
      if (!mygit_add(work_tree->tab[i].name))
        LOG_ERROR("Error: Could not add the file `%s`", work_tree->tab[i].name);
    }
  }
}

void mygit_create_deletion_commit(const char *branch, const list_t *conflicts,
                                  const char *message)
{
  commit_t *last_commit_branch = NULL;
  work_tree_t *last_work_tree_branch = NULL;
  char *default_branch = NULL;

  if (!branch || !conflicts)
    return;
  default_branch = get_current_branch();
  if (!default_branch)
    return;
  if (!mygit_checkout_branch(branch))
    return;
  last_commit_branch = get_last_commit_from_branch(branch);
  last_work_tree_branch = get_work_tree_from_commit(last_commit_branch);
  remove(MYGIT_PATH_ADD);
  add_files_not_in_conflict(conflicts, last_work_tree_branch);
  if (!message)
    mygit_commit(branch, "mygit: deletion commit");
  mygit_commit(branch, message);
}
