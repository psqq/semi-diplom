#ifndef DIGRAPHISO_H
#define DIGRAPHISO_H

#include "digraph.h"
#include <functional>
#include <map>
#include <set>
#include <vector>
using namespace std;

template <class T, class U> class DigraphIso2 {
  Digraph<T> orig_g1;
  Digraph<U> orig_g2;
  SimpleDigraph g1, g2;
  std::set<int> vertices;
  int n = -1;    // количество вершин в графах g1, g2
  int g1_k = -1; // подмножество вершин g1 {0, 1, ..., g1_k}
  std::set<int> g2_s; // Подмножество вершин графа g2, которое
  // соотвествует множеству вершин грфафа g1 {0, 1, ..., g1_k}
  vector<int> f; // биекция: i (вершина g1) -> f[i] (вершина g2)
  int ans = -1;
  bool match(int v);
  void go();
  std::map<T, U> f2;
  std::map<string, vector<U>> inv3_f;
  Inv3<T> g1_inv3;
  Inv3<U> g2_inv3;

public:
  DigraphIso(Digraph<T> ag1, Digraph<U> ag2);
  bool is_iso();
  void set_initial_biection(std::map<T, U> b) {
    initial_bijection = b;
    ans = -1;
  }
  std::map<T, U> get_biection();
};

template class DigraphIso2<std::string, std::string>;
template class DigraphIso2<std::string, int>;
template class DigraphIso2<int, std::string>;
template class DigraphIso2<int, int>;

#endif /* end of include guard: DIGRAPHISO_H */
