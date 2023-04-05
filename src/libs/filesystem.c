// Sorbonne University, 2022 - 2023
// MyGit Project
//
// filesystem.c
// File description:
//   This file contains the implementation of the filesystem.h header.

#include "filesystem.h"
#include "hash.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

List **get_list_files_and_dir(const char *rootDir) {
  struct dirent *ep = NULL;
  List **list = create_init_list();
  DIR *dp = opendir(rootDir);
  if (!dp || !list)
    return NULL;
  while ((ep = readdir(dp))) {
    if (!create_and_insert_cell_in_list(list, ep->d_name)) {
      fprintf(stderr,
              "Error, the returned list of directories may be not complete");
      return list;
    }
  }
  return list;
}

int does_file_exists(const char *file) {
  struct stat buffer;
  return (stat(file, &buffer) == 0);
}

void copy_file(const char *to, const char *from) {
  if (!to || !from)
    return;
  if (!does_file_exists(from)) {
    fprintf(stderr, "Error, the file %s doesn't exist\n", from);
    return;
  }
  FILE *file_from = fopen(from, "r");
  FILE *file_to = fopen(to, "w");
  if (!file_from || !file_to) {
    fprintf(stderr, "Error, can't open file %s or %s in read or write mode\n",
            from, to);
    return;
  }
  char buffer[SIZE_BUFFER_READ_LINE];
  while (fgets(buffer, SIZE_BUFFER_READ_LINE, file_from))
    fputs(buffer, file_to);
  fclose(file_from);
  fclose(file_to);
}

char *get_path_from_hash(const char *hash) {
  int strlen_hash = strlen(hash);
  char *dir = malloc((strlen_hash + 1) * sizeof(char));
  dir[0] = hash[0];
  dir[1] = hash[1];
  dir[2] = '/';
  for (int i = 3; i < strlen_hash + 1; ++i) {
    dir[i] = hash[i - 1];
  }
  dir[strlen_hash + 1] = '\0';
  return dir;
}

void create_blob(const char *filename) {
  if (!filename)
    return;
  if (!does_file_exists(filename)) {
    fprintf(stderr, "Error, the file %s doesn't exist\n", filename);
    return;
  }
  char *hash = get_sha256_of_file(filename);
  char *path = get_path_from_hash(hash);
  char *dir = strdup(hash);
  dir[2] = '\0';
  if (!does_file_exists(dir)) {
    mkdir(dir, S_IRWXU);
  }
  copy_file(path, filename);
  free(path);
  free(dir);
  free(hash);
}
