#include <string>
using namespace std;

template <class T> class A {
public:
  T x;
};

template <class T> class B {
public:
  T x, y;
};

template <class T> B<T> f(A<T> &a) {
  B<T> b;
  b.x = b.y = a.x;
  return b;
}

template class A<string>;
template class A<int>;
template class B<string>;
template class B<int>;

int main() {
  A<string> a = {"hello"};
  B<string> b = f(a);

  A<int> a1 = {111};
  B<int> b1 = f(a1);
}
