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
  printf("Here is all your refs:\n%s\n", str_all_ref);
  free(str_all_ref);
  return 0;
}

int create_ref_handle_args(int argc, char **argv)
{
  char *ref_path = NULL;

  if (argc < 5) {
    LOG_ERROR("Error: bad usage\nUsage: mygit create-ref "
              "<ref> <commit>\n");
    return 1;
  }
  ref_path = get_path_absolute(MYGIT_DIR_REFS, argv[3]);
  if (ref_path == NULL)
    return 1;
  if (does_file_exists(ref_path)) {
    LOG_ERROR("Error: ref already exists, delete it before\n");
    free(ref_path);
    return 1;
  }
  free(ref_path);
  create_or_update_ref(argv[3], argv[4]);
  printf("Ref %s created\n", argv[3]);
  return 0;
}

int delete_ref_handle_args(int argc, char **argv)
{
  if (argc < 4) {
    LOG_ERROR("Error: bad usage\nUsage: mygit delete-ref <ref>\n");
    return 1;
  }
  if (!delete_ref(argv[3])) {
    LOG_ERROR("Error: can't delete ref\n");
    return 1;
  }
  printf("Ref %s deleted\n", argv[3]);
  return 0;
}

int add_handle_args(int argc, char **argv)
{
  if (argc < 3) {
    fprintf(
        stderr,
        "Error: bad usage\nUsage: mygit add <elem> [<elem2> <elem3> ...]\n");
    return 1;
  }
  for (int i = 3; i < argc; i++) {
    if (!mygit_add(argv[i]))
      return 1;
    printf("File %s added\n", argv[i]);
  }
  return 0;
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
  printf("Here is all your added files and directories:\n%s\n", str_list_add);
  free(str_list_add);
  return 0;
}

// Note: the lines (void)argc; (void)argv; are used to avoid warnings
int clear_add_handle_args(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  if (!remove(MYGIT_PATH_ADD)) {
    LOG_ERROR("Error: can't clear list of added files\n It's probably "
              "because you didn't add any file yet\n");
    return 1;
  }
  printf("List of added files cleared\n");
  return 0;
}

int commit_handle_args(int argc, char **argv)
{
  if (argc < 3) {
    LOG_ERROR(
        "Error: bad usage\nUsage: mygit commit <branch> [-m <message>]\n");
    return 1;
  }
  if (argc == 3) {
    if (!mygit_commit(argv[2], NULL)) {
      LOG_ERROR("Error: can't commit\n");
      return 1;
    }
    printf("Commit done\n");
    return 0;
  }
  if (argc >= 5 && strcmp(argv[3], "-m")) {
    if (!mygit_commit(argv[2], argv[4])) {
      LOG_ERROR("Error: can't commit\n");
      return 1;
    }
    printf("Commit done\n");
    return 0;
  }
  LOG_ERROR("Error: bad usage\nUsage: mygit commit <branch> [-m <message>]\n");
  return 1;
}