#include "main.h"
#include "semiiso.h"
#include "semilog.h"
#include "utils.h"
#include "inv3.h"
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <functional>
using namespace std;

const char *usage_ru = R"EOF(Usage help:
semi iso f1 f2 - проверить полурешетки из файлов f1 и f2 на изоморфизм.
semi tos f1 - преобразует орграф из файла f1 в полурешетку.
semi tog f1 - преобразует полурешетку из файла f1 в орграф.
semi giso f1 f2 - проверить орграфы из файлов f1 и f2 на изоморфизм.
semi todot f1 - преобразует орграф в формат .dot файл для graphviz.
semi inv3 s.txt - выводит инвариант 3 для полурешетки из файла s.txt.
semi ginv3 g.txt - выводит инвариант 3 для графа полурешетки из файла g.txt.
semi istree s.txt - является ли граф полурешетки деревом
semi gistree g.txt - тоже самое только для графа полурешетки
semi ccode g.txt - выводит канонический код графа

-speed - выводит время выполнения программы (в секундах): "speed: 0.023"

-log - добавьте этот флаг для ведения программой подробного лога. Все
данные будут записываться в файл log.txt. Если такой файл существует, то
он будет перезаписан.

-int - используйте этот флаг, когда все элементы - целые числа (включен по
умолчанию), иначе элементами будут строки.

-str - элементы графов и полурешеток - строки.

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

#define USE_FILE_FOR_OUTPUT_IF_EXISTS(cmd_args_index, osvar) \
  ostream *osvar ## _ost = &cout; \
  ofstream osvar ## _fout; \
  if (cmd_args_index < count_cmd_args) { \
    osvar ## _fout.open(cmd_args[cmd_args_index]); \
    osvar ## _ost = & osvar ## _fout; \
  } \
  ostream &osvar = *osvar ## _ost

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
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Digraph<T> g = Digraph<T>::from_file(cmd_args[0]);
  Semilattice<T> s = to_semi(g);

  USE_FILE_FOR_OUTPUT_IF_EXISTS(1, os);

  os << s.to_string();
  return 0;
}

template <class T> int tog() {
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Semilattice<T> s = Semilattice<T>::from_file(cmd_args[0]);
  Digraph<T> g = to_digraph(s);

  USE_FILE_FOR_OUTPUT_IF_EXISTS(1, os);

  os << g.to_string();
  return 0;
}

template <class T> int todot() {
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Digraph<T> g = Digraph<T>::from_file(cmd_args[0]);

  USE_FILE_FOR_OUTPUT_IF_EXISTS(1, os);

  os << R"EOF(digraph {
node [ shape=circle ];
// edge [ arrowhead="none" ];
rankdir = BT;
)EOF";
  set<T> used;
  for (auto p : g.edges()) {
    os << p.first << " -> " << p.second << endl;
    used.insert(p.first);
    used.insert(p.second);
  }
  for (auto v : g.nodes()) {
    if (used.find(v) != used.end())
      continue;
    os << v << endl;
  }
  os << "}" << endl;
  return 0;
}

template <class T> int inv3() {
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Semilattice<T> s = Semilattice<T>::from_file(cmd_args[0]);
  Digraph<T> g = to_digraph(s);

  USE_FILE_FOR_OUTPUT_IF_EXISTS(1, os);

  Inv3<T> inv3_for_g(g);

  os << inv3_for_g.get_full_inv3() << endl;
}

template <class T> int ginv3() {
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Digraph<T> g = Digraph<T>::from_file(cmd_args[0]);

  USE_FILE_FOR_OUTPUT_IF_EXISTS(1, os);

  Inv3<T> inv3_for_g(g);

  os << inv3_for_g.get_full_inv3() << endl;
}

template <class T> int istree() {
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Semilattice<T> s = Semilattice<T>::from_file(cmd_args[0]);
  Digraph<T> g = to_digraph(s);
  T r = find_root(g);

  USE_FILE_FOR_OUTPUT_IF_EXISTS(1, os);

  os << g.is_tree_with_root(r) << endl;
}

template <class T> int gistree() {
  if (count_cmd_args < 1) {
    cout << "too few arguments" << endl;
    return 1;
  }
  Digraph<T> g = Digraph<T>::from_file(cmd_args[0]);
  T r = find_root(g);

  USE_FILE_FOR_OUTPUT_IF_EXISTS(1, os);

  os << g.is_tree_with_root(r) << endl;
}

int main(int argc, char **argv) {
  parse_args(argc, argv);

  // cout << "cmd: " << cmd << endl;
  // cout << "cmd_args: " << cmd_args << endl;

  // cout << "log_mode: " << log_mode << endl;

  int_mode = true;

  for (string flag : cmd_flags) {
    if (flag == "-fast") {
      fast_mode = true;
    } else if (flag == "-int") {
      int_mode = true;
    } else if (flag == "-str") {
      int_mode = false;
    } else if (flag == "-log") {
      log_mode = true;
      semi_log.log = true;
    } else if (flag == "-logtofile") {
      log_mode = true;
      semi_log.logtofile = true;
      semi_log.open_logfile();
    }
  }

  // cout << "semi_log.log: " << semi_log.log << endl;
  // cout << "semi_log.logtofile: " << semi_log.logtofile << endl;
  // semi_log << "Hello, World!" << endl;

  try {

#define CMD(f) { #f, { f<int>, f<string> } }

    map<string, vector<function<int()>>> cmds = {
      CMD(iso), CMD(tos), CMD(tog), CMD(todot), CMD(inv3), CMD(ginv3),
      CMD(istree), CMD(gistree),
    };

#undef CMD

    if (cmds.find(cmd) == cmds.end()) {
      cout << "Command \"" << cmd << "\" not found. Usage:" << endl;
      cout << usage_ru;
      return 1;
    }

    if (fast_mode) {
      cout << "fast mode doesn't work." << endl;
    }

    int j = 0;
    if (int_mode == false) j = 1;
    return cmds[cmd][j]();

  } catch (exception &e) {
    cout << "Exception: " << e.what() << endl;
    return 1;
  } catch (...) {
    cout << "Unknow error!" << endl;
    return 1;
  }

  return 0;
}
