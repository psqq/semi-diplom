#include "cxxopts.hpp"
#include "digraph.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  int argc2 = argc;

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

    options.parse(argc2, argv);

    istream *insp = &cin;
    ostream *outsp = &cout;
    ifstream fin;
    ofstream fout;

    if (options.count("input")) {
      string input_file_name = options["input"].as<string>();
      fin.open(input_file_name);
      insp = &fin;
    }
    if (options.count("output")) {
      string output_file_name = options["output"].as<string>();
      fout.open(output_file_name);
      outsp = &fout;
    }

    istream &ins = *insp;
    ostream &outs = *outsp;

    if (!ins.good()) {
      cout << "Error: input stream don't good!" << endl;
      return 1;
    }
    if (!outs.good()) {
      cout << "Error: output stream don't good!" << endl;
      return 1;
    }

    if (argc == 1 || options.count("help")) {
      cout << argc << endl;
      cout << options.count("help") << endl;
      cout << options.help({"", "digraph", "semilattice"}) << std::endl;
      return 0;
    }

    if (options.count("to-semi")) {
      digraph g;
      g.load_from_stream(ins);
      Semilattice semi = g.to_semi();
      outs << semi.to_text();
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
    return 1;
  } catch (...) {
    cout << "Unknow error!" << endl;
    return 1;
  }

  return 0;
}
