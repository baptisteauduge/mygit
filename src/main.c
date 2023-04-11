// Sorbonne University, 2022 - 2023
// MyGit Project
//
// main.c
// File description:
//    This file contains the main function of the program.

// #include "libs/convert_worktree.h"
// #include "libs/file_worktree.h"
// #include "libs/worktree.h"
#include <stdio.h>
#include <stdlib.h>
#include <work_tree/convert_str_work_tree.h>
#include <work_tree/insert_get_search_work_tree.h>
#include <work_tree/restore_work_tree.h>
#include <work_tree/save_content_and_work_tree.h>
#include <work_tree/save_get_file_work_tree.h>
#include <work_tree/work_tree.h>
#include <commit/create_blob_of_commit.h>
#include <commit/convert_str_commit.h>

int main(void)
{
  //   WorkTree *list = string_to_worktree(
  //       "name1\thash1\t777\nname2\thash2\t777\nname3\thash3\t77"
  //       "7\nname4\thash4\t777");
  // append_work_tree_with_values(list, "name1", "hash1", 777);
  // append_work_tree_with_values(list, "name2", "hash2", 777);
  // append_work_tree_with_values(list, "name3", "hash3", 777);
  // append_work_tree_with_values(list, "name4", "hash4", 777);
  // char *str = worktree_to_string(list);
  // printf("%s\n", str);
  // free(str);
  // char *blobPath = create_blob_of_worktree(list);
  // printf("Blob path %s\n", blobPath);
  // free_worktree(list);
  // free(blobPath);
  // printf("%s\n", list_to_string(list));

  // work_tree_t *wt = create_and_init_work_tree();
  // append_work_tree(wt, ".gitignore", NULL, 0);
  // append_work_tree(wt, "Makefile", NULL, 0);
  // append_work_tree(wt, "testing", NULL, 0);
  // char *work_tree_str = convert_work_tree_to_str(wt);
  // printf("%s\n", work_tree_str);
  // free(work_tree_str);
  // char *hash = save_content_and_work_tree(wt, ".");
  // work_tree_str = convert_work_tree_to_str(wt);
  // printf("%s\n", work_tree_str);
  // free(work_tree_str);
  // free_work_tree(wt);
  // free(hash);

  // work_tree_t *wt = file_to_work_tree(
  //     ".mygit/objects/08/"
  //     "8e693e95dc0bf274ff6afd748cf304e17383adbdfa9f513c1e3d11ab51bfe1.t");
  // char *str = convert_work_tree_to_str(wt);
  // printf("%s\n", str);
  // printf("aaa\n");
  // restore_work_tree(wt, ".");
  // free_work_tree(wt);
  // free(str);

  // commit_t *commit = create_commit_with_tree_key_val("123456789012345678901234");
  // char *commit_str = convert_commit_to_str(commit);
  // printf("%s\n", commit_str);
  // free(commit_str);
  // char *blobPath = create_blob_of_commit(commit);
  // printf("Blob path %s\n", blobPath);
  // free(blobPath);
  // free_commit(commit);
  
  return 0;
}
