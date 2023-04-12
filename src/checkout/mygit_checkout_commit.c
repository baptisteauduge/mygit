// MyGit Project
//
// mygit_checkout_commit.c
// File description:
//    mygit_checkout_commit.c

#include "checkout/mygit_checkout_commit.h"
#include "commit/mygit_commit.h"
#include "libs/commit/restore_commit.h"
#include "libs/file/read_write_file.h"
#include "libs/list/filter_list_prefix.h"
#include "utils/utils.h"
#include <stdio.h>

static void print_error_several_commits_found(list_t *filtered_list)
{
  cell_t *iter = NULL;

  LOG_ERROR("Error: several commits found\n");
  iter = *filtered_list;
  while (iter) {
    fprintf(stderr, "%s\n", iter->data);
    iter = iter->next;
  }
}

static void checkout_commit_by_hash(char *hash)
{
  write_file_content(MYGIT_FILE_REF_HEAD, hash);
  restore_commit_from_hash(hash);
  printf("HEAD is now at `%s`\n", hash);
}

void mygit_checkout_commit(char *pattern)
{
  list_t *list_all_commits = NULL;
  list_t *filtered_list = NULL;

  if (!pattern)
    return;
  list_all_commits = get_list_all_commits();
  if (!list_all_commits)
    return;
  filtered_list = filter_list_prefix(list_all_commits, pattern);
  if (list_all_commits || !*filtered_list) {
    LOG_ERROR("Error: no commit found\n");
    free_list(filtered_list);
    free_list(list_all_commits);
    return;
  }
  if ((*filtered_list)->next) {
    print_error_several_commits_found(filtered_list);
    free_list(filtered_list);
    free_list(list_all_commits);
    return;
  }
  checkout_commit_by_hash((*filtered_list)->data);
  free_list(filtered_list);
  free_list(list_all_commits);
}
