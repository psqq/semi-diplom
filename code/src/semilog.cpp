#include "semilog.h"

void SemiLog::open_logfile(std::string fn) { log_file.open(fn); }

SemiLog &
operator<<(SemiLog &sl,
           std::basic_ostream<char> &(*func)(std::basic_ostream<char> &)) {
  if (sl.log) {
    std::cout << func;
  }
  if (sl.logtofile) {
    sl.log_file << func;
  }
  return sl;
}
