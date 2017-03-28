#include "digraph.h"
#include "exceptions.h"
#include "utils.h"
#include <algorithm>
#include <fstream>
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
    _shortest_path_length.resize(max_n);
    _undirected_shortest_path_length.resize(max_n);
    for (int i = 0; i < max_n; i++) {
      adj_matrix[i].resize(max_n);
      _shortest_path_length[i].resize(max_n, -1);
      _undirected_shortest_path_length[i].resize(max_n, -1);
      _shortest_path_length[i][i] = _undirected_shortest_path_length[i][i] = 0;
    }
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

vector<int> SimpleDigraph::successors(int u) {
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
  if (number_of_nodes() - 1 != number_of_edges())
    return false;
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
    if (!used[i])
      return false;
  }
  return true;
}

int SimpleDigraph::shortest_path_length(int u, int v, bool undirected) {
  if (undirected && _undirected_shortest_path_length[u][v] >= 0) {
    return _undirected_shortest_path_length[u][v];
  }
  if (undirected && _undirected_shortest_path_length[v][u] >= 0) {
    return _undirected_shortest_path_length[v][u];
  }
  if (!undirected && _shortest_path_length[u][v] >= 0) {
    return _shortest_path_length[u][v];
  }
  queue<pair<int, int>> q;
  vector<bool> used(n);
  q.emplace(u, 0);
  while (!q.empty()) {
    int w, d;
    tie(w, d) = q.front();
    q.pop();
    used[w] = true;
    if (undirected) {
      _undirected_shortest_path_length[u][w] =
          _undirected_shortest_path_length[w][u] = d;
    } else {
      _shortest_path_length[u][w] = d;
    }
    if (w == v) {
      return d;
    }
    for (int i = 0; i < n; i++) {
      if ((adj_matrix[w][i] || (undirected && adj_matrix[i][w])) && !used[i]) {
        q.emplace(i, d + 1);
      }
    }
  }
  throw PathDontFoundException<int>(u, v);
}

int SimpleDigraph::shortest_path_length(int u, int v) {
  return shortest_path_length(u, v, false);
}

template <class T> Digraph<T>::Digraph() {}

template <class T> void Digraph<T>::add_node(T v) {
  if (is_node(v))
    return;
  id[v] = simple_digraph.add_node();
  name.push_back(v);
  _elements.insert(v);
}

template <class T> bool Digraph<T>::is_node(T v) {
  return _elements.find(v) != _elements.end();
}

template <class T> void Digraph<T>::add_nodes(vector<T> nodes) {
  for (T v : nodes)
    add_node(v);
}

template <class T> set<T> Digraph<T>::nodes() { return _elements; }

template <class T> Digraph<T> Digraph<T>::from_stream(std::istream &is) {
  Digraph<T> g;
  int line_number = 0;
  while (!is.eof()) {
    string line;
    getline(is, line);
    line_number++;
    if (line.empty())
      continue;
    istringstream iss(line);
    char ch;
    T u, v;
    if (line[0] == '+') {
      iss >> ch;
      while (iss >> v) {
        g.add_node(v);
      }
    } else if (line[0] == '-') {
      iss >> ch;
      iss >> u;
      while (iss >> v) {
        g.add_edge(u, v);
      }
    } else {
      if (line[0] == '*') {
        iss >> ch;
      }
      iss >> u;
      while (iss >> v) {
        g.add_edge(u, v);
        u = v;
      }
    }
  }
  return g;
}

template <class T> Digraph<T> Digraph<T>::from_string(std::string str) {
  stringstream ss(str);
  return Digraph<T>::from_stream(ss);
}

template <class T> Digraph<T> Digraph<T>::from_file(std::string filename) {
  ifstream f(filename);
  return Digraph<T>::from_stream(f);
}

template <class T> vector<T> Digraph<T>::successors(T v) {
  vector<T> res;
  if (!is_node(v))
    return res;
  int vv = id[v];
  for (int u : simple_digraph.successors(vv)) {
    res.push_back(name[u]);
  }
  return res;
}

template <class T> vector<T> Digraph<T>::predecessors(T v) {
  vector<T> res;
  if (!is_node(v))
    return res;
  int vv = id[v];
  for (int u : simple_digraph.predecessors(vv)) {
    res.push_back(name[u]);
  }
  return res;
}

template <class T> int Digraph<T>::number_of_nodes() {
  return simple_digraph.number_of_nodes();
}

template <class T> int Digraph<T>::number_of_edges() {
  return simple_digraph.number_of_edges();
}

template <class T> bool Digraph<T>::is_tree_with_root(T root) {
  if (!is_node(root))
    return false;
  return simple_digraph.is_tree_with_root(id[root]);
}

template <class T>
int Digraph<T>::shortest_path_length(T u, T v, bool undirected) {
  if (!is_node(u) || !is_node(v))
    throw PathDontFoundException<T>(u, v);
  try {
    return simple_digraph.shortest_path_length(id[u], id[v], undirected);
  } catch (PathDontFoundException<int> &e) {
    throw PathDontFoundException<T>(u, v);
  }
}

template <class T> int Digraph<T>::shortest_path_length(T u, T v) {
  return shortest_path_length(u, v, false);
}

template <class T> void Digraph<T>::add_edges(vector<pair<T, T>> edges) {
  for (auto p : edges) {
    add_edge(p.first, p.second);
  }
}

template <class T> void Digraph<T>::add_edge(T u, T v) {
  if (!is_node(u))
    add_node(u);
  if (!is_node(v))
    add_node(v);
  simple_digraph.add_edge(id[u], id[v]);
}

template <class T> bool Digraph<T>::is_edge(T u, T v) {
  if (!is_node(u) || !is_node(v))
    return false;
  return simple_digraph.is_edge(id[u], id[v]);
}

template <class T> vector<pair<T, T>> Digraph<T>::edges() {
  vector<pair<T, T>> res;
  for (T u : _elements) {
    for (T v : _elements) {
      if (is_edge(u, v)) {
        res.emplace_back(u, v);
      }
    }
  }
  return res;
}

template <class T> std::string Digraph<T>::to_string() {
  stringstream ss;
  // ss << "nodes " << _elements << endl;
  map<T, bool> used;
  for (auto e : edges()) {
    used[e.first] = used[e.second] = true;
    ss << e.first << " " << e.second << endl;
  }
  vector<T> not_used;
  for (T n : _elements) {
    if (!used[n]) {
      not_used.push_back(n);
    }
  }
  if (not_used.size() > 0) {
    ss << "+ ";
    for (T n : not_used) {
      ss << n << " ";
    }
    ss << endl;
  }
  return ss.str();
}
