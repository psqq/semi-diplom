#ifndef INV3_H
#define INV3_H

#include "digraph.h"
#include "semiiso.h"
#include <map>
#include <sstream>
#include <string>

template <class T> class Inv3 {
  bool is_empty = false;
  Digraph<T> g;
  T root;
  std::vector<T> leaves;
  void find_leaves();
  std::map<T, std::string> inv3_for_node;
  std::string full_inv3;
  std::string compute_inv3_for_node(T v);
  std::string compute_full_inv3();

public:
  Inv3();
  explicit Inv3(Digraph<T> ag);
  std::string get_inv3_for_node(T v);
  std::string get_full_inv3();
};

template class Inv3<int>;
template class Inv3<std::string>;

#endif /* end of include guard: INV3_H */
