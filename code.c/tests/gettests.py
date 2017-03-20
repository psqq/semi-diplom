import os, re

def apath(*args):
    return os.path.abspath(os.path.join(*args))

dirname = apath(os.path.dirname(__file__))
print(dirname)

suite_files = [fn for fn in os.listdir(dirname) if 'suite' in fn]

add_test_template = """
CU_add_test({suite_name}, {msg}, {func_name})
"""

add_suite_template = """
  CU_pSuite {suite_name} = NULL;

  {suite_name} = CU_add_suite("{suite_name}", init_{suite_name}, clean_{suite_name});
  if (NULL == {suite_name}) {{
    CU_cleanup_registry();
    return CU_get_error();
  }}

  int add_tests_flag = {add_tests_flag};

  if (add_tests_flag) {{
    CU_cleanup_registry();
    return CU_get_error();
  }}
"""

complete_template = """// this file autogenerated by gettests.py
#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>

{suite_codes}

int main() {{

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  {all_suites}

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}}
"""

def read_suite(fn):
    fn_basename = os.path.basename(fn)
    suite_name, _ = os.path.splitext(fn_basename)
    with open(fn, "r") as f:
        lines = f.readlines()
    tests = []
    q = 0d
    for line in lines:
        m = re.match("// test:\s*(.*)", line)

        if "// test:" in line:
            print(line)
    res = {
        "code": "".join(lines),
        "suite_name": suite_name,
        "tests": tests,
    }
    print(suite_name) # os.path.basename(fn)
    return res

print(read_suite("/home/ps/sandbox/diplom/code.c/tests/suite1.c"))
