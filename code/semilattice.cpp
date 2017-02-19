#include "semilattice.h"

Semilattice::Semilattice() {}
Semilattice::Semilattice(int an) {
  resize(an);
}

void Semilattice::resize(int new_n) {
  n = new_n;
  op.resize(n, vector<int>(n, 0));
}

void Semilattice::load(string filename) {
  ifstream fin(filename);
  vector<int> nums;
  int t;
  while (fin >> t) nums.push_back(t);
  int sq = sqrt(nums.size() + .0);
  if (sq*sq != nums.size()) {
    cout << "Warning: matrix in file " << filename << " don't square!" << endl;
    sq++;
  }
  resize(sq);
  for (int i=0; i<nums.size(); i++) {
    op[i/n][i%n] = nums[i];
  }
  if (!validate()) {
    cout << "Warning: semilattice don't valid!" << endl;
  }
}

bool Semilattice::validate_associative() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      for (int z = 0; z < n; z++) {
        if (op[x][op[y][z]] != op[op[x][y]][z]) {
          return false;
        }
      }
    }
  }
  return true;
}

bool Semilattice::validate_commutativity() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (op[x][y] != op[y][x]) {
        return false;
      }
    }
  }
  return true;
}

bool Semilattice::validate_idempotence() {
  for (int x = 0; x < n; x++) {
    if (op[x][x] != x) {
      return false;
    }
  }
  return true;
}

bool Semilattice::validate() {
  is_valid = validate_associative() && validate_commutativity() &&
             validate_idempotence();
  return is_valid;
}
