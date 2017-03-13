#include "semiiso.h"
#include <fstream>
using namespace std;

const char *usage = R"EOF(Usage help:
semi iso f1 f2 -- test isomorphic for semilattices from file f1 and f2
semi tos f1 f2 -- convert digraph (file f1) to semilattice (file f2)
)EOF";

int main(int argc, char **argv) {

  if (argc == 1) {
    cout << usage;
    return 0;
  }

  try {

    string cmd = argv[1];

    if (cmd == "iso") {
      if (argc < 4) {
        cout << "too few arguments" << endl;
        return 1;
      }

      Semilattice<int> s1, s2;
      s1 = Semilattice<int>::from_file(argv[2]);
      s2 = Semilattice<int>::from_file(argv[3]);

      cout << is_isomorphic(s1, s2) << endl;
      return 0;
    }

    else if (cmd == "tos") {
      return 0;
    } else {
      cout << "undefined command" << endl;
      cout << usage;
      return 1;
    }

  } catch (exception &e) {
    cout << "Exception: " << e.what() << endl;
    return 1;
  } catch (...) {
    cout << "Unknow error!" << endl;
    return 1;
  }
  return 0;
}
