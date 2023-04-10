// MyGit Project
//
// work_file.c
// File description:
//    work_file.c

#include "work_file/work_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

work_file_t *create_work_file(const char *name, const char *hash, mode_t mode) {
  work_file_t *new_wf = NULL;
  
  if (!name)
    return NULL;
  new_wf = malloc(sizeof(work_file_t));
  if (!new_wf)
    return NULL;
  new_wf->name = strdup(name);
  if (!new_wf->name) {
    free(new_wf);
    return NULL;
  }
  if (!hash)
    new_wf->hash = NULL;
  else
    new_wf->hash = strdup(hash);
  new_wf->mode = mode;
  return new_wf;
}

void free_work_file(work_file_t *wf) {
  if (!wf)
    return;
  free(wf->name);
  free(wf->hash);
  free(wf);
}
