#include "digraphiso.h"
#include <algorithm>
using namespace std;

template <class T, class U>
DigraphIso<T, U>::DigraphIso(Digraph<T> ag1, Digraph<U> ag2,
                             std::function<bool(T, U)> amatch2)
    : orig_g1(ag1), orig_g2(ag2), g1(ag1.get_simple_digraph()),
      g2(ag2.get_simple_digraph()), match2(amatch2) {}

template <class T, class U> bool DigraphIso<T, U>::match(int v) {
  // Подмножество g1 {0, 1, ..., g1_k - 1} изоморфно
  // подножеству графа g2 g2_s,
  // которое равно {f[0], f[1], ..., f[g1_k - 1]}
  // На данном шаге нужно проверить может ли подмножество g1
  // {0, 1, ..., g1_k - 1, g1_k} быть изоморфно
  // подмножеству g2 {f[0], f[1], ..., f[g1_k - 1], v}
  if (!match2(orig_g1.get_name_by_id(g1_k), orig_g2.get_name_by_id(v)))
    return false;
  for (int u = 0; u < g1_k; u++) {
    if (g1.is_edge(u, g1_k) && !g2.is_edge(f[u], v)) {
      // cout << 1 << ": " << u << " " << g1_k << " "
      //      << f[u] << " " << v << endl;
      return false;
    }
    if (g1.is_edge(g1_k, u) && !g2.is_edge(v, f[u])) {
      // cout << 2 << endl;
      return false;
    }
  }
  return true;
}

template <class T, class U> void DigraphIso<T, U>::go() {
  // cout << "go begin\n";
  // cout << "g2_s: ";
  // for (int i : g2_s) cout << i << " ";
  // cout << endl;
  if (g2_s.size() == n) {
    ans = 1;
    return;
  }
  g1_k += 1;
  set<int> t;
  set_difference(vertices.begin(), vertices.end(), g2_s.begin(), g2_s.end(),
                 inserter(t, t.end()));
  // cout << "t: ";
  // for (int i : t) cout << i << " ";
  // cout << endl;
  for (int v : t) {
    if (ans >= 0)
      return;
    if (match(v)) {
      // cout << g1_k << " match " << v << endl;
      f[g1_k] = v;
      f2[orig_g1.get_name_by_id(g1_k)] = orig_g2.get_name_by_id(v);
      g2_s.insert(v);
      go();
      g2_s.erase(v);
    } else {
      // cout << g1_k << " don't match " << v << endl;
    }
  }
  g1_k -= 1;
}

template <class T, class U> bool DigraphIso<T, U>::is_iso() {
  if (ans >= 0)
    return ans;
  if (g1.number_of_nodes() != g2.number_of_nodes()) {
    return false;
  }
  n = g1.number_of_nodes();
  f.resize(n);
  for (int i = 0; i < n; i++)
    vertices.insert(i);
  go();

  // cout << "ans " << ans << endl;
  if (ans < 0)
    ans = 0;
  return ans;
}

template <class T, class U> map<T, U> DigraphIso<T, U>::get_biection() {
  return f2;
}
