#include "digraph.h"
#include "exceptions.h"
#include <algorithm>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

SimpleDigraph::SimpleDigraph(int an) { resize(an); }

void SimpleDigraph::resize(int new_n) {
  if (new_n < 0) {
    throw SimpleDigraphException(this, "The size can not be negative!");
  }
  n = new_n;
  if (new_n > max_n) {
    int new_max_n = max(max_n + BUFFER_INCREASE, new_n);
    if (new_max_n > buffer_limit) {
      throw SimpleDigraphBufferLimitException(this, max_n, new_max_n,
                                              buffer_limit);
    }
    max_n = new_max_n;
  }
  if (adj_matrix.size() != max_n) {
    adj_matrix.resize(max_n);
    for (int i = 0; i < max_n; i++)
      adj_matrix[i].resize(max_n);
  }
}

int SimpleDigraph::add_node() {
  n++;
  resize(n);
  return n - 1;
}

bool SimpleDigraph::is_node_exist(int v) { return 0 <= v && v < n; }

void SimpleDigraph::throw_exception_if_node_does_not_exist(int v) {
  if (!is_node_exist(v)) {
    throw SimpleDigraphNodeDoesNotExistEception(this, v);
  }
}

void SimpleDigraph::add_edge(int u, int v) {
  throw_exception_if_node_does_not_exist(u);
  throw_exception_if_node_does_not_exist(v);
  adj_matrix[u][v] = 1;
}


void SimpleDigraph::add_edges(vector<pair<int, int>> edges) {
  for (auto &p : edges) {
    add_edge(p.first, p.second);
  }
}

bool SimpleDigraph::is_edge(int u, int v) {
  throw_exception_if_node_does_not_exist(u);
  throw_exception_if_node_does_not_exist(v);
  return adj_matrix[u][v];
}

vector<int> SimpleDigraph::successsors(int u) {
  vector<int> res;
  for (int v = 0; v < n; v++) {
    if (adj_matrix[u][v])
      res.push_back(v);
  }
  return res;
}

vector<int> SimpleDigraph::predecessors(int u) {
  vector<int> res;
  for (int v = 0; v < n; v++) {
    if (adj_matrix[v][u])
      res.push_back(v);
  }
  return res;
}

int SimpleDigraph::number_of_nodes() { return n; }

int SimpleDigraph::number_of_edges() {
  int m = 0;
  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      if (adj_matrix[u][v])
        m++;
    }
  }
  return m;
}

bool SimpleDigraph::is_tree_with_root(int root) {
  if (number_of_nodes() - 1 != number_of_edges()) return false;
  queue<int> q;
  vector<bool> used(n);
  q.push(root);
  while (!q.empty()) {
    int w = q.front();
    q.pop();
    used[w] = true;
    for (int i = 0; i < n; i++) {
      if (adj_matrix[w][i] && !used[i]) {
        q.push(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) return false;
  }
  return true;
}

int SimpleDigraph::shortest_path_length(int u, int v) {
  queue<pair<int, int>> q;
  vector<bool> used(n);
  q.emplace(u, 0);
  while (!q.empty()) {
    int w, d;
    tie(w, d) = q.front();
    q.pop();
    used[w] = true;
    if (w == v)
      return d;
    for (int i = 0; i < n; i++) {
      if (adj_matrix[w][i] && !used[i]) {
        q.emplace(i, d + 1);
      }
    }
  }
  throw SimpleDigraphPathDontFoundException(this, u, v);
}
