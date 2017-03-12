#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <class T> class Matrix {
  int buffer_increase = 100, buffer_limit = 100000;
  int size = 0;
  int rows = 0, cols = 0;
  std::vector<std::vector<T>> buf;

public:
  Matrix(int start_rows, int start_cols);
  void resize(int new_rows, int new_cols);
  std::vector<T> &operator[](int i);
};

#endif /* end of include guard: MATRIX_H */
