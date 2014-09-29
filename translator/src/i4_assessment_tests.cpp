/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#define _CXXTEST_ABORT_TEST_ON_FAIL
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
bool suite_ScannerTestSuite_init = false;
#include "/home/mader036/3081/group/repo-group-Bluebirds/project/src/i4_assessment_tests.h"

static ScannerTestSuite suite_ScannerTestSuite;

static CxxTest::List Tests_ScannerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "i4_assessment_tests.h", 12, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_suite_ScannerTestSuite_test_simple_4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_simple_4() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 90, "test_simple_4" ) {}
 void runTest() { suite_ScannerTestSuite.test_simple_4(); }
} testDescription_suite_ScannerTestSuite_test_simple_4;

static class TestDescription_suite_ScannerTestSuite_test_simple_5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_simple_5() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 91, "test_simple_5" ) {}
 void runTest() { suite_ScannerTestSuite.test_simple_5(); }
} testDescription_suite_ScannerTestSuite_test_simple_5;

static class TestDescription_suite_ScannerTestSuite_test_simple_6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_simple_6() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 92, "test_simple_6" ) {}
 void runTest() { suite_ScannerTestSuite.test_simple_6(); }
} testDescription_suite_ScannerTestSuite_test_simple_6;

static class TestDescription_suite_ScannerTestSuite_test_simple_7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_simple_7() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 93, "test_simple_7" ) {}
 void runTest() { suite_ScannerTestSuite.test_simple_7(); }
} testDescription_suite_ScannerTestSuite_test_simple_7;

static class TestDescription_suite_ScannerTestSuite_test_simple_8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_simple_8() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 94, "test_simple_8" ) {}
 void runTest() { suite_ScannerTestSuite.test_simple_8(); }
} testDescription_suite_ScannerTestSuite_test_simple_8;

static class TestDescription_suite_ScannerTestSuite_test_your_code_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_your_code_1() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 96, "test_your_code_1" ) {}
 void runTest() { suite_ScannerTestSuite.test_your_code_1(); }
} testDescription_suite_ScannerTestSuite_test_your_code_1;

static class TestDescription_suite_ScannerTestSuite_test_your_code_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_your_code_2() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 97, "test_your_code_2" ) {}
 void runTest() { suite_ScannerTestSuite.test_your_code_2(); }
} testDescription_suite_ScannerTestSuite_test_your_code_2;

static class TestDescription_suite_ScannerTestSuite_test_forest_loss : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_forest_loss() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 99, "test_forest_loss" ) {}
 void runTest() { suite_ScannerTestSuite.test_forest_loss(); }
} testDescription_suite_ScannerTestSuite_test_forest_loss;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
