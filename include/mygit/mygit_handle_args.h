// MyGit Project
//
// mygit_handle_args.h
// File description:
//    mygit_handle_args.h

#ifndef MYGIT_HANDLE_ARGS_H
#define MYGIT_HANDLE_ARGS_H

typedef int (*handle_args_func)(int, char **);

int mygit_handle_args(int argc, char **argv);

#endif
