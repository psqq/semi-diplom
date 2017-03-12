#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <map>
using namespace std;

template<class T>
class Digraph {
  std::set<T> nodes;
  std::map<std::map<T, bool>> adj_matrix;
public:
  void add_node(T a);
  void add_nodes(set<T> ns);
};

#endif /* end of include guard: DIGRAPH_H */
