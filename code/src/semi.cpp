#include "main.h"
#include "semiiso.h"
#include "utils.h"
#include <cstring>
#include <fstream>
#include <set>
using namespace std;

const char *usage_ru = R"EOF(Usage help:
semi iso f1 f2 - проверить полурешетки из файлов f1 и f2 на изоморфизм.
semi tos f1 - преобразует орграф из файла f1 в полурешетку.
semi tog f1 - преобразует полурешетку из файла f1 в орграф.
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

vector<string> cmd_flags, cmd_args;
int count_cmd_args = 0;
string cmd;

void parse_args(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      cmd_flags.push_back(argv[i]);
    } else {
      if (cmd == "") {
        cmd = argv[i];
      } else {
        cmd_args.push_back(argv[i]);
      }
    }
  }
  count_cmd_args = cmd_args.size();
}

template <class T> int iso() {
  if (count_cmd_args < 2) {
    cout << "too few arguments" << endl;
    return 1;
  }

  Semilattice<T> s1, s2;
  s1 = Semilattice<T>::from_file(cmd_args[0]);
  s2 = Semilattice<T>::from_file(cmd_args[1]);

  cout << is_isomorphic(s1, s2) << endl;
  return 0;
}

template <class T> int tos() {
  if (count_cmd_args < 2) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Digraph<T> g = Digraph<T>::from_file(cmd_args[0]);
  Semilattice<T> s = to_semi(g);
  ofstream f(cmd_args[1]);
  f << s.to_string();
  return 0;
}

int main(int argc, char **argv) {

  parse_args(argc, argv);
  set<string> all_cmds = {"iso", "tos", "tog", "giso"};

  // cout << "cmd: " << cmd << endl;
  // cout << "cmd_args: " << cmd_args << endl;

  if (argc == 1 || all_cmds.find(cmd) == all_cmds.end()) {
    cout << usage_ru;
    return 0;
  }

  // cout << "log_mode: " << log_mode << endl;

  for (string flag : cmd_flags) {
    if (flag == "-fast") {
      fast_mode = true;
    } else if (flag == "-int") {
      int_mode = true;
    } else if (flag == "-log") {
      log_mode = true;
    }
  }

  if (log_mode) {
    semi_log.open("log.txt");
  }

  try {

    if (!fast_mode) {
      if (cmd == "iso") {
        if (int_mode) {
          return iso<int>();
        } else {
          return iso<string>();
        }
        return 0;
      } else if (cmd == "tos") {
        if (int_mode) {
          return tos<int>();
        } else {
          return tos<string>();
        }
        return 0;
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
