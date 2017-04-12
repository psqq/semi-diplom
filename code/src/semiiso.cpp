#include "digraphiso.h"
#include "exceptions.h"
#include "inv3.h"
#include "main.h"
#include "semiiso.h"
#include "semilog.h"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iostream>
#include <set>
#include <tuple>
using namespace std;

template <class T> Digraph<T> to_digraph(Semilattice<T> s) {
  // int n = s.size();
  auto elems = s.elements();
  T root = *begin(elems);
  Digraph<T> g;
  for (T el : elems) {
    g.add_node(el);
    root = s.inf(root, el);
  }
  set<T> level = {root};
  while (level.size() > 0) {
    set<T> new_level;
    for (T x : level) {
      for (T y : elems) {
        if (y != x && s.inf(x, y) == x) {
          bool flag = true;
          for (T z : elems) {
            if (z != x && z != y && x == s.inf(x, z) && z == s.inf(z, y)) {
              flag = false;
              break;
            }
          }
          if (flag) {
            g.add_edge(x, y);
            new_level.insert(y);
          }
        }
      }
    }
    level = new_level;
  }
  return g;
}

template <class T> T find_root(Digraph<T> g) {
  if (g.number_of_nodes() == 0) {
    throw GeneralException("find_root: root don't found!");
  }
  T root = *begin(g.nodes());
  for (int i = 0; i < g.number_of_nodes(); i++) {
    auto p = g.predecessors(root);
    if (p.size() == 0)
      return root;
    root = *begin(p);
  }
  throw GeneralException("find_root: root don't found!");
}

template int inf_for_digraph(Digraph<int> g, int u, int v);
template string inf_for_digraph(Digraph<string> g, string u, string v);

template <class T> T inf_for_digraph(Digraph<T> g, T u, T v) {
  T root = find_root(g);
  int du = g.shortest_path_length(root, u);
  int dv = g.shortest_path_length(root, v);
  set<T> us = {u}, vs = {v};
  bool flag = false;
  while (1) {
    while (us.size() > 0 && (flag || du > dv)) {
      set<T> new_us;
      for (T x : us) {
        auto p = g.predecessors(x);
        new_us.insert(begin(p), end(p));
      }
      us = new_us;
      du--;
      flag = false;
    }
    while (vs.size() > 0 && dv > du) {
      set<T> new_vs;
      for (T x : vs) {
        auto p = g.predecessors(x);
        new_vs.insert(begin(p), end(p));
      }
      vs = new_vs;
      dv--;
      flag = false;
    }
    if (vs.size() == 0 || us.size() == 0) {
      throw GeneralException("inf_for_digraph: inf don't found!");
    }
    set<T> uv_intersection;
    set_intersection(begin(us), end(us), begin(vs), end(vs),
                     inserter(uv_intersection, uv_intersection.begin()));
    if (uv_intersection.size() > 1) {
      throw GeneralException("inf_for_digraph: inf don't found!");
    } else if (uv_intersection.size() == 1) {
      return *begin(uv_intersection);
    } else {
      flag = true;
    }
  }
}

template Semilattice<int> to_semi<int>(Digraph<int> g);
template Semilattice<string> to_semi<string>(Digraph<string> g);

template <class T> Semilattice<T> to_semi(Digraph<T> g) {
  Semilattice<T> s;
  if (g.number_of_nodes() == 0) {
    return s;
  }
  if (g.number_of_nodes() == 1) {
    s.add_element(*g.nodes().begin());
    return s;
  }
  s.add_elements(g.nodes());
  for (T v : g.nodes()) {
    for (T u : g.nodes()) {
      s.set_inf(v, u, inf_for_digraph(g, v, u));
    }
  }
  return s;
}

template <class T> string encode_tree(Digraph<T> g) {
  if (g.number_of_nodes() == 0) {
    return "";
  }
  T root = find_root(g);
  function<string(T)> go = [&](T v) -> string {
    string s = "0";
    for (T u : g.successors(v)) {
      s += go(u);
    }
    return s + "1";
  };
  return go(root);
}

