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
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "MyTestSuite.h", 13, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 18, "test_SimpleDigraph_Constructor" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_Constructor(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 31, "test_SimpleDigraph_METHODS_add_node" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_add_node(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 45, "test_SimpleDigraph_METHODS_add_edge_AND_is_edge" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_add_edge_AND_is_edge(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_successsors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_successsors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 72, "test_SimpleDigraph_METHODS_successsors" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_successsors(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_successsors;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_predecessors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_predecessors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 81, "test_SimpleDigraph_METHODS_predecessors" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_predecessors(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_predecessors;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_shortest_path_length : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_shortest_path_length() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 90, "test_SimpleDigraph_METHODS_shortest_path_length" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_shortest_path_length(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_shortest_path_length;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_is_tree_with_root : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_is_tree_with_root() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 112, "test_SimpleDigraph_METHODS_is_tree_with_root" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_is_tree_with_root(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_is_tree_with_root;

static class TestDescription_suite_MyTestSuite_test_Digraph_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_Constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 126, "test_Digraph_Constructor" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_Constructor(); }
} testDescription_suite_MyTestSuite_test_Digraph_Constructor;

static class TestDescription_suite_MyTestSuite_test_Digraph_get_nodes_of_empty_graph : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_get_nodes_of_empty_graph() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 142, "test_Digraph_get_nodes_of_empty_graph" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_get_nodes_of_empty_graph(); }
} testDescription_suite_MyTestSuite_test_Digraph_get_nodes_of_empty_graph;

static class TestDescription_suite_MyTestSuite_test_Digraph_from_string : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_from_string() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 147, "test_Digraph_from_string" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_from_string(); }
} testDescription_suite_MyTestSuite_test_Digraph_from_string;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_add_edge_AND_is_edge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_add_edge_AND_is_edge() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 165, "test_Digraph_METHODS_add_edge_AND_is_edge" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_add_edge_AND_is_edge(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_add_edge_AND_is_edge;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_successsors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_successsors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 194, "test_Digraph_METHODS_successsors" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_successsors(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_successsors;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_predecessors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_predecessors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 203, "test_Digraph_METHODS_predecessors" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_predecessors(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_predecessors;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_shortest_path_length : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_shortest_path_length() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 212, "test_Digraph_METHODS_shortest_path_length" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_shortest_path_length(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_shortest_path_length;

static class TestDescription_suite_MyTestSuite_test_Digraph_METHODS_is_tree_with_root : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Digraph_METHODS_is_tree_with_root() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 235, "test_Digraph_METHODS_is_tree_with_root" ) {}
 void runTest() { suite_MyTestSuite.test_Digraph_METHODS_is_tree_with_root(); }
} testDescription_suite_MyTestSuite_test_Digraph_METHODS_is_tree_with_root;

static class TestDescription_suite_MyTestSuite_test_SimpleSemilattice_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleSemilattice_Constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 249, "test_SimpleSemilattice_Constructor" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleSemilattice_Constructor(); }
} testDescription_suite_MyTestSuite_test_SimpleSemilattice_Constructor;

static class TestDescription_suite_MyTestSuite_test_Semilattice_from_string : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Semilattice_from_string() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 257, "test_Semilattice_from_string" ) {}
 void runTest() { suite_MyTestSuite.test_Semilattice_from_string(); }
} testDescription_suite_MyTestSuite_test_Semilattice_from_string;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_to_digraph : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_to_digraph() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 293, "test_FUNCTION_to_digraph" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_to_digraph(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_to_digraph;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_inf_for_digraph : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_inf_for_digraph() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 306, "test_FUNCTION_inf_for_digraph" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_inf_for_digraph(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_inf_for_digraph;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_to_semi : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_to_semi() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 326, "test_FUNCTION_to_semi" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_to_semi(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_to_semi;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_tree_is_isomorphic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_tree_is_isomorphic() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 340, "test_FUNCTION_tree_is_isomorphic" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_tree_is_isomorphic(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_tree_is_isomorphic;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 351, "test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_SIMPLE_AND_TREE_Semilattices;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 374, "test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_is_isomorphic_FOR_NON_TREE_Semilattices;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_find_branches_of_digraph : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_find_branches_of_digraph() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 391, "test_FUNCTION_find_branches_of_digraph" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_find_branches_of_digraph(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_find_branches_of_digraph;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_find_cyclic_vers : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_find_cyclic_vers() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 421, "test_FUNCTION_find_cyclic_vers" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_find_cyclic_vers(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_find_cyclic_vers;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_find_subgraph : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_find_subgraph() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 442, "test_FUNCTION_find_subgraph" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_find_subgraph(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_find_subgraph;

static class TestDescription_suite_MyTestSuite_test_FUNCTION_find_G1_and_G2_graphsh : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_FUNCTION_find_G1_and_G2_graphsh() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 466, "test_FUNCTION_find_G1_and_G2_graphsh" ) {}
 void runTest() { suite_MyTestSuite.test_FUNCTION_find_G1_and_G2_graphsh(); }
} testDescription_suite_MyTestSuite_test_FUNCTION_find_G1_and_G2_graphsh;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 493, "test_DigraphIso_simple_test_1" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_simple_test_1(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_simple_test_1;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 504, "test_DigraphIso_simple_test_2" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_simple_test_2(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_simple_test_2;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 520, "test_DigraphIso_simple_test_3" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_simple_test_3(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_simple_test_3;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_4() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 536, "test_DigraphIso_simple_test_4" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_simple_test_4(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_simple_test_4;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_5() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 557, "test_DigraphIso_simple_test_5" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_simple_test_5(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_simple_test_5;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_simple_test_6() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 565, "test_DigraphIso_simple_test_6" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_simple_test_6(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_simple_test_6;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_hard_test_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_hard_test_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 573, "test_DigraphIso_hard_test_1" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_hard_test_1(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_hard_test_1;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_hard_test_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_hard_test_2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 589, "test_DigraphIso_hard_test_2" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_hard_test_2(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_hard_test_2;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_FOR_initial_biection_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_FOR_initial_biection_1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 607, "test_DigraphIso_FOR_initial_biection_1" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_FOR_initial_biection_1(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_FOR_initial_biection_1;

static class TestDescription_suite_MyTestSuite_test_DigraphIso_FOR_initial_biection_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_DigraphIso_FOR_initial_biection_2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 627, "test_DigraphIso_FOR_initial_biection_2" ) {}
 void runTest() { suite_MyTestSuite.test_DigraphIso_FOR_initial_biection_2(); }
} testDescription_suite_MyTestSuite_test_DigraphIso_FOR_initial_biection_2;

static class TestDescription_suite_MyTestSuite_test_Inv3_full_inv3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_Inv3_full_inv3() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 647, "test_Inv3_full_inv3" ) {}
 void runTest() { suite_MyTestSuite.test_Inv3_full_inv3(); }
} testDescription_suite_MyTestSuite_test_Inv3_full_inv3;

static class TestDescription_suite_MyTestSuite_test_TreeEncoder : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_TreeEncoder() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 668, "test_TreeEncoder" ) {}
 void runTest() { suite_MyTestSuite.test_TreeEncoder(); }
} testDescription_suite_MyTestSuite_test_TreeEncoder;

static class TestDescription_suite_MyTestSuite_test_hard_test_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_hard_test_2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 714, "test_hard_test_2" ) {}
 void runTest() { suite_MyTestSuite.test_hard_test_2(); }
} testDescription_suite_MyTestSuite_test_hard_test_2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
