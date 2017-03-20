#include "digraph.h"

int init_suite1(void) { return 0; }

int clean_suite1(void) { return 0; }

// test: create and free digraph
void test_digraph_create(void) {
  digraph *g = digraph_create(0);
  CU_ASSERT(g != NULL);
  digraph_free(g);
}
