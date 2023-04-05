// Sorbonne University, 2022 - 2023
// MyGit Project
//
// main.c
// File description:
//    This file contains the main function of the program.

#include "worktree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  WorkTree *list = stwt("name1\thash1\t777\nname2\thash2\t777\nname3\thash3\t77"
                        "7\nname4\thash4\t777");
  // appendWorkTree(list, "name1", "hash1", 777);
  // appendWorkTree(list, "name2", "hash2", 777);
  // appendWorkTree(list, "name3", "hash3", 777);
  // appendWorkTree(list, "name4", "hash4", 777);
  char *str = wtts(list);
  printf("%s\n", str);
  free(str);
  char *blobPath = blobWorkTree(list);
  printf("Blob path %s\n", blobPath);
  freeWorkTree(list);
  free(blobPath);
  // printf("%s\n", ltos(list));
}
