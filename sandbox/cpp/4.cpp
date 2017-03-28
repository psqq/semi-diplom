#include <fstream>
#include <iostream>
using namespace std;

struct A {
  bool use_log = 1, use_filelog = 0;
  ofstream log_file;
  void open() {
    use_filelog = 1;
    log_file.open("log.txt");
  }
};

template <class T> A &operator<<(A &a, T x) {
  if (a.use_log) {
    std::cout << x;
  }
  if (a.use_filelog) {
    a.log_file << x;
  }
  return a;
}

A &operator<<(A &a,
              std::basic_ostream<char> &(*func)(std::basic_ostream<char> &)) {
  if (a.use_log) {
    std::cout << func;
  }
  if (a.use_filelog) {
    a.log_file << func;
  }
  return a;
}

int main() {
  A a;
  a.open();
  a << "Hello, World!" << endl;
  a << "Hello, World!" << endl;
  a << "Hello, World!" << endl;
}
