#ifndef DIGRAPHISO_H
#define DIGRAPHISO_H

#include "digraph.h"
#include <set>
#include <vector>
using namespace std;

class DigraphIso {
  digraph &g1, &g2;
  set<int> vertices;
  int n = -1; // количество вершин в графах g1, g2
  int g1_k = -1; // подмножество вершин g1 {0, 1, ..., g1_k}
  set<int> g2_s; // Подмножество вершин графа g2, которое
  // соотвествует множеству вершин грфафа g1 {0, 1, ..., g1_k}
  vector<int> f; // биекция: i (вершина g1) -> f[i] (вершина g2)
  int ans = -1;
  bool match(int v);
  void go();
public:
  DigraphIso(digraph &ag1, digraph &ag2);
  bool is_iso();
  vector<int> biection();
};

#endif /* end of include guard: DIGRAPHISO_H */
