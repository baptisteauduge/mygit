// Sorbonne University, 2022 - 2023
// MyGit Project
// 
// hash.c
// File description:
//   This file contains the implementation of the hash.h header.

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void put_hash_of_source(const char *source, const char *dest) {
  if (!source || !dest)
    return;
  char command[1000];
  sprintf(command, "cat %s | sha256sum > %s", source, dest);
  system(command);
}

char *get_sha256_of_file(const char *filename) {
  if (!filename)
    return NULL;
  static char template[] = "/tmp/XXXXXX";
  char temp_filename[1000], *sha256;
  int fd;
  FILE *f;

  strcpy(temp_filename, template);
  fd = mkstemp(temp_filename);

  put_hash_of_source(filename, temp_filename);
  sha256 = malloc(65 * sizeof(char));
  if (!sha256) {
      close(fd);
      remove_file(temp_filename);
      return NULL;
  }
  f = fopen(temp_filename, "r");
  fgets(sha256, 65, f);

  fclose(f);
  close(fd);
  remove_file(temp_filename);

  return sha256;
}

void remove_file(const char *filename) {
  if (!filename)
    return;
  char buff[1000];
  sprintf(buff, "rm %s", filename);
  system(buff);
}
