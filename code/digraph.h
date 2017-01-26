#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

class digraph {
  int n = 0;
  vector<vector<int>> adj_list;
  void resize(int new_n);
  void load(string file_name);
public:
  digraph(string fn);
  digraph(int an);
  int count_vertices();
  bool is_edge(int a, int b);
  void add_edge(int a, int b);
  vector<pair<int, int>> edges();
  void print();
  int degree(int v);
};

#endif /* end of include guard: GRAPH_H */
