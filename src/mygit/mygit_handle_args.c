// MyGit Project
//
// mygit_handle_args.c
// File description:
//    mygit_handle_args.c

#include "mygit/mygit_handle_args.h"
#include "mygit/mygit_handle_args_actions.h"
#include <stdio.h>
#include <string.h>

int mygit_handle_args(int argc, char **argv)
{
  char *actions_names[] = {"init", "list-refs", "create-ref", "delete-ref",
                           "add",  "list-add",  "clear-add",  "commit"};

  handle_args_func actions_func[] = {
      init_handle_args,       list_refs_handle_args, create_ref_handle_args,
      delete_ref_handle_args, add_handle_args,       list_add_handle_args,
      clear_add_handle_args,  commit_handle_args};
  int nb_actions = 8;

  for (int i = 0; i < nb_actions; ++i) {
    if (strcmp(argv[2], actions_names[i]) == 0)
      return actions_func[i](argc, argv);
  }
  fprintf(stderr, "Error: bad usage, %s is not an available action\n", argv[2]);
  return 1;
}
