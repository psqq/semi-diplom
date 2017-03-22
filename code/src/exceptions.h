#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class SimpleDigraph;

class GeneralException : public std::exception {
protected:
  std::string msg;

public:
  explicit GeneralException(std::string amsg = "");
  virtual const char *what() const throw();
};

class WrongSizeException : public GeneralException {
public:
  explicit WrongSizeException(std::string amsg = "") : GeneralException(amsg) {}
};

class BufferLimitException : public GeneralException {
public:
  BufferLimitException(std::string amsg, int new_max_n, int max_n,
                       int buffer_limit);
};

// class SimpleSemilatticeElementDoesNotExist : public GeneralException {
// public:
//   SimpleSemilatticeElementDoesNotExist(int el);
// };

class SimpleDigraphException : public GeneralException {
public:
  SimpleDigraphException(SimpleDigraph *g = nullptr, std::string amsg = "");
};

template <class T>
class PathDontFoundException : public SimpleDigraphException {
public:
  PathDontFoundException(T from, T to);
};

template class PathDontFoundException<int>;
template class PathDontFoundException<std::string>;

class SimpleDigraphNodeDoesNotExistEception : public SimpleDigraphException {
public:
  SimpleDigraphNodeDoesNotExistEception(SimpleDigraph *g, int node);
};

class SimpleDigraphBufferLimitException : public SimpleDigraphException {
public:
  SimpleDigraphBufferLimitException(SimpleDigraph *g, int new_max_n, int max_n,
                                    int buffer_limit);
};

#endif /* end of include guard: EXCEPTIONS_H */
