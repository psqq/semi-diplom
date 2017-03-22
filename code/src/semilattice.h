#ifndef SEMILATTICE_H
#define SEMILATTICE_H

#include <map>
#include <set>
#include <unordered_map>
#include <vector>

class SimpleSemilattice {
  static const int BUFFER_INCREASE = 100;
  int buffer_limit = 100000;
  int n = 0, max_n = 0;
  std::vector<std::vector<int>> op;
  void resize(int new_n);

public:
  explicit SimpleSemilattice(int new_n = 0);
  int add_element();
  int size();
  int inf(int a, int b);
  void set_inf(int a, int b, int val);
  bool is_element(int a);
  void throw_exception_if_element_does_not_exist(int a);
  bool is_valid();
  bool is_associative();
  bool is_commutativity();
  bool is_idempotence();
};

template <class T> class Semilattice {
  std::set<T> _elements;
  std::map<T, int> id;
  std::vector<T> name;
  SimpleSemilattice simple_semilattice;

public:
  void add_element(T a);
  template <class U> void add_elements(U elems) {
    for (T el : elems) {
      add_element(el);
    }
  }
  bool is_element(T a);
  int size();
  std::set<T> elements();
  T inf(T a, T b);
  void set_inf(T a, T b, T c);
  void throw_exception_if_element_does_not_exist(T a);
  bool is_valid();
  bool is_associative();
  bool is_commutativity();
  bool is_idempotence();
  static Semilattice<T> from_stream(std::istream &is);
  static Semilattice<T> from_file(std::string fn);
  static Semilattice<T> from_string(std::string s);
};

template class Semilattice<std::string>;
template class Semilattice<int>;

#endif /* end of include guard: SEMILATTICE_H */
