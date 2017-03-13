// Example program
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

function<int(int, int)> f1;

template <class T, class U> class A {
  function<int(T, U)> f;

public:
  A(function<int(T, U)> af = [](T x, U y) -> int { return 42; }) : f(af) {}
  int foo(T x, U y) { return f(x, y); }
};

int main() {
  // cout << "f1(2, 3) == '" << f1(2, 3) << "'" << endl;
  A<int, string> a([](auto x, auto y) {
    stringstream ss, ss2;
    ss << x << y;
    ss2 << ss.str();
    int t;
    ss2 >> t;
    return t;
  });
  cout << a.foo(12, "00") << endl;
}
