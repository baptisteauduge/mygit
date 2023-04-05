// Sorbonne University, 2022 - 2023
// MyGit Project
//
// worktree.c
// File description:
//     This file contains the implementation of the worktree.h header.

#include "worktree.h"
#include "filesystem.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

WorkTree *create_init_worktree() {
  WorkTree *res = malloc(sizeof(WorkTree));
  if (!res)
    return NULL;
  res->tab = malloc(sizeof(WorkFile) * WORKTREE_INIT_SIZE);
  if (!res->tab) {
    free(res);
    return NULL;
  }
  res->n = 0;
  res->size = (size_t)WORKTREE_INIT_SIZE;
  return res;
}

void free_worktree(WorkTree *wt) {
  if (!wt)
    return;
  if (wt->tab) {
    for (int i = 0; i < wt->size; ++i) {
      if (wt->tab[i].name)
        free(wt->tab[i].name);
      if (wt->tab[i].hash)
        free(wt->tab[i].hash);
    }
    free(wt->tab);
  }
  free(wt);
}

int is_in_worktree(const WorkTree *wt, const char *name) {
  if (!wt || !name)
    return -1;
  for (int i = 0; i < wt->n; ++i) {
    if (!strcmp(wt->tab[i].name, name))
      return i;
  }
  return -1;
}

int append_work_tree_with_values(WorkTree *wt, const char *name, const char *hash, int mode) {
  if (!wt || wt->size <= wt->n || !name)
    return -1;
  if (is_in_worktree(wt, name) >= 0)
    return 0;
  wt->tab[wt->n].name = strdup(name);
  if (!wt->tab[wt->n].name)
    return -1;
  wt->tab[wt->n].mode = mode;
  if (hash) {
    wt->tab[wt->n].hash = strdup(hash);
    if (!wt->tab[wt->n].hash)
      return -1;
  } else
    wt->tab[wt->n].hash = NULL;
  ++wt->n;
  return 1;
}
