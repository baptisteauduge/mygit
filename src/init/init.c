// MyGit Project
//
// init.c
// File description:
//    init.c

#include "init/init.h"
#include "file/copy_file.h"
#include "file/create_empty_file.h"
#include "file/list_files.h"
#include "utils/constants.h"
#include <sys/stat.h>

void init_mygit(void)
{
  if (!does_file_exists(MYGIT_DIR))
    mkdir(MYGIT_DIR_BLOBS, MYGIT_DIR_RIGTHS);
  init_blobs();
  init_refs();
}

void init_blobs(void)
{
  if (!does_file_exists(MYGIT_DIR_BLOBS))
    mkdir(MYGIT_DIR_BLOBS, MYGIT_DIR_RIGTHS);
}

void init_refs(void)
{
  if (!does_file_exists(MYGIT_DIR_REFS)) {
    mkdir(MYGIT_DIR_REFS, MYGIT_DIR_RIGTHS);
    create_empty_file(MYGIT_DIR_REFS "HEAD");
    create_empty_file(MYGIT_DIR_REFS "master");
  }
}
