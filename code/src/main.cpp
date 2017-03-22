#include "semiiso.h"
#include <cstring>
#include <fstream>
using namespace std;

const char *usage_ru = R"EOF(Usage help:
semi iso f1 f2 - проверить полурешетки из файлов f1 и f2 на изоморфизм.
semi tos f1 - преобразует орграф из файла f1 в полурешетку.
semi giso f1 f2 - проверить орграфы из файлов f1 и f2 на изоморфизм.

-log - добавьте этот флаг для ведения программой подробного лога. Все
данные будут записываться в файл log.txt. Если такой файл существует, то
он будет перезаписан.

-int - используйте этот флаг, когда все элементы - целые числа, иначе элементами
будут строки.

-fast - этот флаг нужен для отключения различных проверок на ошибки. Также не
будут доступны произвольные имена для элементов орграфов и полурешеток. Все
элементы должны именоваться следующим образом: 0, 1, 2, ..., n-2, n-1,
где n - это размер орграфа или полурешетки.
)EOF";

bool fast_mode = false, int_mode = false, log_mode = false;

char *cmd;
int count_cmd_args;
char **cmd_argv;
ofstream semi_log;

template <class T> int iso() {
  if (count_cmd_args < 2) {
    cout << "too few arguments" << endl;
    return 1;
  }

  Semilattice<T> s1, s2;
  s1 = Semilattice<T>::from_file(cmd_argv[0]);
  s2 = Semilattice<T>::from_file(cmd_argv[1]);

  cout << is_isomorphic(s1, s2) << endl;
}

template <class T> int tos() {
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Digraph<T> g = Digraph<T>::from_file(cmd_argv[0]);
  Semilattice<T> s = to_semi(g);
}

int main(int argc, char **argv) {

  if (argc == 1) {
    cout << usage_ru;
    return 0;
  }

  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-fast") == 0) {
      fast_mode = true;
    } else if (strcmp(argv[i], "-int") == 0) {
      int_mode = true;
    } else if (strcmp(argv[i], "-log") == 0) {
      log_mode = true;
    }
  }

  if (log_mode) {
    semi_log.open("log.txt");
  }

  // cout << "fast_mode == " << fast_mode << endl;
  // cout << "int_mode == " << int_mode << endl;

  try {

    cmd = argv[1];
    count_cmd_args = argc - 2;
    cmd_argv = &argv[2];

    if (!fast_mode) {
      if (strcmp(cmd, "iso") == 0) {
        if (int_mode) {
          return iso<int>();
        } else {
          return iso<string>();
        }
        return 0;
      } else if (strcmp(cmd, "tos") == 0) {
        if (int_mode) {
          return tos<int>();
        } else {
          return tos<string>();
        }
        return 0;
      } else {
        cout << "undefined command" << endl;
        cout << usage_ru;
        return 1;
      }
    } else { // fast mode
      cout << "fast mode don't work" << endl;
      return 0;
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
