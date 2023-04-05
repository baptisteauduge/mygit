// Sorbonne University, 2022 - 2023
// MyGit Project
//
// worktree.c
// File description:
//     This file contains the implementation of the worktree.h header.

#include "worktree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WorkFile *createWorkFile(const char *name) {
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

void freeWorkFile(WorkFile *wf) {
  if (!wf)
    return;
  free(wf->name);
  if (wf->hash)
    free(wf->hash);
  free(wf);
}

static const char *contentOrEmpty(const char *str) {
  if (!str)
    return "";
  return str;
}

char *wfts(const WorkFile *wf) {
  if (!wf)
    return NULL;
  char *res = malloc(sizeof(char) * WORKTREE_FIELD_MAX_SIZE * 3);
  if (!res)
    return NULL;
  snprintf(res, sizeof(char) * WORKTREE_FIELD_MAX_SIZE * 3, "%s\t%s\t%d",
           contentOrEmpty(wf->name), contentOrEmpty(wf->hash), wf->mode);
  return res;
}

WorkFile *stwf(const char *str) {
  if (!str)
    return NULL;
  char name[WORKTREE_FIELD_MAX_SIZE], hash[WORKTREE_FIELD_MAX_SIZE];
  int mode;
  if (sscanf(str, "%s\t%s\t%d", name, hash, &mode) != 3)
    return NULL;
  WorkFile *res = createWorkFile(name);
  if (!res)
    return NULL;
  res->hash = strdup(hash);
  res->mode = mode;
  return res;
}

WorkTree *initWorkTree() {
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

void freeWorkTree(WorkTree *wt) {
  if (!wt)
    return;
  if (wt->tab) {
    for (int i = 0; i < wt->size; ++i) {
      if (wt->tab[i].name)
        free(wt->tab[i].name);
      if (wt->tab[i].hash)
        free(wt->tab->hash);
    }
    free(wt->tab);
  }
  free(wt);
}

int inWorkTree(const WorkTree *wt, const char *name) {
  if (!wt || !name)
    return -1;
  for (int i = 0; i < wt->n; ++i) {
    if (!strcmp(wt->tab[i].name, name))
      return i;
  }
  return -1;
}

int appendWorkTree(WorkTree *wt, const char *name, const char *hash, int mode) {
  if (!wt || wt->size <= wt->n || !name)
    return -1;
  if (inWorkTree(wt, name) >= 0)
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

char *wtts(const WorkTree *wt) {
  if (!wt)
    return NULL;
  size_t resSize = wt->n * (WORKTREE_FIELD_MAX_SIZE * 3 + 1);
  char *res = malloc(sizeof(char) * resSize), *tmp = NULL;

  if (!res)
    return NULL;
  for (int i = 0; i < wt->n; ++i) {
    tmp = wfts(wt->tab + i);
    snprintf(res, resSize, "%s%s", res, tmp);
    if (i != wt->n - 1)
      snprintf(res, resSize, "%s\n", res);
    free(tmp);
  }
  return res;
}

WorkTree *stwt(const char *str) {
  if (!str)
    return NULL;

  int bufferOffset = 0, bufferSize = 0;
  char buffer[WORKTREE_FIELD_MAX_SIZE * 3];
  WorkFile *tmp = NULL;
  WorkTree *res = initWorkTree();
  if (!res)
    return NULL;

  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '\n') {
      memcpy(buffer, str + bufferOffset, bufferSize * sizeof(char));
      buffer[bufferSize] = '\0';
      tmp = stwf(buffer);
      if (!tmp) {
        fprintf(stderr, "Error, when creating a new workfile, the returned "
                        "WorkTree could be uncomplete\n");
        return res;
      }
      if (!appendWorkTree(res, tmp->name, tmp->hash, tmp->mode)) {
        fprintf(stderr, "Error when trying to append the WorkTree, WorkTree "
                        "could be uncomplete\n");
        freeWorkFile(tmp);
        return res;
      }
      bufferOffset += bufferSize + 1;
      bufferSize = 0;
      freeWorkFile(tmp);
      continue;
    }
    ++bufferSize;
  }
  memcpy(buffer, str + bufferOffset, bufferSize * sizeof(char));
  buffer[bufferSize] = '\0';
  tmp = stwf(buffer);
  if (!tmp) {
    fprintf(stderr, "Error, when creating a new workfile, the returned "
                    "WorkTree could be uncomplete\n");
    return res;
  }
  if (!appendWorkTree(res, tmp->name, tmp->hash, tmp->mode)) {
    fprintf(stderr, "Error when trying to append the WorkTree, WorkTree could "
                    "be uncomplete\n");
    freeWorkFile(tmp);
    return res;
  }
  freeWorkFile(tmp);
  return res;
}

int wttf(const WorkTree *wt, char *file) {
  if (!wt || !file)
    return -1;
  FILE *f = fopen(file, "w");
  if (!f)
    return -1;
  char *wtStr = wtts(wt);
  if (!wtStr) {
    fclose(f);
    return -1;
  }
  if (fprintf(f, "%s", wtStr) != 0) {
    fclose(f);
    free(wtStr);
    return -1;
  }
  fclose(f);
  free(wtStr);
  return 0;
}

