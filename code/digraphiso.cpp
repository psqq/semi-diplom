#include "digraphiso.h"

DigraphIso::DigraphIso(digraph &ag1, digraph &ag2)
  : g1(ag1), g2(ag2) {}

bool DigraphIso::match(int v) {
  // Подмножество g1 {0, 1, ..., g1_k - 1} изоморфно
  // подножеству графа g2 g2_s,
  // которое равно {f[0], f[1], ..., f[g1_k - 1]}
  // На данном шаге нужно проверить может ли подмножество g1
  // {0, 1, ..., g1_k - 1, g1_k} быть изоморфно
  // подмножеству g2 {f[0], f[1], ..., f[g1_k - 1], v}
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

void DigraphIso::go() {
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
  set_difference(
    vertices.begin(), vertices.end(),
    g2_s.begin(), g2_s.end(),
    inserter(t, t.end())
  );
  // cout << "t: ";
  // for (int i : t) cout << i << " ";
  // cout << endl;
  for (int v : t) {
    if (ans >= 0) return;
    if (match(v)) {
      // cout << g1_k << " match " << v << endl;
      f[g1_k] = v;
      g2_s.insert(v);
      go();
      g2_s.erase(v);
    } else {
      // cout << g1_k << " don't match " << v << endl;
    }
  }
  g1_k -= 1;
}

bool DigraphIso::is_iso() {
  if (ans >= 0) return ans;
  if (g1.count_vertices() != g2.count_vertices()) {
    return false;
  }
  n = g1.count_vertices();
  f.resize(n);
  for (int i=0; i<n; i++) vertices.insert(i);
  go();
  // cout << "ans " << ans << endl;
  if (ans < 0) ans = 0;
  return ans;
}

vector<int> DigraphIso::biection() {
  return f;
}
