#include "semiiso.h"
#include <set>
using namespace std;

template <class T> Digraph<T> to_digraph(Semilattice<T> s) {
  int n = s.size();
  T root = *begin(s.elements());
  Digraph<T> g(n);
  for (T &el : s.elements()) {
    g.add_node(el);
    root = s.inf(root, el);
  }
  set<T> level = {root};
  while (level.size() > 0) {
    set<T> new_level;
    for (T &x : level) {
      for (T &y : s.elements()) {
        if (y != x && s.inf(x, y) == x) {
          bool flag = true;
          for (T &z : s.elements()) {
            if (z != x && z != y && x == s.inf(x, z) && z == s.inf(z, y)) {
              flag = false;
              break;
            }
          }
          if (flag) {
            g.add_edge(x, y);
            new_level.add(y);
          }
        }
      }
    }
  }
  return g;
}

template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2) {
  Digraph<T> g1 = to_digraph(s1), g2 = to_digraph(s1);
  return false;
}
