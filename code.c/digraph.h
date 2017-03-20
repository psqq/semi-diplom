#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdint.h>

struct digraph {
  int_fast8_t *adj_matrix = NULL;
  int *successors = NULL, *predecessors = NULL;
};

digraph *digraph_create(int n);

#endif /* end of include guard: DIGRAPH_H */
