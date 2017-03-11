#include "digraph.h"
#include "exceptions.h"
#include <sstream>
using namespace std;

GeneralException::GeneralException(std::string amsg) : msg(amsg) {}

const char *GeneralException::what() const throw() { return msg.c_str(); }

SimpleDigraphException::SimpleDigraphException(SimpleDigraph *g,
                                               std::string amsg)
    : GeneralException(amsg) {}

SimpleDigraphPathDontFoundException::SimpleDigraphPathDontFoundException(
    SimpleDigraph *g, int from, int to) {
  stringstream ss;
  ss << "Dont fount path from node" << from << " to node " << to << ".";
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
