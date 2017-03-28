#ifndef SEMILOG_H
#define SEMILOG_H

#include <fstream>
#include <iostream>

struct SemiLog {
  bool log = false, logtofile = false;
  std::ofstream log_file;
  void open_logfile(std::string fn = "log.txt");
  // ~SemiLog() {
  //   std::cout << "Log file closed" << std::endl;
  //   log_file.close();
  // }
};

template <class T> SemiLog &operator<<(SemiLog &sl, T x) {
  if (sl.log) {
    std::cout << x;
  }
  if (sl.logtofile) {
    sl.log_file << x;
  }
  return sl;
}

SemiLog &
operator<<(SemiLog &sl,
           std::basic_ostream<char> &(*func)(std::basic_ostream<char> &));

#endif /* end of include guard: SEMILOG_H */
