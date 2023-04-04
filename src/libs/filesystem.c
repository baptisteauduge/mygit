#include "filesystem.h"
#include "hash.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

List **listdir(char *rootDir) {
  struct dirent *ep = NULL;
  List **list = initList();
  DIR *dp = opendir(rootDir);
  if (!dp || !list)
    return NULL;
  while ((ep = readdir(dp))) {
    if (!addFirstCell(list, ep->d_name)) {
      fprintf(stderr,
              "Error, the returned list of directories may be not complete");
      return list;
    }
  }
  return list;
}

int fileExists(char *file) {
  List **listDirCurrent = listdir(".");
  if (!listDirCurrent)
    return 0;
  int answer = searchList(listDirCurrent, file) != NULL;
  freeList(listDirCurrent);
  return answer;
}

void cp(char *to, char *from) {
  if (!to || !from)
    return;
  if (!fileExists(from)) {
    fprintf(stderr, "Error, the file %s doesn't exist\n", from);
    return;
  }
  FILE *fFrom = fopen(from, "r");
  FILE *fTo = fopen(to, "w");
  if (!fFrom || !fTo) {
    fprintf(stderr, "Error, can't open file %s or %s in read or write mode\n",
            from, to);
    return;
  }
  char buffer[SIZE_BUFFER_READ_LINE];
  while (fgets(buffer, SIZE_BUFFER_READ_LINE, fFrom))
    fputs(buffer, fTo);
  fclose(fFrom);
  fclose(fTo);
}

char *hashToPath(char *hash) {
  int strlenHash = strlen(hash);
  char *dir = malloc((strlenHash + 1) * sizeof(char));
  dir[0] = hash[0];
  dir[1] = hash[1];
  dir[2] = '/';
  for (int i = 3; i < strlenHash + 1; ++i) {
    dir[i] = hash[i - 1];
  }
  dir[strlenHash + 1] = '\0';
  return dir;
}

void blobFile(char *filename) {
  if (!filename)
    return;
  if (!fileExists(filename)) {
    fprintf(stderr, "Error, the file %s doesn't exist\n", filename);
    return;
  }
  char *hash = sha256file(filename);
  char *path = hashToPath(hash);
  char *dir = strdup(hash);
  dir[2] = '\0';
  if (!fileExists(dir)) {
    mkdir(dir, S_IRWXU);
  }
  cp(path, filename);
  free(path);
  free(dir);
  free(hash);
}
