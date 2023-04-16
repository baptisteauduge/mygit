// MyGit Project
//
// mygit_help.c
// File description:
//    mygit_help.c

#include "mygit/mygit_help.h"
#include <stdio.h>
#include <string.h>

void mygit_help(void)
{
  printf(
      "\n----COMMANDS---- \n\n -init: initialize a new repository\n -list-refs: "
      "list all "
      "the references\n -create-ref: create a new reference\n\t ref: the name "
      "of the reference\n\t hash: the hash of the commit\n -delete-ref: delete "
      "a reference\n\t ref: the name of the reference\n -add: add a file to "
      "the "
      "staging area\n\t file: the name of the file\n\t [<file1>, <file2>, "
      "...]: the "
      "name of the files (optional)\n -list-add: list all the files in the "
      "staging area\n -clear-add: clear the staging area\n -commit: create a "
      "new commit,\n\t branch: the name of the branch\n\t -m<message>: the "
      "message of the commit (optional)\n -merge: merge the specified one to "
      "the current branch, the specified branch will then be deleted\n\t "
      "branch: the name of the branch to merge with the current branch\n\t "
      "-m<message>: the message of the merge (optional)\n\n");
}