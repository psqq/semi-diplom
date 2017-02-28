#include "semilattice.h"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Semilattice::Semilattice() {}
Semilattice::Semilattice(int an) { resize(an); }

void Semilattice::resize(int new_n) {
  assert(new_n > 0);
  n = new_n;
  op.resize(n, vector<int>(n, 0));
}

void Semilattice::load_from_file(string filename) {
  ifstream fin(filename);
  load_from_stream(fin);
}

void Semilattice::load_from_stream(istream &is) {
  vector<int> nums;
  int t;
  while (is >> t)
    nums.push_back(t);
  int sq = sqrt(nums.size() + .0);
  if (sq * sq != nums.size()) {
    cout << "Warning: matrix in stream don't square!" << endl;
    sq++;
  }
  resize(sq);
  for (int i = 0; i < nums.size(); i++) {
    assert(0 <= nums[i] && nums[i] < n);
    op[i / n][i % n] = nums[i];
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

void Semilattice::set(int x, int y, int val) {
  assert(0 <= x && x < n && 0 <= y && y < n && 0 <= val && val < n);
  op[x][y] = val;
}

string Semilattice::to_text() {
  stringstream ss;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ss << op[i][j];
      if (j + 1 < n)
        ss << " ";
    }
    ss << "\n";
  }
  return ss.str();
}
