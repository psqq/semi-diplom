#include "digraph.h"
#include "semilattice.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

digraph::digraph(istream &is) { load_from_stream(is); }

digraph::digraph(string s) {
  stringstream ss(s);
  load_from_stream(ss);
}

digraph::digraph(int an) { resize(an); }

void digraph::resize(int new_n) {
  n = new_n;
  adj_list.resize(n, vector<int>());
  input_vers.resize(n, vector<int>());
  adj_mat.resize(n, vector<int>(n, 0));
  dist.resize(n, vector<int>(n, -1));
  inv3.resize(n);
}

void digraph::load_from_file(string file_name) {
  ifstream fin(file_name);
  if (!fin.good()) {
    cout << "File '" << file_name << "' not found!" << endl;
    exit(1);
  }
  load_from_stream(fin);
}

void digraph::load_from_stream(istream &is) {
  string line;
  getline(is, line);
  istringstream iss(line);
  iss >> n;
  resize(n);
  while (!is.eof()) {
    getline(is, line);
    if (line.empty())
      continue;
    istringstream iss(line);
    istringstream iss2(line);
    char c;
    iss2 >> c;
    int v, u;
    if (c == 'l') {
      iss >> c;
      iss >> v;
      while (iss >> u)
        add_edge(v, u);
    } else if (c == 'p' || isdigit(c)) {
      if (!isdigit(c))
        iss >> c;
      iss >> v;
      while (iss >> u) {
        add_edge(v, u);
        v = u;
      }
    } else {
      cout << "Ошибка: ожидалось число, символ 'p' или 'l', но получено: '"
           << "'" << endl;
    }
  }
  update();
}

int digraph::count_vertices() { return n; }

bool digraph::is_edge(int a, int b) {
  assert(0 <= a && a < n && 0 <= b && b < n);
  return adj_mat[a][b];
}

void digraph::add_edge(int a, int b) {
  assert(0 <= a && a < n && 0 <= b && b < n);
  if (is_edge(a, b))
    return;
  input_vers[b].push_back(a);
  adj_list[a].push_back(b);
  adj_mat[a][b] = 1;
  m++;
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
  if (is_leaves_finded) {
    cout << "Leaves: ";
    for (int i = 0; i < leaves.size(); i++) {
      cout << leaves[i];
      if (i < leaves.size() - 1)
        cout << ", ";
    }
    cout << endl;
  }
  if (is_dists_finded) {
    cout << "Dists:\n";
    for (int v = 0; v < n; v++) {
      cout << '\t';
      for (int u = 0; u < n; u++) {
        cout << dist[v][u];
        if (u < n - 1)
          cout << " ";
      }
      cout << '\n';
    }
  }
  if (is_inv3_finded) {
    cout << "Inv3:\n";
    for (int v = 0; v < n; v++) {
      cout << '\t' << v << ": '" << inv3[v] << "'\n";
    }
    cout << "full: '" << inv3_full << "'\n";
  }
}

int digraph::degree(int v) { return adj_list[v].size(); }

vector<int> digraph::output_vertices(int v) { return adj_list[v]; }

void digraph::find_dists_from(int s) {
  queue<int> q;
  vector<bool> used(n, false);
  q.push(s);
  dist[s][s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    used[v] = true;
    for (int u = 0; u < n; u++) {
      if (is_edge(v, u) || is_edge(u, v)) {
        if (!used[u]) {
          dist[s][u] = dist[s][v] + 1;
          q.push(u);
        }
      }
    }
  }
}

void digraph::find_dists() {
  if (is_dists_finded)
    return;
  for (int s = 0; s < n; s++) {
    find_dists_from(s);
  }
  is_dists_finded = true;
}

void digraph::find_leaves() {
  if (is_leaves_finded)
    return;
  for (int v = 0; v < n; v++) {
    if (adj_list[v].size() == 0) {
      leaves.push_back(v);
    }
  }
  is_leaves_finded = true;
}

