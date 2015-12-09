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
#include <stdbool.h>

/* Tries Headers */
#include <tries/trie/node.h>

TrieNode *create_trie_node()
{
  TrieNode *node = malloc(sizeof(TrieNode));
  for (int i = 0; i < ALPHABET_SIZE; i++)
    node->child[i] = NULL;
  node->is_end_char = false;
  return node;
}