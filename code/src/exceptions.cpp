#include "digraph.h"
#include "exceptions.h"
#include "semilattice.h"
#include <sstream>
using namespace std;

GeneralException::GeneralException(std::string amsg) : msg(amsg) {}

const char *GeneralException::what() const throw() { return msg.c_str(); }

SimpleDigraphException::SimpleDigraphException(SimpleDigraph *g,
                                               std::string amsg)
    : GeneralException(amsg) {}

template <class T>
PathDontFoundException<T>::PathDontFoundException(T from, T to) {
  stringstream ss;
  ss << "Don't found path from node " << from << " to node " << to << ".";
  msg = ss.str();
}

SimpleDigraphNodeDoesNotExistEception::SimpleDigraphNodeDoesNotExistEception(
    SimpleDigraph *g, int node) {
  stringstream ss;
  ss << "Node " << node << " does not exist in digraph of size "
     << g->number_of_nodes() << ".";
  msg = ss.str();
}

SimpleDigraphBufferLimitException::SimpleDigraphBufferLimitException(
    SimpleDigraph *g, int max_n, int new_max_n, int buffer_limit) {
  stringstream ss;
  ss << "Buffer Size Limit Exceeded. Current buffer size: " << max_n
     << ". New buffer size: " << new_max_n << ". Buffer limit: " << buffer_limit
     << endl;
  msg = ss.str();
}

BufferLimitException::BufferLimitException(string amsg, int max_n,
                                           int new_max_n, int buffer_limit) {
  stringstream ss;
  ss << amsg << " Current buffer size: " << max_n
     << ". New buffer size: " << new_max_n << ". Buffer limit: " << buffer_limit
     << endl;
  msg = ss.str();
}

// SimpleSemilatticeElementDoesNotExist::SimpleSemilatticeElementDoesNotExist(
//     SimpleSemilattice *s, int el) {
//   stringstream ss;
//   ss << "Element " << el << " does not exist in semilattice of size "
//      << s->size() << ".";
//   msg = ss.str();
// }
