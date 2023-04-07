// MyGit Project
//
// test_hash.c
// File description:
//     test_hash.c

#include "test_hash.h"
#include "hash/hash.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_hash(void) {
  put_hash_of_source("libs/test_hash.c", "libs/test_hash.sha256");
  char *hash = get_sha256_of_file("libs/test_hash.c");
  FILE *file = fopen("libs/test_hash.sha256", "r");
  char *hash2 = malloc(sizeof(char) * 65);
  fgets(hash2, 65, file);
  assert(strcmp(hash, hash2) == 0);
  remove_file("libs/test_hash.sha256");
  free(hash);
  free(hash2);
}