template <class T> bool tree_is_isomorphic(Digraph<T> g1, Digraph<T> g2) {
  string s1 = encode_tree(g1);
  string s2 = encode_tree(g2);
  // if (log_mode) {
  //   semi_log << "Код дерева g1: " << s1 << endl;
  //   semi_log << "Код дерева g2: " << s2 << endl;
  //   if (s1 == s2) {
  //     semi_log << "Строки равны следовательно графы изоморфны." << endl;
  //   }
  // }
  // cout << endl << s1 << endl << s2 << endl;
  return s1 == s2;
}

template <class T> vector<set<T>> find_branches_of_digraph(Digraph<T> g) {
  vector<set<T>> branches;
  T root = find_root(g);
  class A {
    map<T, set<T>> res;
    map<T, bool> used;
    Digraph<T> &g;

  public:
    explicit A(Digraph<T> &ag) : g(ag) {}
    set<T> operator()(T v) {
      if (used[v])
        return res[v];
      set<T> t = {v}, t2;
      for (T u : g.successors(v)) {
        t2 = this->operator()(u);
        t.insert(t2.begin(), t2.end());
      }
      used[v] = true;
      res[v] = t;
      return t;
    }
  } vertexes_of_subgraph_with_root(g);
  // function<set<T>(T)> vertexes_of_subgraph_with_root = [&](T v) {
  //   set<T> t = {v}, t2;
  //   for (T u : g.successors(v)) {
  //     t2 = vertexes_of_subgraph_with_root(u);
  //     t.insert(t2.begin(), t2.end());
  //   }
  //   return t;
  // };
  for (T v : g.successors(root)) {
    auto t = vertexes_of_subgraph_with_root(v);
    vector<set<T>> new_branches;
    for (auto b : branches) {
      set<T> intersection_t_and_b;
      set_intersection(
          begin(t), end(t), begin(b), end(b),
          inserter(intersection_t_and_b, intersection_t_and_b.begin()));
      if (intersection_t_and_b.size() > 0) {
        t.insert(begin(b), end(b));
      } else {
        new_branches.push_back(b);
      }
    }
    new_branches.push_back(t);
    branches = new_branches;
  }
  for (auto &b : branches) {
    b.insert(root);
  }
  return branches;
}

template <class T> set<T> find_cyclic_vers(Digraph<T> g) {
  set<T> res;
  for (T v : g.nodes()) {
    if (g.predecessors(v).size() > 1) {
      res.insert(v);
    }
  }
  return res;
}

template <class T> Digraph<T> find_subgraph(Digraph<T> g, set<T> vers) {
  Digraph<T> subg;
  for (T u : vers) {
    subg.add_node(u);
    for (T v : vers) {
      if (g.is_edge(u, v)) {
        subg.add_edge(u, v);
      }
    }
  }
  return subg;
}

template <class T>
pair<Digraph<T>, Digraph<T>> find_G1_and_G2_graphs(Digraph<T> g) {
  auto branches = find_branches_of_digraph(g);
  auto cyclic_vers = find_cyclic_vers(g);
  set<T> G1_vers, G2_vers;
  for (auto b : branches) {
    set<T> t;
    set_intersection(begin(cyclic_vers), end(cyclic_vers), begin(b), end(b),
                     inserter(t, t.begin()));
    if (t.size() > 0) {
      G2_vers.insert(b.begin(), b.end());
    } else {
      G1_vers.insert(b.begin(), b.end());
    }
  }
  Digraph<T> G1 = find_subgraph(g, G1_vers);
  Digraph<T> G2 = find_subgraph(g, G2_vers);
  return {G1, G2};
}

template bool is_isomorphic<string>(Semilattice<string> s1,
                                    Semilattice<string> s2);

template bool is_isomorphic<int>(Semilattice<int> s1, Semilattice<int> s2);

