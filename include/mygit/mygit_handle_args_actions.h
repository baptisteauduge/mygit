// MyGit Project
//
// mygit_handle_args_actions.h
// File description:
//    mygit_handle_args_actions.h

#ifndef MYGIT_HANDLE_ARGS_ACTIONS_H
#define MYGIT_HANDLE_ARGS_ACTIONS_H

int init_handle_args(int argc, char **argv);
int list_refs_handle_args(int argc, char **argv);
int create_ref_handle_args(int argc, char **argv);
int delete_ref_handle_args(int argc, char **argv);
int add_handle_args(int argc, char **argv);
int list_add_handle_args(int argc, char **argv);
int clear_add_handle_args(int argc, char **argv);
int commit_handle_args(int argc, char **argv);
int current_branch_handle_args(int argc, char **argv);
int branch_handle_args(int argc, char **argv);
int branch_print_handle_args(int argc, char **argv);
int checkout_branch_handle_args(int argc, char **argv);
int checkout_commit_handle_args(int argc, char **argv);

#endif