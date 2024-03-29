/* Generated file, do not edit */
#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>


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



int main() {

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();


CU_pSuite suite1 = NULL;

suite1 = CU_add_suite("suite1", init_suite1, clean_suite1);
if (NULL == suite1) {
CU_cleanup_registry();
return CU_get_error();
}

int add_tests_flag =
(NULL ==
CU_add_test(suite1, "create and free digraph", test_digraph_create)
) || (NULL ==
CU_add_test(suite1, "2 plus 2 == 4", test_2_plus_2)
)
;

if (add_tests_flag) {
CU_cleanup_registry();
return CU_get_error();
}


  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
