// Sorbonne University, 2022 - 2023
// MyGit Project
//
// hash.c
// File description:
//   This file contains the implementation of the hash.h header.

#include "hash.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void put_hash_of_source(const char *source, const char *dest) {
  if (!source || !dest)
    return;
  size_t size_command = strlen(source) + strlen(dest) + 20;
  char *command = malloc(size_command * sizeof(char));
  sprintf(command, "cat %s | sha256sum > %s", source, dest);
  system(command);
  free(command);
}

static int get_hash_from_file(const char *temp_filename, char **sha256) {
  if (!temp_filename || !sha256)
    return 0;
  FILE *f = NULL;
  *sha256 = malloc(65 * sizeof(char));
  if (!*sha256)
    return 0;
  f = fopen(temp_filename, MODE_READ);
  if (!f) {
    free(*sha256);
    return 0;
  }
  fgets(*sha256, 65, f);
  fclose(f);
  return 1;
}

char *get_sha256_of_file(const char *filename) {
  if (!filename)
    return NULL;
  char temp_filename[] = "/tmp/XXXXXX";
  char *sha256;
  int fd;

  fd = mkstemp(temp_filename);
  put_hash_of_source(filename, temp_filename);
  if (!get_hash_from_file(temp_filename, &sha256)) {
    close(fd);
    remove_file(temp_filename);
  }
  remove_file(temp_filename);
  return sha256;
}

void remove_file(const char *filename) {
  if (!filename)
    return;
  char *buff = malloc((strlen(filename) + 4) * sizeof(char));
  sprintf(buff, "rm %s", filename);
  system(buff);
  free(buff);
}
