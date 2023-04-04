#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void hashFile(char *source, char *dest) {
  if (!source || !dest)
    return;
  char buff[1000];
  sprintf(buff, "cat %s | sha256sum > %s", source, dest);
  system(buff);
}

char *sha256file(char *filename) {
  if (!filename)
    return NULL;
  static char template[] = "/tmp/XXXXXX";
  char tempFileName[1000], *sha256;
  int fd;
  FILE *f;

  strcpy(tempFileName, template);
  fd = mkstemp(tempFileName);

  hashFile(filename, tempFileName);
  sha256 = malloc(65 * sizeof(char));
  f = fopen(tempFileName, "r");
  fgets(sha256, 65, f);

  fclose(f);
  close(fd);
  removeFile(tempFileName);

  return sha256;
}

void removeFile(char *filename) {
  if (!filename)
    return;
  char buff[1000];
  sprintf(buff, "rm %s", filename);
  system(buff);
}
