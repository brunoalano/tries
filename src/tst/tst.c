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

/* Standard Libraries */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/* TST Headers */
#include <tries/tst/tst.h>

bool tst_find(TST *head, const char *str)
{
  while(head) {
    if(*str < head->data)
      head = head->lesser;
    else if(*str > head->data)
      head = head->greater;
    else if(*str == '\0')
      return true;
    else
    {
      head = head->equal;
      str++;
    }
  }
  return false;
}

void tst_insert(TST *head, const char *str)
{
  if (!head)
  {
    head = malloc(sizeof(TST));
    head->data = *str;
    head->lesser = head->equal = head->greater = NULL;
  }

  /* now follow search */
  if(*str < head->data)
    tst_insert(head->lesser, str);
  else if(*str > head->data)
    tst_insert(head->greater, str);
  else if (*str == '\0')
    return;
  else
    tst_insert(head->equal, str+1);
}
