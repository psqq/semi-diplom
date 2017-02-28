#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

#include "semilattice.h"

class digraph {
  int n = 0; // количество вершин
  int root = 0; // корневая вершина
  vector<vector<int>> adj_list; // списки смежных вершин
  vector<vector<int>> adj_mat; // матрица смежности
  vector<vector<int>> input_vers;
  // Информация о графе полученная с помощью bfs алгоритма
  // расстояние от одной вершины до другой
  // без учета направлений ребер
  bool is_dists_finded = false;
  vector<vector<int>> dist;
  bool is_leaves_finded = false;
  vector<int> leaves;
  // Инвариант 3
  bool is_inv3_finded = false;
  vector<string> inv3;
  string inv3_full;
private:
  void resize(int new_n);
  void add_edge(int a, int b);
  void find_dists_from(int v);
  void find_dists();
  void find_leaves();
  void find_inv3();
  void update();
public:
  digraph(istream &is);
  digraph(string s);
  digraph(int an = 0);
  void load_from_file(string file_name);
  void load_from_stream(istream &is);
  int count_vertices();
  bool is_edge(int a, int b);
  vector<pair<int, int>> edges();
  void print();
  int degree(int v);
  vector<int> output_vertices(int k);
  int dist_to_root(int v);
  int inf(int u, int v);
  Semilattice to_semi();
};

#endif /* end of include guard: GRAPH_H */
