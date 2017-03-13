#include "cxxtest/TestSuite.h"
#include "digraph.h"
#include "exceptions.h"
#include "semiiso.h"
#include "semilattice.h"
#include <cstdlib>
#include <set>
using namespace std;

class MyTestSuite : public CxxTest::TestSuite {
public:
  //----------------------------------------------------------------------------
  // SIMPLE DIGRAPH TESTS
  //----------------------------------------------------------------------------
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

  void test_SimpleDigraph_METHODS_successsors() {
    SimpleDigraph g1(5);
    g1.add_edges({{1, 2}, {1, 4}, {0, 1}});
    auto v = g1.successors(1);
    vector<int> ans = {2, 4};
    // for (auto x : v) cout << endl << x << endl;
    TS_ASSERT(v.size() == ans.size() && equal(v.begin(), v.end(), ans.begin()));
  }

  void test_SimpleDigraph_METHODS_predecessors() {
    SimpleDigraph g1(5);
    g1.add_edges({{1, 2}, {1, 4}, {0, 1}, {3, 1}});
    auto v = g1.predecessors(1);
    vector<int> ans = {0, 3};
    // for (auto x : v) cout << endl << x << endl;
    TS_ASSERT(v.size() == ans.size() && equal(v.begin(), v.end(), ans.begin()));
  }

  void test_SimpleDigraph_METHODS_shortest_path_length() {
    SimpleDigraph g1(5);
    g1.add_edges({{1, 2}, {2, 3}});
    TS_ASSERT_EQUALS(g1.shortest_path_length(1, 1), 0);
    TS_ASSERT_EQUALS(g1.shortest_path_length(1, 2), 1);
    TS_ASSERT_EQUALS(g1.shortest_path_length(1, 3), 2);
    bool not_found = false;
    try {
      g1.shortest_path_length(3, 1);
    } catch (PathDontFoundException<int> &e) {
      not_found = true;
    }
    TS_ASSERT(not_found);
    not_found = false;
    try {
      g1.shortest_path_length(0, 4);
    } catch (PathDontFoundException<int> &e) {
      not_found = true;
    }
    TS_ASSERT(not_found);
  }

  void test_SimpleDigraph_METHODS_is_tree_with_root() {
    SimpleDigraph g1(3);
    g1.add_edges({{0, 1}, {0, 2}});
    TS_ASSERT(g1.is_tree_with_root(0));
    SimpleDigraph g2(3);
    g2.add_edges({{0, 1}, {2, 1}});
    TS_ASSERT(!g2.is_tree_with_root(0));
    TS_ASSERT(!g2.is_tree_with_root(1));
    TS_ASSERT(!g2.is_tree_with_root(2));
  }

