#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class SimpleDigraph;

class GeneralException : public std::exception {
protected:
  std::string msg;

public:
  GeneralException(std::string amsg = "");
  virtual const char *what() const throw();
};

class SimpleDigraphException : public GeneralException {
public:
  SimpleDigraphException(SimpleDigraph *g = nullptr, std::string amsg = "");
};

class SimpleDigraphPathDontFoundException : public SimpleDigraphException {
public:
  SimpleDigraphPathDontFoundException(SimpleDigraph *g, int from, int to);
};

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
