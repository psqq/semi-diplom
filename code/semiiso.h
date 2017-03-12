#ifndef SEMIISO_H
#define SEMIISO_H

#include "semilattice.h"
#include "digraph.h"

template <class T> Digraph<T> to_digraph(Semilattice<T> s);
template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2);

#endif /* end of include guard: SEMIISO_H */