template <class T> bool is_isomorphic(Semilattice<T> s1, Semilattice<T> s2) {

  clock_t t, start_time = clock();

  auto end_of_log = [&](bool res) {
    semi_log << "Полурешетки имзоморфны? " << res << endl;
    semi_log << "Полное время проверки полурешеток на изоморфизм: "
             << ((float)(clock() - start_time) / CLOCKS_PER_SEC) << " sec."
             << endl;
  };

  if (s1.size() != s2.size()) {
    semi_log << "Полурешетки не изоморфны, т.к. состоят из различного "
                "количества переменных."
             << endl;
    end_of_log(0);
    return false;
  }

  if (s1.size() == 0) {
    semi_log << "Путсые полурешетки изоморфны." << endl;
    end_of_log(1);
    return true;
  }

  if (s1.size() == 1) {
    semi_log << "Полурешетки, состоящие из одного элемента, изоморфны." << endl;
    end_of_log(1);
    return true;
  }

  auto tree_is_isomorphic_with_log = [&](Digraph<T> &g1, string g1_name,
                                         Digraph<T> &g2, string g2_name) {
    cout << "Проверка графов " << g1_name << " и " << g2_name
         << " на изоморфизм с помощью алгоритма проверки деревьев на изоморфизм"
         << endl;
    string s1 = encode_tree(g1);
    string s2 = encode_tree(g2);
    bool res = s1 == s2;
    semi_log << "Код графа " << g1_name << ": '" << s1 << "'" << endl;
    semi_log << "Код графа " << g2_name << ": '" << s2 << "'" << endl;
    if (res) {
      semi_log << "Строки равны следовательно графы изоморфны." << endl;
    } else {
      semi_log << "Строки не равны следовательно графы не изоморфны." << endl;
    }
    return res;
  };

  if (log_mode) {
    semi_log << "Проверка полурешеток s1 и s2 на изоморфизм." << endl;
    semi_log << "Полурешетка s1:\n" << s1.to_string();
    semi_log << "Полурешетка s2:\n" << s2.to_string();
    semi_log << "Преобразование полурешеток s1, s2 в графы g1, g2... ";
    t = clock();
  }

  Digraph<T> g1 = to_digraph(s1), g2 = to_digraph(s2);

  if (log_mode) {
    float dt = ((float)(clock() - t) / CLOCKS_PER_SEC);
    semi_log << dt << " sec." << endl;
    semi_log << "Граф g1:\n" << g1.to_string();
    semi_log << "Граф g2:\n" << g2.to_string();
    t = clock();
  }

  int n1 = g1.number_of_nodes(), n2 = g2.number_of_nodes();

  if (log_mode) {
    semi_log << "Количество вершин в графе g1: " << n1 << endl;
    semi_log << "Количество вершин в графе g2: " << n2 << endl;
  }

  if (n1 != n2) {
    if (log_mode) {
      semi_log
          << "В графах различное количество вершин, поэтому полурешетки не "
             "изоморфны."
          << endl;
    }
    return false;
  }

  int m1 = g1.number_of_edges(), m2 = g2.number_of_edges();

  if (log_mode) {
    semi_log << "Количество ребер в графе g1: " << m1 << endl;
    semi_log << "Количество ребер в графе g2: " << m2 << endl;
  }

  if (m1 != m2) {
    if (log_mode) {
      semi_log << "В графах различное количество ребер, поэтому полурешетки не "
                  "изоморфны."
               << endl;
    }
    return false;
  }

  T r1 = find_root(g1), r2 = find_root(g2);

  if (log_mode) {
    semi_log << "Корень в графе g1: " << r1 << endl;
    semi_log << "Корень в графе g2: " << r2 << endl;
  }

  bool g1_is_tree = g1.is_tree_with_root(r1);
  bool g2_is_tree = g2.is_tree_with_root(r2);

  if (log_mode) {
    semi_log << "Является ли граф g1 деревом? " << g1_is_tree << endl;
    semi_log << "Является ли граф g2 деревом? " << g2_is_tree << endl;
  }

  if (g1_is_tree != g2_is_tree) {
    if (log_mode) {
      semi_log
          << "Один из графов - дерево, а другой нет, поэтому полурешетки не "
             "изоморфны."
          << endl;
    }
    return false;
  }

  if (g1_is_tree && g2_is_tree) {
    if (log_mode) {
      semi_log << "Оба графа - деревья." << endl;
      bool res = tree_is_isomorphic_with_log(g1, "g1", g2, "g2");
      end_of_log(res);
      return res;
    } else {
      return tree_is_isomorphic(g1, g2);
    }
  }

  if (log_mode) {
    float dt = ((float)(clock() - t) / CLOCKS_PER_SEC);
    semi_log << "... " << dt << " sec." << endl;
    semi_log << "Поиск графов G1 и G2... ";
    t = clock();
  }

  Digraph<T> g1_G1, g1_G2, g2_G1, g2_G2;
  tie(g1_G1, g1_G2) = find_G1_and_G2_graphs(g1);
  tie(g2_G1, g2_G2) = find_G1_and_G2_graphs(g2);

  if (log_mode) {
    float dt = ((float)(clock() - t) / CLOCKS_PER_SEC);
    semi_log << dt << " sec." << endl;
    semi_log << "Граф g1_G1:\n" << g1_G1.to_string();
    semi_log << "Граф g1_G2:\n" << g1_G2.to_string();
    semi_log << "Граф g2_G1:\n" << g2_G1.to_string();
    semi_log << "Граф g2_G2:\n" << g2_G2.to_string();
    semi_log << "Проверка графов g1_G1, g2_G1 и g1_G2, g2_G2 на изоморфизм с "
                "помощью алгоритма для деревьев... ";
    t = clock();
  }

  bool res1 = tree_is_isomorphic(g1_G1, g2_G1);
  bool res2 = tree_is_isomorphic(g1_G2, g2_G2);

  if (log_mode) {
    float dt = ((float)(clock() - t) / CLOCKS_PER_SEC);
    semi_log << dt << " sec." << endl;
  }

  if (log_mode) {
    bool res1 = tree_is_isomorphic_with_log(g1_G1, "g1_G1", g2_G1, "g2_G1");
    if (!res1) {
      end_of_log(0);
      return false;
    }
    bool res2 = tree_is_isomorphic_with_log(g1_G2, "g1_G2", g2_G2, "g2_G2");
    if (!res2) {
      end_of_log(0);
      return false;
    }
  } else {
    if (!res1 || !res2) {
      return false;
    }
  }

  if (log_mode) {
    semi_log << "Поиск инварианта 3 для графов g1_G2 и g2_G2... ";
    t = clock();
  }

  Inv3<T> inv3_for_g1_G2(g1_G2);
  Inv3<T> inv3_for_g2_G2(g2_G2);

  if (log_mode) {
    float dt = ((float)(clock() - t) / CLOCKS_PER_SEC);
    semi_log << dt << " sec." << endl;
    semi_log << "Инвариант 3 для каждой из вершин графа g1_G2:" << endl;
    for (T v : g1_G2.nodes()) {
      semi_log << v << ": '" << inv3_for_g1_G2.get_inv3_for_node(v) << "'"
               << endl;
    }
    semi_log << "Инвариант 3 для каждой из вершин графа g1_G2:" << endl;
    for (T v : g2_G2.nodes()) {
      semi_log << v << ": '" << inv3_for_g2_G2.get_inv3_for_node(v) << "'"
               << endl;
    }
    semi_log << "Инвариант 3 для графа g1_G2: '"
             << inv3_for_g1_G2.get_full_inv3() << "'" << endl;
    semi_log << "Инвариант 3 для графа g2_G2: '"
             << inv3_for_g2_G2.get_full_inv3() << "'" << endl;
  }

  bool iseqinv3 =
      inv3_for_g1_G2.get_full_inv3() == inv3_for_g2_G2.get_full_inv3();

  if (!iseqinv3) {
    if (log_mode) {
      semi_log
          << "Инварианты графов не совпадают, значит полурешетки не изоморфны."
          << endl;
      end_of_log(0);
    }
    return false;
  }

  if (log_mode) {
    semi_log << "Проверка графов на изоморфизм с помощью общего алгоритма... ";
    t = clock();
  }

  DigraphIso<T, T> digiso(g1_G2, g2_G2, [&](T v, T u) {
    return inv3_for_g1_G2.get_inv3_for_node(v) ==
           inv3_for_g2_G2.get_inv3_for_node(u);
  });
  // digiso.set_initial_biection({{r1, r2}});
  bool res = digiso.is_iso();

  if (log_mode) {
    float dt = ((float)(clock() - t) / CLOCKS_PER_SEC);
    semi_log << dt << " sec." << endl;
  }

  if (log_mode && res) {
    semi_log << "Графы изоморфны. Биекция:\n";
    map<T, T> b = digiso.get_biection();
    for (auto p : b) {
      semi_log << p.first << " <-> " << p.second << endl;
    }
  }

  if (log_mode) {
    end_of_log(res);
  }

  return res;
}
