#include "matrix.h"
using namespace std;

template <class T>
Matrix<T>::Matrix(int start_rows, int start_cols) {
  resize(start_rows, start_cols);
}

template <class T>
void Matrix<T>::resize(int new_rows, int new_cols) {
}

template <class T>
vector<T> &Matrix<T>::operator[](int i) {
  return buf[i];
}
