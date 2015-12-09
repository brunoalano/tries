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

#ifndef _NODE_H_INCLUDED
#define _NODE_H_INCLUDED

/* Standard Libraries */
#include <stdbool.h>

/* Alphabet Size */
#define ALPHABET_SIZE 26

/* Node Structure */
struct trie_node {
  /* Is a termination character? */
  bool is_end_char;

  /* The possible next character */
  struct trie_node *child[ALPHABET_SIZE];
};
typedef struct trie_node TrieNode;

/**
 * Create Empty Node
 *
 * This will allocate memory for a Node.
 * 
 * @return Node without data
 */
TrieNode *create_trie_node();

#endif