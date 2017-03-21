#ifndef SEMIISO_H
#define SEMIISO_H

#include "digraph.h"
#include "semilattice.h"
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <vector>

template <class T> Digraph<T> to_digraph(Semilattice<T> s);
template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2);
template <class T> T inf_for_digraph(Digraph<T> g, T u, T v);
template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2);
template <class T> Semilattice<T> to_semi(Digraph<T> g);
template <class T> std::string encode_tree(Digraph<T> g);
template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2);
template <class T>
std::vector<std::set<T>> find_branches_of_digraph(Digraph<T> g);
template <class T> std::set<T> find_cyclic_vers(Digraph<T> g);
template <class T> Digraph<T> find_subgraph(Digraph<T> g, std::set<T> vers);
template <class T>
std::pair<Digraph<T>, Digraph<T>> find_G1_and_G2_graphs(Digraph<T> g);
template <class T> T find_root(Digraph<T> g);

#endif /* end of include guard: SEMIISO_H */
