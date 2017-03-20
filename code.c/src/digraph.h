#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdint.h>

typedef struct digraph {
  int n;
  int_fast8_t *adj_matrix;
  int *successors, *predecessors;
} digraph;

digraph *digraph_create(int n);
void digraph_free(digraph *g);

#endif /* end of include guard: DIGRAPH_H */
