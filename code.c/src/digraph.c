#include "digraph.h"
#include <stddef.h>
#include <stdlib.h>

digraph *digraph_create() {
  digraph *g;
  int errno;
  g = (digraph *)malloc(sizeof(digraph));
  if (g == NULL) return NULL;
  g->n = 0;
  g->max_n = 0;
  g->adj_matrix = NULL;
  g->successors = NULL;
  g->predecessors = NULL;
  if (0 != (errno = digraph_resize(g, DIGRAPH_BUF_INC))) {
    return NULL;
  }
  return g;
}

void digraph_free(digraph *g) {
  free(g);
}
