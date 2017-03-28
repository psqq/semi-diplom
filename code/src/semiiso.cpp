#include "digraphiso.h"
#include "exceptions.h"
#include "semiiso.h"
#include "inv3.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <tuple>
#include <iostream>
#include <ctime>
#include <fstream>
#include "main.h"
using namespace std;

template <class T> Digraph<T> to_digraph(Semilattice<T> s) {
  // int n = s.size();
  auto elems = s.elements();
  T root = *begin(elems);
  Digraph<T> g;
  for (T el : elems) {
    g.add_node(el);
    root = s.inf(root, el);
  }
  set<T> level = {root};
  while (level.size() > 0) {
    set<T> new_level;
    for (T x : level) {
      for (T y : elems) {
        if (y != x && s.inf(x, y) == x) {
          bool flag = true;
          for (T z : elems) {
            if (z != x && z != y && x == s.inf(x, z) && z == s.inf(z, y)) {
              flag = false;
              break;
            }
          }
          if (flag) {
            g.add_edge(x, y);
            new_level.insert(y);
          }
        }
      }
    }
    level = new_level;
  }
  return g;
}

template <class T> T find_root(Digraph<T> g) {
  if (g.number_of_nodes() == 0) {
    throw GeneralException("find_root: root don't found!");
  }
  T root = *begin(g.nodes());
  for (int i = 0; i < g.number_of_nodes(); i++) {
    auto p = g.predecessors(root);
    if (p.size() == 0)
      return root;
    root = *begin(p);
  }
  throw GeneralException("find_root: root don't found!");
}

template int inf_for_digraph(Digraph<int> g, int u, int v);
template string inf_for_digraph(Digraph<string> g, string u, string v);

template <class T> T inf_for_digraph(Digraph<T> g, T u, T v) {
  T root = find_root(g);
  int du = g.shortest_path_length(root, u);
  int dv = g.shortest_path_length(root, v);
  set<T> us = {u}, vs = {v};
  bool flag = false;
  while (1) {
    while (us.size() > 0 && (flag || du > dv)) {
      set<T> new_us;
      for (T x : us) {
        auto p = g.predecessors(x);
        new_us.insert(begin(p), end(p));
      }
      us = new_us;
      du--;
      flag = false;
    }
    while (vs.size() > 0 && dv > du) {
      set<T> new_vs;
      for (T x : vs) {
        auto p = g.predecessors(x);
        new_vs.insert(begin(p), end(p));
      }
      vs = new_vs;
      dv--;
      flag = false;
    }
    if (vs.size() == 0 || us.size() == 0) {
      throw GeneralException("inf_for_digraph: inf don't found!");
    }
    set<T> uv_intersection;
    set_intersection(begin(us), end(us), begin(vs), end(vs),
                     inserter(uv_intersection, uv_intersection.begin()));
    if (uv_intersection.size() > 1) {
      throw GeneralException("inf_for_digraph: inf don't found!");
    } else if (uv_intersection.size() == 1) {
      return *begin(uv_intersection);
    } else {
      flag = true;
    }
  }
}

template Semilattice<int> to_semi<int>(Digraph<int> g);
template Semilattice<string> to_semi<string>(Digraph<string> g);

template <class T> Semilattice<T> to_semi(Digraph<T> g) {
  Semilattice<T> s;
  s.add_elements(g.nodes());
  for (T v : g.nodes()) {
    for (T u : g.nodes()) {
      s.set_inf(v, u, inf_for_digraph(g, v, u));
    }
  }
  return s;
}

template <class T> string encode_tree(Digraph<T> g) {
  if (g.number_of_nodes() == 0) {
    return "";
  }
  T root = find_root(g);
  function<string(T)> go = [&](T v) -> string {
    string s = "0";
    for (T u : g.successors(v)) {
      s += go(u);
    }
    return s + "1";
  };
  return go(root);
}

template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2) {
  string s1 = encode_tree(g1);
  string s2 = encode_tree(g2);
  // cout << endl << s1 << endl << s2 << endl;
  return s1 == s2;
}

template <class T> vector<set<T>> find_branches_of_digraph(Digraph<T> g) {
  vector<set<T>> branches;
  T root = find_root(g);
  class A {
    map<T, set<T>> res;
    map<T, bool> used;
    Digraph<T> &g;
  public:
    explicit A(Digraph<T> &ag) : g(ag) {}
    set<T> operator() (T v) {
      if (used[v]) return res[v];
      set<T> t = {v}, t2;
      for (T u : g.successors(v)) {
        t2 = this->operator()(u);
        t.insert(t2.begin(), t2.end());
      }
      used[v] = true;
      res[v] = t;
      return t;
    }
  } vertexes_of_subgraph_with_root(g);
  // function<set<T>(T)> vertexes_of_subgraph_with_root = [&](T v) {
  //   set<T> t = {v}, t2;
  //   for (T u : g.successors(v)) {
  //     t2 = vertexes_of_subgraph_with_root(u);
  //     t.insert(t2.begin(), t2.end());
  //   }
  //   return t;
  // };
  for (T v : g.successors(root)) {
    auto t = vertexes_of_subgraph_with_root(v);
    vector<set<T>> new_branches;
    for (auto b : branches) {
      set<T> intersection_t_and_b;
      set_intersection(
          begin(t), end(t), begin(b), end(b),
          inserter(intersection_t_and_b, intersection_t_and_b.begin()));
      if (intersection_t_and_b.size() > 0) {
        t.insert(begin(b), end(b));
      } else {
        new_branches.push_back(b);
      }
    }
    new_branches.push_back(t);
    branches = new_branches;
  }
  for (auto &b : branches) {
    b.insert(root);
  }
  return branches;
}