void digraph::find_inv3() {
  find_dists();
  find_leaves();
  for (int v = 0; v < n; v++) {
    stringstream ss;
    ss << dist[root][v] << ", " << input_vers[v].size() << ", "
       << adj_list[v].size() << ", (";
    vector<int> t;
    for (int i = 0; i < leaves.size(); i++) {
      t.push_back(dist[v][leaves[i]]);
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++) {
      ss << t[i];
      if (i < t.size() - 1)
        ss << ", ";
    }
    ss << ")";
    inv3[v] = ss.str();
  }
  vector<string> t = inv3;
  sort(t.begin(), t.end());
  for (int v = 0; v < n; v++) {
    inv3_full += t[v];
    if (v < n - 1)
      inv3_full += "; ";
  }
  is_inv3_finded = true;
}

int digraph::dist_to_root(int v) {
  find_dists();
  return dist[root][v];
}

int digraph::inf(int u, int v) {
  assert(0 <= u && u < n && 0 <= v && v < n);
  int du = dist_to_root(u), dv = dist_to_root(v);
  set<int> us, vs;
  us.insert(u);
  vs.insert(v);
  int f = 0;
  while (1) {
    while (du > dv || f) {
      set<int> new_us;
      for (int x : us) {
        new_us.insert(input_vers[x].begin(), input_vers[x].end());
      }
      us = new_us;
      du--;
    }
    while (dv > du) {
      set<int> new_vs;
      for (int x : vs) {
        new_vs.insert(input_vers[x].begin(), input_vers[x].end());
      }
      vs = new_vs;
      dv--;
    }
    if (us.size() == 0 || vs.size() == 0) {
      cout << "Ошибка: у данных вершин нет inf!" << endl;
      return -1;
    }
    set<int> intersect;
    set_intersection(us.begin(), us.end(), vs.begin(), vs.end(),
                     inserter(intersect, intersect.begin()));
    if (intersect.size() == 1) {
      return *intersect.begin();
    } else if (intersect.size() > 1) {
      cout << "Ошибка: inf имеет больше одного значения!" << endl;
      return -1;
    } else {
      f = 1;
    }
  }
}

Semilattice digraph::to_semi() {
  Semilattice semi(n);
  for (int u = 0; u < n; u++) {
    for (int v = u; v < n; v++) {
      int res;
      if (u == v)
        res = u;
      else
        res = inf(u, v);
      semi.set_op(u, v, res);
      semi.set_op(v, u, res);
    }
  }
  return semi;
}

void digraph::check_is_tree() {
  queue<int> q;
  vector<bool> used(n, false);
  int count_used = 0;
  q.push(root);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    used[v] = true;
    count_used++;
    for (int u = 0; u < n; u++) {
      if (is_edge(v, u) || is_edge(u, v)) {
        if (!used[u]) {
          q.push(u);
        }
      }
    }
  }
  _is_tree = count_used == n && m == n - 1;
}

bool digraph::is_tree() {
  if (_is_tree < 0) check_is_tree();
  return _is_tree;
}

void digraph::update() {
  find_dists();
  find_inv3();
  find_leaves();
  check_is_tree();
}

string digraph::encode_as_tree_for_vertex(int v) {
  string res = "0";
  for(int u: adj_list[v]) {
    res += encode_as_tree_for_vertex(u);
  }
  return res + "1";
}

string digraph::encode_as_tree() {
  return encode_as_tree_for_vertex(root);
}

int digraph::get_root() {
  return root;
}

string digraph::to_text() {
  stringstream ss;
  ss << n << "\n";
  ss << "r " << root << "\n";
  for (int u = 0; u < n; u++) {
    for (int v = u; v < n; v++) {
      if (is_edge(u, v)) {
        ss << u << " " << v << "\n";
      }
    }
  }
  return ss.str();
}
