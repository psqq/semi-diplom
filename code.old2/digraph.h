#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include <map>
#include <vector>

class SimpleDigraph {
  static const int BUFFER_INCREASE = 100;
  int buffer_limit = 100000;
  int n = 0, max_n = 0;
  std::vector<std::vector<int>> adj_matrix;
  void resize(int n);

public:
  SimpleDigraph(int n = 0);
  int add_node();
  void add_edge(int u, int v);
  void add_edges(std::vector<std::pair<int, int>> edges);
  bool is_edge(int u, int v);
  std::vector<int> successsors(int u);
  std::vector<int> predecessors(int u);
  int number_of_nodes();
  int number_of_edges();
  bool is_tree_with_root(int root);
  int shortest_path_length(int u, int v);
  bool is_node_exist(int v);
  void throw_exception_if_node_does_not_exist(int u);
};

template <typename T> class Digraph {
  std::map<T, bool> _is_node;
  std::map<T, int> id;
  SimpleDigraph simple_digraph;

public:
  Digraph();
  void add_node(T v);
  bool is_node(T v);
  bool add_edge(T u, T v);
  void load_from_stream(std::istream &is);
  void from_string(std::string str);
  void load_from_file(std::string filename);
  int add_node();
  bool add_edge(int u, int v);
  bool is_edge(int u, int v);
  std::vector<int> successsors();
  std::vector<int> predecessors();
  int number_of_nodes();
  bool is_tree();
  int shortest_path_length(T u, T v);
};

#endif /* end of include guard: DIGRAPH_H */
