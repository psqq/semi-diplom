#include "exceptions.h"
#include "semilattice.h"
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

SimpleSemilattice::SimpleSemilattice(int new_n) { resize(new_n); }

void SimpleSemilattice::resize(int new_n) {
  if (new_n < 0) {
    throw WrongSizeException(
        "SimpleSemilattice: The size can not be negative!");
  }
  n = new_n;
  if (new_n > max_n) {
    int new_max_n = max(max_n + BUFFER_INCREASE, new_n);
    if (new_max_n > buffer_limit) {
      throw BufferLimitException("SimpleSemilattice:", max_n, new_max_n,
                                 buffer_limit);
    }
    max_n = new_max_n;
  }
  if (op.size() != max_n) {
    op.resize(max_n);
    for (int i = 0; i < max_n; i++)
      op[i].resize(max_n);
  }
}

int SimpleSemilattice::add_element() {
  n++;
  resize(n);
  return n - 1;
}

int SimpleSemilattice::size() { return n; }

int SimpleSemilattice::inf(int a, int b) {
  throw_exception_if_element_does_not_exist(a);
  throw_exception_if_element_does_not_exist(b);
  return op[a][b];
}

void SimpleSemilattice::set_inf(int a, int b, int val) {
  throw_exception_if_element_does_not_exist(a);
  throw_exception_if_element_does_not_exist(b);
  throw_exception_if_element_does_not_exist(val);
  op[a][b] = val;
}

bool SimpleSemilattice::is_element(int a) { return 0 <= a && a < n; }

void SimpleSemilattice::throw_exception_if_element_does_not_exist(int a) {
  if (!is_element(a)) {
    throw GeneralException("SimpleSemilattice: Eleement does not exist.");
    // throw SimpleSemilatticeElementDoesNotExist(a);
  }
}

template <class T> void Semilattice<T>::add_element(T a) {
  if (is_element(a))
    return;
  int i = simple_semilattice.add_element();
  id[a] = i;
  name.push_back(a);
  _elements.insert(a);
}

template <class T> std::set<T> Semilattice<T>::elements() { return _elements; }

template <class T> bool Semilattice<T>::is_element(T a) {
  return _elements.find(a) != _elements.end();
}

template <class T> int Semilattice<T>::size() {
  return simple_semilattice.size();
}

template <class T> T Semilattice<T>::inf(T a, T b) {
  throw_exception_if_element_does_not_exist(a);
  throw_exception_if_element_does_not_exist(b);
  // cout << endl;
  // cout << a << " " << b << endl;
  auto res = simple_semilattice.inf(id[a], id[b]);
  // cout << res << endl;
  // cout << name.size() << endl;
  // return a;
  return name[res];
}

template <class T> void Semilattice<T>::set_inf(T a, T b, T c) {
  throw_exception_if_element_does_not_exist(a);
  throw_exception_if_element_does_not_exist(b);
  throw_exception_if_element_does_not_exist(c);
  simple_semilattice.set_inf(id[a], id[b], id[c]);
}

template <class T>
void Semilattice<T>::throw_exception_if_element_does_not_exist(T a) {
  if (!is_element(a)) {
    throw GeneralException("Semilattice: Eleement does not exist.");
    // throw SimpleSemilatticeElementDoesNotExist(a);
  }
}

template <class T> void Semilattice<T>::load_from_stream(std::istream &is) {
  vector<T> a;
  T t;
  set<T> elems;
  while (is >> t) {
    a.push_back(t);
    elems.insert(t);
  }
  int n = sqrt(a.size());
  if (n * n != a.size()) {
    throw GeneralException(
        "Semilattice: load_from_stream: loaded matrix don't square.");
  }
  if (elems.size() != n) {
    throw GeneralException("Semilattice: load_from_stream: elems.size() != n.");
  }
  for (T el : elems) {
    add_element(el);
  }
  // cout << endl;
  // for (int i = 0; i < n*n; i++) {
  //   cout << "'" << a[i] << "' ";
  // }
  // cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // cout << name[i] << " " << name[j] << " " << a[i*n + j] << endl;
      set_inf(name[i], name[j], a[i * n + j]);
    }
  }
  // cout << endl;
}

template <class T> void Semilattice<T>::from_string(std::string s) {
  stringstream ss(s);
  load_from_stream(ss);
}
