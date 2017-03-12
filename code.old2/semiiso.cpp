#include "semiiso.h"
#include <set>
using namespace std;

template <class T> Digraph<T> to_digraph(Semilattice<T> s) {
  int n = s.size();
  auto elems = s.elements();
  T root = *begin(elems);
  Digraph<T> g(n);
  for (T &el : elems) {
    g.add_node(el);
    root = s.inf(root, el);
  }
  set<T> level = {root};
  while (level.size() > 0) {
    set<T> new_level;
    for (T &x : level) {
      for (T &y : elems) {
        if (y != x && s.inf(x, y) == x) {
          bool flag = true;
          for (T &z : elems) {
            if (z != x && z != y && x == s.inf(x, z) && z == s.inf(z, y)) {
              flag = false;
              break;
            }
          }
          if (flag) {
            g.add_edge(x, y);
            new_level.add(y);
          }
        }
      }
    }
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

template <class T> inf_for_digraph(Digraph<T> g, T u, T v) {
  T root = find_root(g);
  int du = g.shortest_path_length(root, u);
  int dv = g.shortest_path_length(root, v);
  set<T> us = {u}, vs = {v};
  bool flag = false;
  while (1) {
    while (len(us) > 0 && (flag || du > dv)) {
      set<T> new_us;
      for (T &x : us) {
        auto p = g.predecessors(x);
        new_us.insert(begin(p), end(p));
      }
      us = new_us;
      du--;
      flag = false;
    }
    while (len(vs) > 0 && dv > du) {
      set<T> new_vs;
      for (T &x : vs) {
        auto p = g.predecessors(x);
        new_vs.insert(begin(p), end(p));
      }
      vs = new_vs;
      dv--;
      flag = false;
    }
    if (len(vs) == 0 || len(us) == 0) {
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

template <class T> Semilattice<T> to_semi(Digraph<T> g) {
  Semilattice<T> s;
  s.add_elements(g.nodes());
  for (T &v : g.nodes()) {
    for (T &u : g.nodes()) {
    s.set_inf(inf_for_digraph(g, v, u);
    }
  }
  return s;
}

template <class T> string encode_tree(Digraph<T> g) {
  if (g.number_of_nodes() == 0) {
    return "";
  }
  T root = find_root(g);
  auto go = [&](T v) -> string {
    string s = "0";
    for (T &u : g.successors()) {
      s += go(u);
    }
    return s + "1";
  };
  return go(root);
}

template <class T> tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2) {
  return encode_tree(g1) == encode_tree(g2);
}

template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2) {
  Digraph<T> g1 = to_digraph(s1), g2 = to_digraph(s1);
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
    tree_is_isomorphic(g1, g2);
  }
  return false;
}
