#include "semilattice.h"
#include "digraph.h"

bool is_isomorphic(Semilattice &s1, Semilattice &s2) {
  digraph g1 = s1.to_digraph();
  digraph g2 = s2.to_digraph();
}
