#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <stdint.h>

// public:
digraph *digraph_create(void);
void digraph_free(digraph *g);
void digraph_add_edge(int a, int b);
int digraph_number_of_nodes(digraph *g);

// private:
#define DIGRAPH_BUF_INC 100

typedef struct digraph {
  int n, sz;
  int_fast8_t *adj_matrix;
  int *successors, *predecessors;
} digraph;

int digraph_resize_bufer(digraph *g, int new_size);

#endif /* end of include guard: DIGRAPH_H */
