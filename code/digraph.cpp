#include "digraph.h"

void digraph::resize(int new_n) {
  n = new_n;
  adj_list.resize(n);
  for (auto v : adj_list) {
    v.clear();
  }
}
void digraph::load(string file_name) {
  ifstream fin(file_name);
  string line;
  getline(fin, line);
  istringstream iss(line);
  iss >> n;
  resize(n);
  while (!fin.eof()) {
    getline(fin, line);
    if (line.empty()) continue;
    istringstream iss(line);
    char c;
    iss >> c;
    int v, u;
    if (c == 'l') {
      iss >> v;
      while (iss >> u) add_edge(v, u);
    } else if (c == 'p') {
      iss >> v;
      while (iss >> u) {
        add_edge(v, u);
        v = u;
      }
    }
  }
}
digraph::digraph(string fn) {
  load(fn);
}
digraph::digraph(int an) : n(an) {
  adj_list.resize(n);
}
int digraph::count_vertices() {
  return n;
}
bool digraph::is_edge(int a, int b) {
  assert(a < n);
  for (auto v : adj_list[a]) {
    if (v == b) return true;
  }
  return false;
}
void digraph::add_edge(int a, int b) {
  assert(a < n && b < n);
  if (is_edge(a, b)) return;
  adj_list[a].push_back(b);
}
vector<pair<int, int>> digraph::edges() {
  vector<pair<int, int>> es;
  for (int v = 0; v < n; v++) {
    for (int u : adj_list[v]) {
      es.push_back(make_pair(v, u));
    }
  }
  return es;
}
void digraph::print() {
  cout << "Count of vertices: " << n << '\n';
  cout << "Degree of vertices:\n";
  for (int v = 0; v < n; v++) {
    cout << "\tdeg(" << v << ") = " << degree(v) << endl;
  }
  cout << "Edges:\n";
  for (int v = 0; v < n; v++) {
    for (int u : adj_list[v]) {
      cout << '\t' << v << " -> " << u << '\n';
    }
  }
}
int digraph::degree(int v) {
  return adj_list[v].size();
}
