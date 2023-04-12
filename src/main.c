// Sorbonne University, 2022 - 2023
// MyGit Project
//
// main.c
// File description:
//    main.c

#include "mygit/mygit_handle_args.h"
#include "utils/utils.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc < 2)
    LOG_ERROR("Error: bad usage\n");
  else
    return mygit_handle_args(argc, argv);
}
