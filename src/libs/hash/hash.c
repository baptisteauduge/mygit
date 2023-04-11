// MyGit Project
//
// hash.c
// File description:
//    hash.c

#include "hash/hash.h"
#include "file/constants_file.h"
#include "file/read_write_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *get_sha256_of_file(const char *filename)
{
  char temp_filename[] = "/tmp/XXXXXX";
  char *sha256 = NULL;
  int fd = 0;

  if (!filename)
    return NULL;
  fd = mkstemp(temp_filename);
  if (fd == -1)
    return NULL;
  put_hash_of_source_in_dest(filename, temp_filename);
  sha256 = get_first_line(temp_filename);
  sha256[64] = '\0';
  if (!sha256)
    return NULL;
  close(fd);
  remove(temp_filename);
  return sha256;
}

void put_hash_of_source_in_dest(const char *source, const char *dest)
{
  char *command = NULL;
  size_t size_command = 0;

  if (!source || !dest)
    return;
  size_command = strlen(source) + strlen(dest) + 20;
  command = calloc(size_command, sizeof(char));
  sprintf(command, "cat %s | sha256sum > %s", source, dest);
  system(command);
  free(command);
}

// Function djb2 from http://www.cse.yorku.ca/~oz/hash.html
unsigned long commit_hash_func(const char *str)
{
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash;
}
