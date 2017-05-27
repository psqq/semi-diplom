#include "treeiso.h"
#include "semiiso.h"
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

template <class T> TreeEncoder<T>::TreeEncoder(Digraph<T> &ag) : g(ag) {}

template <class T> void TreeEncoder<T>::go() {
  r.second = find_root(g);
  _good = true;
  if (g.number_of_nodes() == 0)
    return;
  go(r.second);
  computed = true;
}

template <class T> void TreeEncoder<T>::go(const T &v) {
  string t = "0";
  vector<string> a;
  for (const T &u : g.successors(v)) {
    go(u);
    a.push_back(s[u]);
  }
  sort(a.begin(), a.end());
  for (string &tt : a) {
    t += tt;
  }
  t += "1";
  s[v] = t;
}

template <class T> string TreeEncoder<T>::code() {
  if (!computed)
    go();
  return s[r.second];
}

template <class T> string TreeEncoder<T>::code_of_node(T v) {
  if (!computed)
    go();
  return s[v];
}

template <class T> bool TreeEncoder<T>::good() {
  if (!computed)
    go();
  return _good;
}

template <class T>
TreeIso<T>::TreeIso(Digraph<T> &ag1, Digraph<T> &ag2)
    : g1(ag1), g2(ag2), e1(ag1), e2(ag2) {}

template <class T> bool TreeIso<T>::is_iso() {
  if (_is_iso >= 0)
    return _is_iso;
  if (!e1.good() || !e2.good()) {
    _is_iso = 0;
    return false;
  }
  _is_iso = e1.code() == e2.code() ? 1 : 0;
  return _is_iso;
}

template <class T> const std::map<T, T> &TreeIso<T>::get_biection() {
  if (_is_iso < 0) {
    is_iso();
  }
  if (!_is_iso || f_computed) {
    return f;
  }
  T r1 = find_root(g1);
  T r2 = find_root(g2);
  f[r1] = r2;
  queue<T> q;
  q.push(r1);
  while (!q.empty()) {
    T v1 = q.front();
    q.pop();
    T v2 = f[v1];
    vector<pair<T, string>> a1, a2;
    for (const T &u1 : g1.successors(v1)) {
      a1.emplace_back(u1, e1.code_of_node(u1));
    }
    for (const T &u2 : g2.successors(v2)) {
      a2.emplace_back(u2, e2.code_of_node(u2));
    }
    sort(a1.begin(), a1.end(),
         [](auto &a, auto &b) { return a.second < b.second; });
    sort(a2.begin(), a2.end(),
         [](auto &a, auto &b) { return a.second < b.second; });
    for (int i = 0; i < a1.size(); i++) {
      f[a1[i].first] = a2[i].first;
      q.push(a1[i].first);
    }
  }
  f_computed = true;
  return f;
}
