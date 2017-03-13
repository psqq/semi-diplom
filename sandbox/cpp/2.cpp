// Example program
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
using namespace std;

int main() {
  set<int> s1 = {1, 2, 3}, s2 = {3, 1, 2};
  cout << (s1 == s2) << endl;
  vector<int> v1 = {1, 2, 3}, v2 = {3, 1, 2};
  cout << (v1 == v2) << endl;
  v1 = {1, 2, 3}, v2 = {1, 2, 3};
  cout << (v1 == v2) << endl;
}
