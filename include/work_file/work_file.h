// MyGit Project
//
// work_file.h
// File description:
//    work_file.h

#ifndef WORK_FILE_H
#define WORK_FILE_H

#define MODE_MAX_SIZE_STR 4
#define TAB_SIZE 1

typedef struct work_file_s {
  char *name;
  char *hash;
  int mode;
} work_file_t;

work_file_t *create_work_file(const char *name, const char *hash, int mode);
void free_work_file(work_file_t *wf);

#endif