  //----------------------------------------------------------------------------
  // DIGRAPH<T> DIGRAPH TESTS
  //----------------------------------------------------------------------------
  void test_Digraph_Constructor() {
    Digraph<int> g1;
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 0);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 0);
    Digraph<string> g2;
    g2.add_node("a");
    TS_ASSERT_EQUALS(g2.number_of_nodes(), 1);
    TS_ASSERT_EQUALS(g2.number_of_edges(), 0);
    int n = rand() % 100;
    Digraph<int> g3;
    for (int i = 0; i < n; i++)
      g3.add_node(i);
    TS_ASSERT_EQUALS(g3.number_of_nodes(), n);
    TS_ASSERT_EQUALS(g3.number_of_edges(), 0);
  }

  void test_Digraph_METHODS_add_edge_AND_is_edge() {
    Digraph<int> g1;
    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    g1.add_edge(3, 4);
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 5);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 3);
    Digraph<int> g2;
    int n = 5 + rand() % 10, m = rand() % n;
    for (int i = 0; i < n; i++)
      g2.add_node(i);
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      edges.emplace(rand() % n, rand() % n);
    }
    m = edges.size();
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

  void test_Digraph_METHODS_successsors() {
    Digraph<int> g1;
    g1.add_edges({{1, 2}, {1, 4}, {0, 1}});
    auto v = g1.successors(1);
    vector<int> ans = {2, 4};
    // for (auto x : v) cout << endl << x << endl;
    TS_ASSERT(v.size() == ans.size() && equal(v.begin(), v.end(), ans.begin()));
  }

  void test_Digraph_METHODS_predecessors() {
    Digraph<int> g1;
    g1.add_edges({{1, 2}, {1, 4}, {0, 1}, {3, 1}});
    auto v = g1.predecessors(1);
    vector<int> ans = {0, 3};
    // for (auto x : v) cout << endl << x << endl;
    TS_ASSERT(v.size() == ans.size() && equal(v.begin(), v.end(), ans.begin()));
  }

  void test_Digraph_METHODS_shortest_path_length() {
    Digraph<int> g1;
    g1.add_nodes({0, 4});
    g1.add_edges({{1, 2}, {2, 3}});
    TS_ASSERT_EQUALS(g1.shortest_path_length(1, 1), 0);
    TS_ASSERT_EQUALS(g1.shortest_path_length(1, 2), 1);
    TS_ASSERT_EQUALS(g1.shortest_path_length(1, 3), 2);
    bool not_found = false;
    try {
      g1.shortest_path_length(3, 1);
    } catch (PathDontFoundException<int> &e) {
      not_found = true;
    }
    TS_ASSERT(not_found);
    not_found = false;
    try {
      g1.shortest_path_length(0, 4);
    } catch (PathDontFoundException<int> &e) {
      not_found = true;
    }
    TS_ASSERT(not_found);
  }

  void test_Digraph_METHODS_is_tree_with_root() {
    Digraph<int> g1;
    g1.add_edges({{0, 1}, {0, 2}});
    TS_ASSERT(g1.is_tree_with_root(0));
    Digraph<int> g2;
    g2.add_edges({{0, 1}, {2, 1}});
    TS_ASSERT(!g2.is_tree_with_root(0));
    TS_ASSERT(!g2.is_tree_with_root(1));
    TS_ASSERT(!g2.is_tree_with_root(2));
  }

  //----------------------------------------------------------------------------
  // SIMPLE SEMILATTICE TESTS
  //----------------------------------------------------------------------------
  void test_SimpleSemilattice_Constructor() {
    SimpleSemilattice s(5);
    TS_ASSERT(s.is_valid());
  }

  //----------------------------------------------------------------------------
  // SEMILATTICE<T> TESTS
  //----------------------------------------------------------------------------
  void test_Semilattice_from_string() {
    Semilattice<int> s1;
    s1.from_string("0");
    TS_ASSERT_EQUALS(s1.size(), 1);
    TS_ASSERT_EQUALS(s1.inf(0, 0), 0);
    Semilattice<string> s2;
    s2.from_string("a");
    TS_ASSERT_EQUALS(s2.size(), 1);
    TS_ASSERT_EQUALS(s2.inf("a", "a"), "a");
    Semilattice<int> s3;
    // s3.from_string("0 0 0 1");
    s3.from_string(R"(
      0 0
      0 1
    )");
    TS_ASSERT_EQUALS(s3.size(), 2);
    TS_ASSERT_EQUALS(s3.inf(0, 0), 0);
    TS_ASSERT_EQUALS(s3.inf(0, 1), 0);
    TS_ASSERT_EQUALS(s3.inf(1, 0), 0);
    TS_ASSERT_EQUALS(s3.inf(1, 1), 1);
    Semilattice<string> s4;
    // s4.from_string("a b b b");
    s4.from_string(R"(
      a b
      b b
    )");
    TS_ASSERT_EQUALS(s4.size(), 2);
    TS_ASSERT_EQUALS(s4.inf("a", "a"), "a");
    TS_ASSERT_EQUALS(s4.inf("a", "b"), "b");
    TS_ASSERT_EQUALS(s4.inf("b", "a"), "b");
    TS_ASSERT_EQUALS(s4.inf("b", "b"), "b");
  }

  //----------------------------------------------------------------------------
  // SEMIISO MODULE TESTS
  //----------------------------------------------------------------------------
  void test_FUNCTION_to_digraph() {
    Semilattice<int> s1;
    s1.from_string(R"(
      0 0
      0 1
    )");
    Digraph<int> g1 = to_digraph(s1);
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 2);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 1);
    TS_ASSERT(g1.is_edge(0, 1));
    TS_ASSERT(!g1.is_edge(1, 0));
  }

  void test_FUNCTION_inf_for_digraph() {
    Semilattice<int> s1;
    s1.from_string(R"(
      0 0 0 0
      0 1 1 1
      0 1 2 1
      0 1 1 3
    )");
    TS_ASSERT(s1.is_valid());
    Digraph<int> g1 = to_digraph(s1);
    TS_ASSERT_EQUALS(g1.number_of_nodes(), 4);
    TS_ASSERT_EQUALS(g1.number_of_edges(), 3);
    int n = s1.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        TS_ASSERT_EQUALS(inf_for_digraph(g1, i, j), s1.inf(i, j));
      }
    }
  }

  void test_FUNCTION_to_semi() {
    Digraph<int> g1;
    g1.add_edges({{0, 1}, {1, 2}, {1, 3}});
    Semilattice<int> s1 = to_semi(g1);
    TS_ASSERT(s1.is_valid());
    TS_ASSERT_EQUALS(s1.size(), 4);
    int n = g1.number_of_nodes();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        TS_ASSERT_EQUALS(inf_for_digraph(g1, i, j), s1.inf(i, j));
      }
    }
  }

  void test_FUNCTION_tree_is_isomorphic() {
    Digraph<int> g1, g2;
    g1.add_edges({{0, 1}, {1, 2}, {1, 3}});
    g2.add_edges({{7, 19}, {19, 101}, {19, 1}});
    TS_ASSERT(tree_is_isomorphic(g1, g2));
    Digraph<int> g3, g4;
    g3.add_edges({{0, 1}, {1, 2}, {1, 3}, {2, 5}});
    g4.add_edges({{7, 19}, {19, 101}, {19, 1}, {19, 200}});
    TS_ASSERT(!tree_is_isomorphic(g3, g4));
  }

  void test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices() {
    Semilattice<string> s1, s2;
    s1.from_string("0");
    s2.from_string("a");
    TS_ASSERT(is_isomorphic(s1, s1));
    TS_ASSERT(is_isomorphic(s2, s2));
    TS_ASSERT(is_isomorphic(s1, s2));
    TS_ASSERT(is_isomorphic(s2, s1));
    Semilattice<string> s3, s4;
    s3.from_string(R"(
      0 0
      0 1
    )");
    s4.from_string(R"(
      0 1
      1 1
    )");
    TS_ASSERT(is_isomorphic(s3, s3));
    TS_ASSERT(is_isomorphic(s3, s4));
    TS_ASSERT(is_isomorphic(s4, s3));
    TS_ASSERT(is_isomorphic(s4, s4));
  }

  void test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices() {
    Semilattice<int> s1, s2;
    s1.from_string(R"(
      0 0 0 0
      0 1 0 1
      0 0 2 2
      0 1 2 3
    )");
    Digraph<int> g1;
    g1.add_edges({{0, 1}, {0, 2}, {1, 3}, {2, 3}});
    s2 = to_semi(g1);
    TS_ASSERT(is_isomorphic(s1, s2));
  }
};
