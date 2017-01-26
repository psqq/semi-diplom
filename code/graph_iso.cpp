#include <bits/stdc++.h>
#include "digraph.h"
using namespace std;

class DigraphIso {
  digraph g1, g2;
  bool match(int k) {}
  bool go(set<int> s) {}
public:
  DigraphIso(digraph ag1, digraph ag2) : g1(ag1), g2(ag2) {}
  bool is_iso() {
    if (g1.count_vertices() != g2.count_vertices()) {
      return false;
    }
  }
};

int main() {
  digraph g1("1.digraph"), g2("2.digraph");
  cout << "# 1.digraph:\n";
  g1.print();
  cout << "# 2.digraph:\n";
  g2.print();
  DigraphIso iso(g1, g2);
  cout << "Is isomorph?: " << iso.is_iso() << endl;
}
