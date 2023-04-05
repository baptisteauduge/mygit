// Sorbonne University, 2022 - 2023
// MyGit Project
// 
// main.c
// File description:
//    This file contains the main function of the program.

#include <stdio.h>
#include "libs/filesystem.h"

int main(void) {
  List **list = listdir("/Users/baptiste/Documents/github/cours/my_git");
  blobFile("main.c");
  printf("%s\n", ltos(list));
}
