// MyGit Project
//
// list_files.c
// File description:
//    list_files.c

#include "file/list_files.h"
#include "list/insert_get_search_list.h"
#include "list/list.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static void read_dir_and_fill_list(DIR *dir, list_t *list)
{
  struct dirent *next_dir = NULL;

  next_dir = readdir(dir);
  while (next_dir) {
    if (strcmp(next_dir->d_name, "..") != 0 &&
        strcmp(next_dir->d_name, ".") != 0) {
      if (!create_and_insert_cell_in_list(list, next_dir->d_name))
        return;
    }
    next_dir = readdir(dir);
  }
  return;
}

list_t *get_list_files_and_dir(const char *path)
{
  list_t *list = NULL;
  DIR *dir = NULL;

  if (!path)
    return NULL;
  dir = opendir(path);
  if (!dir)
    return NULL;
  list = create_init_list();
  if (!list)
    return NULL;
  read_dir_and_fill_list(dir, list);
  closedir(dir);
  return list;
}

int does_file_exists(const char *file)
{
  struct stat buffer = {0};

  if (!file)
    return 0;
  return (stat(file, &buffer) == 0);
}

int is_file(const char *file)
{
  struct stat buffer = {0};

  if (!file)
    return 0;
  if (stat(file, &buffer) == -1)
    return 0;
  return S_ISREG(buffer.st_mode);
}
