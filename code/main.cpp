#include "digraph.h"
#include "exceptions.h"
using namespace std;

const char *usage = R"EOF(Usage help:
)EOF";

int main(int argc, char **argv) {
  cout << "Hello, World!" << endl;

  if (argc == 1) {
    cout << usage;
    return 0;
  }

  try {

    // ...

  } catch (exception &e) {
    cout << "Exception: " << e.what() << endl;
    return 1;
  } catch (...) {
    cout << "Unknow error!" << endl;
    return 1;
  }
  return 0;
}
