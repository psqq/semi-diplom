#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <set>

template <class T> std::ostream &operator<<(std::ostream &os, std::vector<T> s) {
  os << "[ ";
  for (T x : s) {
    os << x << " ";
  }
  os << "]";
  return os;
}

template <class T> std::ostream &operator<<(std::ostream &os, std::set<T> s) {
  os << "{ ";
  for (T x : s) {
    os << x << " ";
  }
  os << "}";
  return os;
}

#endif /* end of include guard: UTILS_H */
