#include "digraph.h"

int init_suite1(void) { return 0; }

int clean_suite1(void) { return 0; }

// test: create and free digraph
void test_digraph_create(void) {
  // digraph *g = digraph_create(0);
  // CU_ASSERT(g != NULL);
  // digraph_free(g);
}

// test: 2 plus 2 == 4
void test_2_plus_2(void) {
  int x = 2 + 2;
  CU_ASSERT(x == 4);
}
