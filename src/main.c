#include <stdio.h>
#include "libs/filesystem.h"

int main(void) {
  List **list = listdir("/Users/baptiste/Documents/github/cours/my_git");
  blobFile("main.c");
  printf("%s\n", ltos(list));
}
