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

#ifndef _TRIE_H_INCLUDED
#define _TRIE_H_INCLUDED

/* Tries Headers */
#include <tries/trie/node.h>

/**
 * Insert String into TRIE
 *
 * This is a recursive implementation of a Trie Insertion, where we
 * need to iterate in each char of `str`.
 * 
 * @param str string to be inserted
 */
void trie_insert(TrieNode *head, const char *str);

/**
 * Find String in Trie
 * 
 * @param  trie [description]
 * @param  str  [description]
 * @return      [description]
 */
bool trie_find(TrieNode *trie, const char *str);

#endif