// MyGit Project
//
// mygit_merge.c
// File description:
//    mygit_merge.c

#include "merge/mygit_merge.h"
#include "branch/create_list_branches.h"
#include "libs/list/insert_get_search_list.h"
#include "libs/list/list.h"
#include "merge/mygit_create_delation_commit.h"
#include "merge/mygit_merge_or_get_conflicts.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

static void mygit_keep_other_branch_changes(const list_t *conflicts,
                                            const char *message)
{
  char *current_branch = NULL;

  if (!conflicts)
    return;
  current_branch = get_current_branch();
  if (!current_branch)
    return;
  mygit_create_deletion_commit(current_branch, conflicts, message);
  free(current_branch);
}

static int mygit_get_yes_no_answer(void)
{
  char answer = 0;

  while (answer != 'y' && answer != 'n') {
    scanf("%c\n", &answer);
    if (answer != 'y' && answer != 'n')
      LOG_ERROR("Invalid answer. Please choose between 'y' and 'n' :\n");
  }
  return answer == 'y';
}

static void mygit_choose_for_each_file(const list_t *conflicts,
                                       const char *message, const char *branch)
{
  list_t *conflicts_delete_current_br = NULL;
  list_t *conflicts_delete_other_br = NULL;
  cell_t *current_cell = NULL;

  if (!conflicts || !branch)
    return;
  conflicts_delete_current_br = create_init_list();
  conflicts_delete_other_br = create_init_list();
  if (!conflicts_delete_current_br || !conflicts_delete_other_br)
    return;
  current_cell = *conflicts;
  while (current_cell) {
    LOG_INFO("Do you want to keep the current branch changes for '%s' ? (y/n)",
             current_cell->data);
    if (mygit_get_yes_no_answer()) {
      create_and_insert_cell_in_list(conflicts_delete_other_br,
                                     current_cell->data);
    }
    else {
      create_and_insert_cell_in_list(conflicts_delete_current_br,
                                     current_cell->data);
    }
    current_cell = current_cell->next;
  }
  mygit_create_deletion_commit(branch, conflicts_delete_other_br, message);
  mygit_keep_other_branch_changes(conflicts_delete_current_br, message);
  free_list(conflicts_delete_current_br);
  free_list(conflicts_delete_other_br);
}

static void mygit_handle_answer(const char *branch, const list_t *conflicts,
                                const char *message)
{
  int answer = 0;

  while (answer < 1 || answer > 3) {
    scanf("%d\n", &answer);
    if (answer < 1 || answer > 3)
      LOG_ERROR("Invalid answer. Please choose between 1 and 3.\nYour choice:");
  }
  if (answer == 1) {
    mygit_create_deletion_commit(branch, conflicts, message);
  }
  else if (answer == 2) {
    mygit_keep_other_branch_changes(conflicts, message);
  }
  else {
    mygit_choose_for_each_file(conflicts, message, branch);
  }
  mygit_merge(branch, message);
}

static void mygit_handle_conflicts(const char *branch, const list_t *conflicts,
                                   const char *message)
{
  if (!conflicts)
    return;

  LOG_INFO(
      "What do you want to do ?\n1) Keep the current branch changes\n2) "
      "Keep the '%s' branch changes\n3) Choose for each file\nYour choice:",
      branch);
  mygit_handle_answer(branch, conflicts, message);
}

void mygit_merge(const char *branch, const char *message)
{
  list_t *conflicts = NULL;

  if (!branch)
    return;
  conflicts = mygit_merge_or_get_conflicts(branch, message);
  if (conflicts) {
    LOG_ERROR("There is conflicts between the branches that you are trying to "
              "merge.\n");
    mygit_handle_conflicts(branch, conflicts, message);
    free_list(conflicts);
  }
  LOG_INFO("Merge done.\n");
}