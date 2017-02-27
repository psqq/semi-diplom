#include "cxxopts.hpp"
#include "digraph.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  try {
    cxxopts::Options options(argv[0], " - command line options");

    // clang-format off
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
      ("g-inf", "comupte inf on digraph", cxxopts::value<std::string>())
      ;

    options.add_options("semilattice")
      ("to-digraph", "convert semilattice to digraph")
      ("validate", "validate semillatice")
      ;
    // clang-format on

    options.parse_positional({"input", "output", "positional"});

    options.parse(argc, argv);

    istream ins = cin;
    ostream outs = cout;
    digraph g;

    if (options.count("input")) {
      ins = ifstream(options["input"].as<string>());
    }
    if (options.count("output")) {
      outs = ofstream(options["output"].as<string>());
    }

    if (argc == 1 || options.count("help")) {
      cout << options.help({"", "digraph", "semilattice"}) << std::endl;
      return 0;
    }

    if (options.count("to-semi")) {
      g.load_from_stream(ins);
      return 0;
    }

    if (options.count("count-nodes") && options.count("input")) {
      digraph g;
      g.load_from_stream(ins);
      outs << g.count_vertices() << endl;
      return 0;
    }

    if (options.count("g-inf")) {
      digraph g;
      g.load_from_stream(ins);
      string g_inf = options["g-inf"].as<string>();
      stringstream ss(g_inf);
      int a, b;
      char ch;
      ss >> a >> ch >> b;
      outs << g.inf(a, b) << endl;
      return 0;
    }

    /*
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
    */
  } catch (const cxxopts::OptionException &e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    exit(1);
  } catch (...) {
    cout << "Unknow error!" << endl;
    exit(1);
  }

  return 0;
}
