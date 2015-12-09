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

/* Tries Headers */
#include <tries/trie/node.h>
#include <tries/trie/trie.h>

void trie_insert(TrieNode *head, const char *str)
{
  /* Size `n` of `str` */
  size_t n = strlen(str);
  if (n == 0) return;

  /* Create the substring */
  char substring[n];
  for (int i = 0; i < n - 1; i++)
    substring[i] = str[i + 1];
  substring[n - 1] = '\0';

  /* Get current letter */
  int current_letter_position = str[0] - (int)'a';
  
  /* Check if child with letter `current_letter_position` it's available */
  if (head->child[current_letter_position] == NULL)
  {
    head->child[current_letter_position] = create_trie_node();
    head->child[current_letter_position]->is_end_char = false;
  }

  /* If it's the last char to be inserted */
  if (n == 1)
  {
    head->child[current_letter_position]->is_end_char = true;
  }
  else
    /* Next character */
    trie_insert(head->child[current_letter_position], substring);
}

bool trie_find(TrieNode *trie, const char *str)
{
  /* If current node it's false */
  if (!trie) return false;

  /* Size `n` of `str` */
  size_t n = strlen(str);

  /* Iterator */
  TrieNode *it = trie;
  
  /* Iterate for each str char */
  for (int i = 0; i < n; i++)
  {
    if (it->child[str[i] - (int)'a'] == NULL)
      return false;
    else
    {
      it = it->child[str[i] - (int)'a'];
    }
  }

  /* Check if the string ended */
  if (it->is_end_char == true) return true;
  else return false;
}