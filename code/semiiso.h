#ifndef SEMIISO_H
#define SEMIISO_H

#include "digraph.h"
#include "semilattice.h"
#include <string>

template <class T> Digraph<T> to_digraph(Semilattice<T> s);
template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2);
template <class T> T inf_for_digraph(Digraph<T> g, T u, T v);
template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2);
template <class T> Semilattice<T> to_semi(Digraph<T> g);
template <class T> std::string encode_tree(Digraph<T> g);
template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2);

// extern template bool is_isomorphic<std::string>(Semilattice<std::string> s1,
//                                                 Semilattice<std::string> s2);
//
// extern template bool is_isomorphic<int>(Semilattice<int> s1,
//                                         Semilattice<int> s2);

#endif /* end of include guard: SEMIISO_H */
