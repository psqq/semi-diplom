#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void find_all_semilattices(int n) {
  stringstream ss1, ss2;
  ss1 << "semigroups/cay" << n << ".txt";
  ss2 << "semilattices/cay" << n << ".txt";
  ifstream semigroups(ss1.str());
  ofstream semilattices(ss2.str());
  int i = 0, k1 = 0, k2 = 0;
  string t;
  vector<string> semi;
  semi.resize(n);
outer:
  while (semigroups >> semi[i++]) {
    if (i < n)
      continue;
    i = 0;
    k1++;
    // cout << "semi: ";
    // for (int x = 1; x <= n; x++) {
    //   cout << "\"" << semi[x] << "\" ";
    // }
    // cout << endl;
    for (int x = 1; x <= n; x++) {
      if (semi[x - 1][x - 1] != ('0' + x)) {
        // cout << "Check idempotence: semi[x][x] != ('0' + x)\n";
        // cout << "\tk: " << k << "\n";
        // cout << "\tx: " << x << " '" << ('0' + x) << "'\n";
        // cout << "\tsemi[x][x]: " << (semi[x][x] - '0') << " '" << semi[x][x]
        // << "'\n";
        goto outer;
      }
    }
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        if (semi[x - 1][y - 1] != semi[y - 1][x - 1]) {
          // cout << k << ": ";
          // cout << "semi[x][y] != semi[y][x]: " << semi[x][y] << " "
          //      << semi[y][x] << endl;
          goto outer;
        }
      }
    }
    k2++;
    for (string &s : semi) {
      for (int i = 0; i < s.length(); i++) {
        semilattices << (i == 0 ? "" : " ") << s[i];
      }
      semilattices << "\n";
    }
    semilattices << endl;
  }
  cout << "total: " << k1 << " " << k2 << " " << (1.0 * k2 / k1) << endl;
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    stringstream ss(argv[i]);
    int n;
    ss >> n;
    find_all_semilattices(n);
  }
}
