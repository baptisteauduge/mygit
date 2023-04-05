// Sorbonne University, 2022 - 2023
// MyGit Project
//
// workfile.c
// File description:
//      This file contains the implementation of the workfile structure. And the
//      basics functions used to manipulate it.

#include "workfile.h"
#include <stdlib.h>
#include <string.h>

WorkFile *create_work_file(const char *name) {
  WorkFile *new = malloc(sizeof(WorkFile));
  if (!new)
    return NULL;
  new->name = strdup(name);
  if (!new->name) {
    free(new);
    return NULL;
  }
  new->hash = NULL;
  new->mode = 0;
  return new;
}

void free_work_file(WorkFile *wf) {
  if (!wf)
    return;
  free(wf->name);
  if (wf->hash)
    free(wf->hash);
  free(wf);
}