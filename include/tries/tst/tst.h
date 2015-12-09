/**
 *  _        _           
 * | |      (_)          
 * | |_ _ __ _  ___  ___ 
 * | __| '__| |/ _ \/ __|
 * | |_| |  | |  __/\__ \
 *  \__|_|  |_|\___||___/
 *
 * Tries: Opensource High-Performance TRIE-like Structures
 * by Bruno Alano Medina
 */

#ifndef _TST_H_INCLUDED
#define _TST_H_INCLUDED

/* Standard Libraries */
#include <stdbool.h>

/* Ternary Search Tree Node */
struct tst {
  /* Data */
  char data;

  /* Lower values (y < data) */
  struct tst *lesser;

  /* Equal values (y == data) */
  struct tst *equal;

  /* Greater values (y > data) */
  struct tst *greater;
};
typedef struct tst TST;

/**
 * Search `str` on Ternary Search Tree
 * 
 * @param  head top of tree
 * @param  str  value to be searched
 * @return      node
 */
bool tst_find(TST *head, const char *str);

/**
 * Add `str` to Ternary Search Tree
 */
void tst_insert(TST *head, const char *str);

#endif