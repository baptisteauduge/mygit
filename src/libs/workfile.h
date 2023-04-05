// Sorbonne University, 2022 - 2023
// MyGit Project
//
// workfile.c
// File description:
//      This file contains the implementation of the workfile structure. And the
//      signatures of the basics functions used to manipulate it.

#ifndef WORKFILE_H
#define WORKFILE_H

typedef struct {
  char *name;
  char *hash;
  int mode;
} WorkFile;

/**
 * @brief Create a Work File and initialize it, return NULL if error
 * mode is set to 0 by default and hash to NULL. Name is copied.
 *
 * @param name
 * @return WorkFile*
 */
WorkFile *create_work_file(const char *name);

/**
 * @brief Free a WorkFile if it's allocated.
 *
 * @param wf
 */
void free_work_file(WorkFile *wf);

#endif
