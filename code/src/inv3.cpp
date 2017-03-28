#include "inv3.h"
#include <algorithm>
using namespace std;

template <class T> Inv3<T>::Inv3() : is_empty(true), root() {}

template <class T> Inv3<T>::Inv3(Digraph<T> ag) : root() {
  if (ag.number_of_nodes() == 0) {
    is_empty = true;
    return;
  }
  g = ag;
  find_leaves();
  root = find_root(g);
  for (T v : g.nodes()) {
    inv3_for_node[v] = compute_inv3_for_node(v);
  }
  full_inv3 = compute_full_inv3();
}

template <class T> void Inv3<T>::find_leaves() {
  for (T v : g.nodes()) {
    if (g.successors(v).size() == 0) {
      leaves.push_back(v);
    }
  }
}

template <class T> string Inv3<T>::get_inv3_for_node(T v) {
  return inv3_for_node[v];
}

template <class T> string Inv3<T>::compute_inv3_for_node(T v) {
  if (is_empty)
    return "";
  stringstream ss;
  ss << g.shortest_path_length(root, v, true) << ", "
     << g.predecessors(v).size() << ", " << g.successors(v).size() << ", (";
  vector<int> t;
  for (int i = 0; i < leaves.size(); i++) {
    t.push_back(g.shortest_path_length(leaves[i], v, true));
  }
  sort(t.begin(), t.end());
  for (int i = 0; i < t.size(); i++) {
    ss << t[i];
    if (i < t.size() - 1)
      ss << ", ";
  }
  ss << ")";
  return ss.str();
}

template <class T> string Inv3<T>::get_full_inv3() { return full_inv3; }

template <class T> string Inv3<T>::compute_full_inv3() {
  if (is_empty)
    return "";
  vector<string> arr;
  for (T v : g.nodes()) {
    arr.push_back(get_inv3_for_node(v));
  }
  sort(arr.begin(), arr.end());
  string full_inv3;
  for (string x : arr) {
    full_inv3 += x + "; ";
  }
  return full_inv3;
}
