#ifndef TREEISO_H
#define TREEISO_H



template <class T, class U> class DigraphIso {
  Digraph<T> orig_g1;
  Digraph<U> orig_g2;
  SimpleDigraph g1, g2;
  std::set<int> vertices;
  int n = -1;    // количество вершин в графах g1, g2
  int g1_k = -1; // подмножество вершин g1 {0, 1, ..., g1_k}
  std::set<int> g2_s; // Подмножество вершин графа g2, которое
  // соотвествует множеству вершин грфафа g1 {0, 1, ..., g1_k}
  vector<int> f; // биекция: i (вершина g1) -> f[i] (вершина g2)
  int ans = -1;
  bool match(int v);
  void go();
  std::map<T, U> f2;
  std::function<bool(T, U)> match2;
  std::map<T, U> initial_bijection;

public:
  DigraphIso(Digraph<T> ag1, Digraph<U> ag2,
             std::function<bool(T, U)> amatch2 = [](T x, U y) { return true; });
  bool is_iso();
  void set_initial_biection(std::map<T, U> b) {
    initial_bijection = b;
    ans = -1;
  }
  std::map<T, U> get_biection();
};

class TreeIso {
public:
  DigraphIso(Digraph<T> ag1, T r1, Digraph<U> ag2, T r2);
  bool is_iso();
  void set_initial_biection(std::map<T, U> b) {
    initial_bijection = b;
    ans = -1;
  }
  std::map<T, U> get_biection();
};

#endif /* end of include guard: TREEISO_H */
