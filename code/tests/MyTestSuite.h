#include "cxxtest/TestSuite.h"
#include "digraph.h"

class MyTestSuite : public CxxTest::TestSuite {
public:
  void test_SimpleDigraph() {
    SimpleDigraph g1;
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 0);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 0);
    SimpleDigraph g2(2);
    TS_ASSERT_EQUALS(g2.number_of_nodes(), 2);
    TS_ASSERT_EQUALS(g2.number_of_edges(), 0);
  }
  void test_SimpleDigraph_add_node() {
    SimpleDigraph g1;
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 0);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 0);
    int v = g1.add_node();
    TS_ASSERT_EQUALS(v, 0);
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 1);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 0);
    v = g1.add_node();
    TS_ASSERT_EQUALS(v, 1);
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 2);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 0);
  }
};
