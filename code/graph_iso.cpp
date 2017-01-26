#include <bits/stdc++.h>
#include "digraph.h"
using namespace std;

bool is_iso(digraph g1, digraph g2) {
  if (g1.count_vertices() != g2.count_vertices()) {
    return false;
  }
}

int main() {
  digraph g("1.digraph");
  g.print();
}
