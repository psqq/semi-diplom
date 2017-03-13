/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "MyTestSuite.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "MyTestSuite.h", 10, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "test_SimpleDigraph_Constructor" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_Constructor(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 28, "test_SimpleDigraph_METHODS_add_node" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_add_node(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 42, "test_SimpleDigraph_METHODS_add_edge_AND_is_edge" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_add_edge_AND_is_edge(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_successsors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_successsors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 69, "test_SimpleDigraph_METHODS_successsors" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_successsors(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_successsors;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_predecessors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_predecessors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 78, "test_SimpleDigraph_METHODS_predecessors" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_predecessors(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_predecessors;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_shortest_path_length : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_shortest_path_length() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 87, "test_SimpleDigraph_METHODS_shortest_path_length" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_shortest_path_length(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_shortest_path_length;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_is_tree_with_root : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_is_tree_with_root() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 109, "test_SimpleDigraph_METHODS_is_tree_with_root" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_is_tree_with_root(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_is_tree_with_root;

static class TestDescription_suite_MyTestSuite_test_Digraph_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_Constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 123, "test_Digraph_Constructor" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_Constructor(); }
} testDescription_suite_MyTestSuite_test_Digraph_Constructor;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_add_edge_AND_is_edge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_add_edge_AND_is_edge() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 139, "test_Digraph_METHODS_add_edge_AND_is_edge" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_add_edge_AND_is_edge(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_add_edge_AND_is_edge;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_successsors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_successsors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 168, "test_Digraph_METHODS_successsors" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_successsors(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_successsors;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_predecessors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_predecessors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 177, "test_Digraph_METHODS_predecessors" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_predecessors(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_predecessors;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_shortest_path_length : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_shortest_path_length() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 186, "test_Digraph_METHODS_shortest_path_length" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_shortest_path_length(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_shortest_path_length;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_is_tree_with_root : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_is_tree_with_root() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 209, "test_Digraph_METHODS_is_tree_with_root" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_is_tree_with_root(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_is_tree_with_root;

static class TestDescription_suite_MyTestSuite_test_SimpleSemilattice_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleSemilattice_Constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 223, "test_SimpleSemilattice_Constructor" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleSemilattice_Constructor(); }
} testDescription_suite_MyTestSuite_test_SimpleSemilattice_Constructor;

static class TestDescription_suite_MyTestSuite_test_Semilattice_from_string : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Semilattice_from_string() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 231, "test_Semilattice_from_string" ) {}
 void runTest() { suite_MyTestSuite.test_Semilattice_from_string(); }
} testDescription_suite_MyTestSuite_test_Semilattice_from_string;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_to_digraph : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_to_digraph() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 267, "test_FUNCTION_to_digraph" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_to_digraph(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_to_digraph;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_inf_for_digraph : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_inf_for_digraph() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 280, "test_FUNCTION_inf_for_digraph" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_inf_for_digraph(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_inf_for_digraph;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_to_semi : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_to_semi() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 300, "test_FUNCTION_to_semi" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_to_semi(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_to_semi;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_tree_is_isomorphic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_tree_is_isomorphic() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 314, "test_FUNCTION_tree_is_isomorphic" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_tree_is_isomorphic(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_tree_is_isomorphic;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 325, "test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 348, "test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
