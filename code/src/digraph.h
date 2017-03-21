#ifndef DIGRAPH_H
#define DIGRAPH_H

#include "exceptions.h"
#include <iostream>
#include <map>
#include <set>
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
  std::vector<int> successors(int u);
  std::vector<int> predecessors(int u);
  int number_of_nodes();
  int number_of_edges();
  bool is_tree_with_root(int root);
  int shortest_path_length(int u, int v, bool undirected);
  int shortest_path_length(int u, int v);
  bool is_node_exist(int v);
  void throw_exception_if_node_does_not_exist(int u);
};

template <class T> class Digraph {
  std::set<T> _elements;
  std::map<T, int> id;
  std::vector<T> name;
  SimpleDigraph simple_digraph;

public:
  Digraph();
  void add_node(T v);
  void add_nodes(std::vector<T> nodes);
  std::set<T> nodes();
  bool is_node(T v);
  void add_edge(T u, T v);
  bool is_edge(T u, T v);
  void add_edges(std::vector<std::pair<T, T>> edges);
  std::vector<T> successors(T v);
  std::vector<T> predecessors(T v);
  int number_of_nodes();
  int number_of_edges();
  bool is_tree_with_root(T root);
  int shortest_path_length(T u, T v, bool undirected);
  int shortest_path_length(T u, T v);
  SimpleDigraph get_simple_digraph() { return simple_digraph; }
  T get_name_by_id(int aid) {
    if (aid < 0 || aid >= number_of_nodes()) {
      throw GeneralException(
          "Digraph: get_name_by_id: Node for this id don't exist.");
    }
    return name[aid];
  }
  static Digraph<T> from_stream(std::istream &is);
  static Digraph<T> from_string(std::string str);
  static Digraph<T> from_file(std::string filename);
};

template class Digraph<std::string>;
template class Digraph<int>;

#endif /* end of include guard: DIGRAPH_H */
