/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
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
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "MyTestSuite.h", 7, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 9, "test_SimpleDigraph_Constructor" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_Constructor(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_Constructor;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 21, "test_SimpleDigraph_METHODS_add_node" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_add_node(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_node;

static class TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 34, "test_SimpleDigraph_METHODS_add_edge_AND_is_edge" ) {}
 void runTest() { suite_MyTestSuite.test_SimpleDigraph_METHODS_add_edge_AND_is_edge(); }
} testDescription_suite_MyTestSuite_test_SimpleDigraph_METHODS_add_edge_AND_is_edge;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
