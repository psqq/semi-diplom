#include "cxxtest/TestSuite.h"
#include "digraph.h"
#include <cstdlib>
#include <set>
using namespace std;

class MyTestSuite : public CxxTest::TestSuite {
public:
  void test_SimpleDigraph_Constructor() {
    SimpleDigraph g1;
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 0);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 0);
    SimpleDigraph g2(1);
    TS_ASSERT_EQUALS(g2.number_of_nodes(), 1);
    TS_ASSERT_EQUALS(g2.number_of_edges(), 0);
    int n = rand() % 100;
    SimpleDigraph g3(n);
    TS_ASSERT_EQUALS(g3.number_of_nodes(), n);
    TS_ASSERT_EQUALS(g3.number_of_edges(), 0);
  }

  void test_SimpleDigraph_METHODS_add_node() {
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

  void test_SimpleDigraph_METHODS_add_edge_AND_is_edge() {
    SimpleDigraph g1(5);
    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(3, 4);
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 5);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 3);
    int n = 5 + rand() % 10, m = rand() % n;
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      edges.emplace(rand() % n, rand() % n);
    }
    m = edges.size();
    SimpleDigraph g2(n);
    for (auto &p : edges) {
      g2.add_edge(p.first, p.second);
    }
    TS_ASSERT_EQUALS(g2.number_of_nodes(), n);
    TS_ASSERT_EQUALS(g2.number_of_edges(), m);
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        TS_ASSERT_EQUALS(g2.is_edge(u, v),
                         edges.find(make_pair(u, v)) != edges.end());
      }
    }
  }
};
