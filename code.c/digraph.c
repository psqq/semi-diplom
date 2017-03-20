#include "digraph.h"

digraph *digraph_create() {
  digraph *g = (digraph *)malloc(sizeof(digraph));
  return g;
}
