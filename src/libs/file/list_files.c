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
#include <sys/stat.h>

list_t *get_list_files_and_dir(const char *path)
{
  struct dirent *next_dir = NULL;
  list_t *list = NULL;
  DIR *dir = NULL;

  if (!path)
    return NULL;
  dir = opendir(path);
  if (!dir)
    return NULL;
  next_dir = readdir(dir);
  list = create_init_list();
  if (!list)
    return NULL;
  while (next_dir) {
    if (!create_and_insert_cell_in_list(list, next_dir->d_name)) {
      closedir(dir);
      return list;
    }
    next_dir = readdir(dir);
  }
  return list;
}

int does_file_exists(const char *file)
{
  struct stat buffer = {0};

  if (!file)
    return 0;
  return (stat(file, &buffer) == 0);
}
