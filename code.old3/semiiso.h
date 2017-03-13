#ifndef SEMIISO_H
#define SEMIISO_H

#include "digraph.h"
#include "semilattice.h"
#include <iterator>
#include <string>
#include <algorithm>

template <class T> Digraph<T> to_digraph(Semilattice<T> s);
template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2);
template <class T> T inf_for_digraph(Digraph<T> g, T u, T v);
template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2);
template <class T> Semilattice<T> to_semi(Digraph<T> g);
template <class T> std::string encode_tree(Digraph<T> g);
template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2);

template <class T>
class DigraphIso {
  Digraph<T> orig_g1, orig_g2;
  SimpleDigraph g1, g2;
  std::set<int> vertices;
  int n = -1;    // количество вершин в графах g1, g2
  int g1_k = -1; // подмножество вершин g1 {0, 1, ..., g1_k}
  std::set<int> g2_s; // Подмножество вершин графа g2, которое
  // соотвествует множеству вершин грфафа g1 {0, 1, ..., g1_k}
  std::vector<int> f; // биекция: i (вершина g1) -> f[i] (вершина g2)
  int ans = -1;
  bool match(int v) {
    // Подмножество g1 {0, 1, ..., g1_k - 1} изоморфно
    // подножеству графа g2 g2_s,
    // которое равно {f[0], f[1], ..., f[g1_k - 1]}
    // На данном шаге нужно проверить может ли подмножество g1
    // {0, 1, ..., g1_k - 1, g1_k} быть изоморфно
    // подмножеству g2 {f[0], f[1], ..., f[g1_k - 1], v}
    for (int u = 0; u < g1_k; u++) {
      if (g1.is_edge(u, g1_k) && !g2.is_edge(f[u], v)) {
        // cout << 1 << ": " << u << " " << g1_k << " "
        //      << f[u] << " " << v << endl;
        return false;
      }
      if (g1.is_edge(g1_k, u) && !g2.is_edge(v, f[u])) {
        // cout << 2 << endl;
        return false;
      }
    }
    return true;
  }
  void go() {
    // cout << "go begin\n";
    // cout << "g2_s: ";
    // for (int i : g2_s) cout << i << " ";
    // cout << endl;
    if (g2_s.size() == n) {
      ans = 1;
      return;
    }
    g1_k += 1;
    std::set<int> t;
    std::set_difference(vertices.begin(), vertices.end(), g2_s.begin(),
                        g2_s.end(), std::inserter(t, t.end()));
    // cout << "t: ";
    // for (int i : t) cout << i << " ";
    // cout << endl;
    for (int v : t) {
      if (ans >= 0)
        return;
      if (match(v)) {
        // cout << g1_k << " match " << v << endl;
        f[g1_k] = v;
        g2_s.insert(v);
        go();
        g2_s.erase(v);
      } else {
        // cout << g1_k << " don't match " << v << endl;
      }
    }
    g1_k -= 1;
  }

public:
  DigraphIso(Digraph<T> ag1, Digraph<T> ag2) : g1(ag1), g2(ag2) {}
  bool is_iso() {
    if (ans >= 0)
      return ans;
    n = g1.number_of_nodes();
    if (n != g2.number_of_nodes()) {
      return false;
    }
    f[find_root(g1)] = find_root(g2);
    for (int v : g1.nodes())
      vertices.insert(v);
    go();
    // cout << "ans " << ans << endl;
    if (ans < 0)
      ans = 0;
    return ans;
  }
  std::vector<int> get_biection() { return f; }
};

#endif /* end of include guard: SEMIISO_H */
