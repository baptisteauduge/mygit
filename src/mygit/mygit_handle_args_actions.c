// MyGit Project
//
// mygit_handle_args_actions.c
// File description:
//    mygit_handle_args_actions.c

#include "file/get_path_absolute.h"
#include "file/list_files.h"
#include "init/init.h"
#include "mygit/mygit_add.h"
#include "mygit/mygit_commit.h"
#include "refs/refs.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note: the lines (void)argc; (void)argv; are used to avoid warnings
int init_handle_args(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  init_all();
  printf("MyGit initialized\n");
  return 0;
}

// Note: the lines (void)argc; (void)argv; are used to avoid warnings
int list_refs_handle_args(int argc, char **argv)
{
  char *str_all_ref = get_str_all_ref();

  (void)argc;
  (void)argv;
  if (str_all_ref == NULL)
    return 1;
  printf("%s", str_all_ref);
  free(str_all_ref);
  return 0;
}

int create_ref_handle_args(int argc, char **argv)
{
  char *ref_path = NULL;

  if (argc < 4) {
    LOG_ERROR("Usage: mygit create-ref <ref> <hash>\n");
    return 1;
  }
  ref_path = get_path_absolute(MYGIT_DIR_REFS, argv[2]);
  if (ref_path == NULL)
    return 1;
  if (does_file_exists(ref_path)) {
    fprintf(stderr, "Error: ref '%s' already exists, delete it before\n",
            argv[2]);
    free(ref_path);
    return 1;
  }
  free(ref_path);
  create_or_update_ref(argv[2], argv[3]);
  printf("Ref '%s' created\n", argv[2]);
  return 0;
}

int delete_ref_handle_args(int argc, char **argv)
{
  if (argc < 3) {
    LOG_ERROR("Usage: mygit delete-ref <ref>\n");
    return 1;
  }
  if (!delete_ref(argv[2])) {
    fprintf(stderr, "Error: can't delete ref '%s'\n", argv[2]);
    return 1;
  }
  printf("Ref '%s' deleted\n", argv[2]);
  return 0;
}

int add_handle_args(int argc, char **argv)
{
  int ret = 0;

  if (argc < 3) {
    LOG_ERROR("Usage: mygit add <elem> [<elem2> <elem3> ...]\n");
    return 1;
  }
  for (int i = 2; i < argc; i++) {
    if (!mygit_add(argv[i]))
      ret = 1;
    else
      printf("File '%s' added\n", argv[i]);
  }
  return ret;
}

// Note: the lines (void)argc; (void)argv; are used to avoid warnings
int list_add_handle_args(int argc, char **argv)
{
  char *str_list_add = get_mygit_list_add_str();

  (void)argc;
  (void)argv;
  if (!str_list_add) {
    LOG_ERROR("Error: can't get list of added files\nIt's probably "
              "because you didn't add any file yet\n");
    return 1;
  }
  printf("%s\n", str_list_add);
  free(str_list_add);
  return 0;
}

// Note: the lines (void)argc; (void)argv; are used to avoid warnings
int clear_add_handle_args(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  if (remove(MYGIT_PATH_ADD) == 0) {
    printf("List of added files cleared\n");
    return 0;
  }
  LOG_ERROR("Error: can't clear list of added files\n It's probably "
            "because you didn't add any file yet\n");
  return 1;
}

int commit_handle_args(int argc, char **argv)
{
  char *commit_hash = NULL;

  if (argc < 3) {
    LOG_ERROR("Usage: mygit commit <branch> [-m <message>]\n");
    return 1;
  }
  if (argc == 3) {
    commit_hash = mygit_commit(argv[2], NULL);
    if (!commit_hash) {
      LOG_ERROR("Error: can't commit\n");
      return 1;
    }
    printf("Commit '%s' created\n", commit_hash);
    free(commit_hash);
    return 0;
  }
  if (argc >= 5 && !strcmp(argv[3], "-m")) {
    commit_hash = mygit_commit(argv[2], argv[4]);
    if (!commit_hash) {
      LOG_ERROR("Error: can't commit\n");
      return 1;
    }
    printf("Commit '%s' created\n", commit_hash);
    free(commit_hash);
    return 0;
  }
  LOG_ERROR("Usage: mygit commit <branch> [-m <message>]\n");
  return 1;
}