#ifndef LIST_H
#define LIST_H

#define MAX_FILES 100
#define MAX_LEN_DATA 100
#define SEPARATOR_LIST_STRING "|"
#define SIZE_BUFFER_READ_LINE 512

typedef struct cell {
  char *data;
  struct cell *next;
} Cell;
typedef Cell List;

List **initList();
/**
 * @brief Function used to build a new Cell, will return NULL if any error
 * The provided data will be copied
 *
 * @param data
 * @return Cell*
 */
Cell *buildCell(char *data);
/**
 * @brief Function used to free a cell, if the cell is NULL, nothing will be done
 *
 * @param cell
 */
void freeCell(Cell *cell);

/**
 * @brief Function used to free a list, if the list is NULL, nothing will be
 * done
 *
 * @param list
 */
void freeList(List **list);

/**
 * @brief Function that will add the provided Cell at the begging of the list
 * provided.
 *
 * @param list
 * @param cell
 */
void insertFirst(List **list, Cell *cell);

/**
 * @brief Function that return the pos-ème element of the list, or NULL if error
 *
 * @param list
 * @param pos the index of the element you are looking for
 * @return Cell*
 */
Cell *listGet(List **list, int pos);

/**
 * @brief Cell to string
 *
 * @param cell
 * @return char*
 */
char *ctos(Cell *cell);

/**
 * @brief List to string, return NULL if error
 *
 * @param list
 * @return char*
 */
char *ltos(List **list);

/**
 * @brief Search and return (if it exist) the element of the list where data ==
 * str If the element is not in the list, we will return NULL.
 *
 * @param list
 * @param str
 * @return Cell*
 */
Cell *searchList(List **list, char *str);

/**
 * @brief Create a cell containing data and add it at the begging of list.
 * The function returns a control, if returned 1, all good.
 *
 * @param list
 * @param data
 * @return int
 */
int addFirstCell(List **list, char *data);

/**
 * @brief Function used to create a List using a string,
 * format must be : "firstCell|secondCell| ... | lastCell"
 * WHERE "|" is the SEPARATOR_LIST_STRING (in a define)
 *
 * @param str
 * @return List**
 */
List **stol(char *str);

/**
 * @brief Function used to save a list into a file
 *
 * @param list
 * @param path
 */
void ltof(List **list, char *path);

/**
 * @brief Function used to load a list from a file
 *
 * @param path
 * @return List**
 */
List **ftol(char *path);

#endif