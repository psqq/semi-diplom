#ifndef TREEISO_H
#define TREEISO_H

#include "digraph.h"
#include <map>
#include <string>


template <class T> class TreeEncoder {
  Digraph<T> &g;
  std::map<T, std::string> s;
  std::pair<bool, T> r;
  void go();
  void go(const T &v);
  bool _good = false, computed = false;
public:
  TreeEncoder(Digraph<T> &ag);
  std::string code();
  std::string code_of_node(T v);
  bool good();
};


template <class T> class TreeIso {
  Digraph<T> &g1, &g2;
  TreeEncoder<T> e1, e2;
  std::map<T, T> f;
  int _is_iso = -1;
  bool f_computed = false;

public:
  TreeIso(Digraph<T> &ag1, Digraph<T> &ag2);
  bool is_iso();
  const std::map<T, T> &get_biection();
};

template class TreeIso<std::string>;
template class TreeIso<int>;

template class TreeEncoder<std::string>;
template class TreeEncoder<int>;

#endif /* end of include guard: TREEISO_H */
