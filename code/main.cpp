#include <iostream>
#include "cxxopts.hpp"
#include "digraph.h"
using namespace std;

int main(int argc, char* argv[])
{
  try
  {
    cxxopts::Options options(argv[0], " - command line options");

    options.add_options()
      ("i,input", "Input file", cxxopts::value<std::string>())
      ("o,output", "Output file", cxxopts::value<std::string>())
      ("positional",
        "Positional arguments: these are the arguments that are entered "
        "without an option", cxxopts::value<std::vector<std::string>>())
      ("help", "Print help")
      ;

    options.add_options("digraph")
      ("count-nodes", "print count nodes in graph")
      ("to-semi", "convert digraph to semilattice")
      ;

    options.add_options("semilattice")
      ("to-digraph", "convert semilattice to digraph")
      ("validate", "validate semillatice")
      ;

    options.parse_positional({"input", "output", "positional"});

    options.parse(argc, argv);

    if (options.count("count-nodes") && options.count("input")) {
      digraph g;
      g.load_from_file(options["input"].as<string>());
      cout << g.count_vertices() << endl;
      return 0;
    }

    if (argc == 1 || options.count("help"))
    {
      std::cout << options.help({"", "digraph", "semilattice"}) << std::endl;
      exit(0);
    }

    if (options.count("input"))
    {
      std::cout << "Input = " << options["input"].as<std::string>()
        << std::endl;
    }

    if (options.count("output"))
    {
      std::cout << "Output = " << options["output"].as<std::string>()
        << std::endl;
    }

  }
  catch (const cxxopts::OptionException& e)
  {
    std::cout << "error parsing options: " << e.what() << std::endl;
    exit(1);
  }
  catch (...)
  {
    cout << "Unknow error!" << endl;
    exit(1);
  }

  return 0;
}
