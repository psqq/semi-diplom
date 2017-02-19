#ifndef SEMILATTICE_H
#define SEMILATTICE_H

#include <iostream>
using namespace std;

class Semilattice {
  int n;
  bool is_valid = false;
  vector<vector<int>> op;
  void resize(int new_n);
private:
  bool validate_associative();
  bool validate_commutativity();
  bool validate_idempotence();
  bool validate();
public:
  Semilattice();
  Semilattice(int an);
  void load(string filename);
};

#endif /* end of include guard: SEMILATTICE_H */
