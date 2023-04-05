// Sorbonne University, 2022 - 2023
// MyGit Project
//
// worktree.h
// File description:
//     This file contains the definition of the WorkTree structure and
//     the functions to manipulate it.

#ifndef WORKTREE_H
#define WORKTREE_H

#define WORKTREE_FIELD_MAX_SIZE 256
#define WORKTREE_INIT_SIZE 100

typedef struct {
  char *name;
  char *hash;
  int mode;
} WorkFile;

typedef struct {
  WorkFile *tab;
  int size;
  int n;
} WorkTree;

/**
 * @brief Create a Work File and initialize it, return NULL if error
 * mode is set to 0 by default and hash to NULL. Name is copied.
 *
 * @param name
 * @return WorkFile*
 */
WorkFile *createWorkFile(const char *name);

/**
 * @brief Free a WorkFile if it's allocated.
 *
 * @param wf
 */
void freeWorkFile(WorkFile *wf);

/**
 * @brief Convert a WorkFile to a string, each field is separated by
 * tabulation. If one field is NULL, it is replaced by an empty string.
 *
 * @param wf
 * @return char*
 */
char *wfts(const WorkFile *wf);

/**
 * @brief Convert a string to a WorkFile. All fields must be separated by
 * tabulation.
 *
 * @param str
 * @return WorkFile*
 */
WorkFile *stwf(const char *str);

/**
 * @brief Create and init a WorkTree of size WORKTREE_INIT_SIZE
 *
 * @return WorkTree*
 */
WorkTree *initWorkTree();

/**
 * @brief Free a WorkTree if it's allocated.
 *
 * @param wt
 */
void freeWorkTree(WorkTree *wt);

/**
 * @brief Returns the index of the WorkFile in the tab
 * if the "name" is in the WorkTree, else -1.
 *
 * @param wt
 * @param name
 * @return int
 */
int inWorkTree(const WorkTree *wt, const char *name);

/**
 * @brief Add a WorkFile to the WorkTree if it's not already in.
 *
 * @param wt The WorkTree
 * @param name The name of the new WorkFile
 * @param hash The hash of the new WorkFile
 * @param mode The mode of the new WorkFile
 * @return int 1 if everything went well, 0 if the WorkFile was already in the
 * WorkTree, -1 if an error occured (like if the tab is full).
 */
int appendWorkTree(WorkTree *wt, const char *name, const char *hash,
                   const int mode);

/**
 * @brief Return a string representing the WorkTree. Each WorkFile is separated
 * by a newline.
 *
 * @param wt
 * @return char*
 */
char *wtts(const WorkTree *wt);

/**
 * @brief Return the WorkTree corresponding to a String. Refer to wtts and wfts
 *
 * @param str
 * @return WorkTree*
 */
WorkTree *stwt(const char *str);


/**
 * @brief Write the WorkTree in a file, return 0 if everything went well, -1
 * otherwise.
 * 
 * @param wt 
 * @param file 
 * @return int 
 */
int wttf(const WorkTree* wt, char* file);

#endif