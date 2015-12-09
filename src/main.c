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
#include <stdio.h>

/* Tries Headers */
#include <tries/trie/node.h>
#include <tries/trie/trie.h>

/* TST Headers */
#include <tries/tst/tst.h>

/* Benchmark */
#include <sys/time.h>
#include <sys/resource.h>

double get_time();
void gen_random(char *s, const int len);


int main(void)
{
  /* Benchmark variables */
  double start_time, end_time;

  /* Start Benchmark: Trie */
  start_time = get_time();
  printf("Iniciando testes com TRIE: \n");
  TrieNode *trie = create_trie_node();

  for (int i = 0; i < 1000000; i++)
  {
    int s = rand() % 10;
    char *t = malloc(s * sizeof(char));
    gen_random(t, s);
    trie_insert(trie, t);
  }
  end_time = get_time();
  printf("\t[TRIE] Tempo: %fs\n", end_time - start_time);
  /* End Benchmark: Trie */

  /* Start Benchmark: Ternary Search Tree */
  start_time = get_time();
  printf("\n\nIniciando testes com TST: \n");
  TST *tst = NULL;

  for (int i = 0; i < 1000000; i++)
  {
    int s = rand() % 10;
    char *t = malloc(s * sizeof(char));
    gen_random(t, s);
    tst_insert(tst, t);
  }
  end_time = get_time();
  printf("\t[TST] Tempo: %fs\n", end_time - start_time);
  /* End Benchmark: Ternary Search Tree */
  return 0;
}

double get_time()
{
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec*1e-6;
}

void gen_random(char *s, const int len) {
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; ++i)
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    s[len] = 0;
}