template <class T> set<T> find_cyclic_vers(Digraph<T> g) {
  set<T> res;
  for (T v : g.nodes()) {
    if (g.predecessors(v).size() > 1) {
      res.insert(v);
    }
  }
  return res;
}

template <class T> Digraph<T> find_subgraph(Digraph<T> g, set<T> vers) {
  Digraph<T> subg;
  for (T u : vers) {
    subg.add_node(u);
    for (T v : vers) {
      if (g.is_edge(u, v)) {
        subg.add_edge(u, v);
      }
    }
  }
  return subg;
}

template <class T>
pair<Digraph<T>, Digraph<T>> find_G1_and_G2_graphs(Digraph<T> g) {
  auto branches = find_branches_of_digraph(g);
  auto cyclic_vers = find_cyclic_vers(g);
  set<T> G1_vers, G2_vers;
  for (auto b : branches) {
    set<T> t;
    set_intersection(begin(cyclic_vers), end(cyclic_vers), begin(b), end(b),
                     inserter(t, t.begin()));
    if (t.size() > 0) {
      G2_vers.insert(b.begin(), b.end());
    } else {
      G1_vers.insert(b.begin(), b.end());
    }
  }
  Digraph<T> G1 = find_subgraph(g, G1_vers);
  Digraph<T> G2 = find_subgraph(g, G2_vers);
  return {G1, G2};
}

template bool is_isomorphic<string>(Semilattice<string> s1,
                                    Semilattice<string> s2);

template bool is_isomorphic<int>(Semilattice<int> s1, Semilattice<int> s2);

template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2) {

  clock_t t;
  if (log_mode) {
    semi_log << "Проверка полурешеток s1 и s2 на изоморфизм." << endl;
    semi_log << "Полурешетка s1:\n" << s1.to_string();
    semi_log << "Полурешетка s2:\n" << s2.to_string();
    semi_log << "Преобразование полурешеток s1, s2 в графы g1, g2... ";
    t = clock();
  }

  Digraph<T> g1 = to_digraph(s1), g2 = to_digraph(s1);

  if (log_mode) {
    semi_log << ((float)(clock() - t) / CLOCKS_PER_SEC) << " sec." << endl;
  }

  int n = g1.number_of_nodes();
  if (n != g2.number_of_nodes() ||
      g1.number_of_edges() != g2.number_of_edges()) {
    return false;
  }
  T r1 = find_root(g1), r2 = find_root(g2);
  bool g1_is_tree = g1.is_tree_with_root(r1);
  if (g1_is_tree != g2.is_tree_with_root(r2)) {
    return false;
  }
  if (g1_is_tree) {
    return tree_is_isomorphic(g1, g2);
  }

#ifdef DEBUG_PRINTING_FOR_IS_ISOMORPHIC
  cout << ((float)(clock() - t) / CLOCKS_PER_SEC) << " sec." << endl;
  cout << "Build digraphs G1 and G2... ";
  t = clock();
#endif // DEBUG_PRINTING_FOR_IS_ISOMORPHIC

  Digraph<T> g1_G1, g1_G2, g2_G1, g2_G2;
  tie(g1_G1, g1_G2) = find_G1_and_G2_graphs(g1);
  tie(g2_G1, g2_G2) = find_G1_and_G2_graphs(g2);
  if (!tree_is_isomorphic(g1_G1, g2_G1) || !tree_is_isomorphic(g1_G2, g2_G2)) {
    return false;
  }

#ifdef DEBUG_PRINTING_FOR_IS_ISOMORPHIC
  cout << ((float)(clock() - t) / CLOCKS_PER_SEC) << " sec." << endl;
  cout << "Invariant 3... ";
  t = clock();
#endif // DEBUG_PRINTING_FOR_IS_ISOMORPHIC

  Inv3<T> inv3_for_g1_G2(g1_G2);
  Inv3<T> inv3_for_g2_G2(g2_G2);

#ifdef DEBUG_PRINTING_FOR_IS_ISOMORPHIC
  cout << ((float)(clock() - t) / CLOCKS_PER_SEC) << " sec." << endl;
  cout << "DigraphIso::is_iso... ";
  t = clock();
#endif // DEBUG_PRINTING_FOR_IS_ISOMORPHIC

  DigraphIso<T, T> digiso(g1_G2, g2_G2, [&](T v, T u) {
    return inv3_for_g1_G2.get_inv3_for_node(v) == inv3_for_g2_G2.get_inv3_for_node(u);
  });
  // digiso.set_initial_biection({{r1, r2}});
  bool res = digiso.is_iso();

#ifdef DEBUG_PRINTING_FOR_IS_ISOMORPHIC
  cout << ((float)(clock() - t) / CLOCKS_PER_SEC) << " sec." << endl;
  cout << "END OF is_isomorphic" << endl << endl;
#endif // DEBUG_PRINTING_FOR_IS_ISOMORPHIC

  return res;
}
