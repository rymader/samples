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
#include "/home/mader036/3081/group/repo-group-Bluebirds/project/src/ast_tests.h"

static ScannerTestSuite suite_ScannerTestSuite;

static CxxTest::List Tests_ScannerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "ast_tests.h", 12, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_suite_ScannerTestSuite_test_sample_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_sample_1() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 82, "test_sample_1" ) {}
 void runTest() { suite_ScannerTestSuite.test_sample_1(); }
} testDescription_suite_ScannerTestSuite_test_sample_1;

static class TestDescription_suite_ScannerTestSuite_test_sample_2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_sample_2() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 84, "test_sample_2" ) {}
 void runTest() { suite_ScannerTestSuite.test_sample_2(); }
} testDescription_suite_ScannerTestSuite_test_sample_2;

static class TestDescription_suite_ScannerTestSuite_test_sample_3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_sample_3() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 86, "test_sample_3" ) {}
 void runTest() { suite_ScannerTestSuite.test_sample_3(); }
} testDescription_suite_ScannerTestSuite_test_sample_3;

static class TestDescription_suite_ScannerTestSuite_test_sample_4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_sample_4() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 88, "test_sample_4" ) {}
 void runTest() { suite_ScannerTestSuite.test_sample_4(); }
} testDescription_suite_ScannerTestSuite_test_sample_4;

static class TestDescription_suite_ScannerTestSuite_test_sample_5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_sample_5() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 90, "test_sample_5" ) {}
 void runTest() { suite_ScannerTestSuite.test_sample_5(); }
} testDescription_suite_ScannerTestSuite_test_sample_5;

static class TestDescription_suite_ScannerTestSuite_test_sample_6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_sample_6() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 92, "test_sample_6" ) {}
 void runTest() { suite_ScannerTestSuite.test_sample_6(); }
} testDescription_suite_ScannerTestSuite_test_sample_6;

static class TestDescription_suite_ScannerTestSuite_test_forest_loss : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_forest_loss() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 94, "test_forest_loss" ) {}
 void runTest() { suite_ScannerTestSuite.test_forest_loss(); }
} testDescription_suite_ScannerTestSuite_test_forest_loss;

static class TestDescription_suite_ScannerTestSuite_test_Program : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_Program() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 136, "test_Program" ) {}
 void runTest() { suite_ScannerTestSuite.test_Program(); }
} testDescription_suite_ScannerTestSuite_test_Program;

static class TestDescription_suite_ScannerTestSuite_test_ComplexMatrixAssignDecl : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_ComplexMatrixAssignDecl() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 139, "test_ComplexMatrixAssignDecl" ) {}
 void runTest() { suite_ScannerTestSuite.test_ComplexMatrixAssignDecl(); }
} testDescription_suite_ScannerTestSuite_test_ComplexMatrixAssignDecl;

static class TestDescription_suite_ScannerTestSuite_test_SimpleMatrixAssignDecl : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_SimpleMatrixAssignDecl() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 142, "test_SimpleMatrixAssignDecl" ) {}
 void runTest() { suite_ScannerTestSuite.test_SimpleMatrixAssignDecl(); }
} testDescription_suite_ScannerTestSuite_test_SimpleMatrixAssignDecl;

static class TestDescription_suite_ScannerTestSuite_test_IntKwdDecl : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_IntKwdDecl() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 145, "test_IntKwdDecl" ) {}
 void runTest() { suite_ScannerTestSuite.test_IntKwdDecl(); }
} testDescription_suite_ScannerTestSuite_test_IntKwdDecl;

static class TestDescription_suite_ScannerTestSuite_test_FloatKwdDecl : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_FloatKwdDecl() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 148, "test_FloatKwdDecl" ) {}
 void runTest() { suite_ScannerTestSuite.test_FloatKwdDecl(); }
} testDescription_suite_ScannerTestSuite_test_FloatKwdDecl;

static class TestDescription_suite_ScannerTestSuite_test_StringKwdDecl : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_StringKwdDecl() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 151, "test_StringKwdDecl" ) {}
 void runTest() { suite_ScannerTestSuite.test_StringKwdDecl(); }
} testDescription_suite_ScannerTestSuite_test_StringKwdDecl;

static class TestDescription_suite_ScannerTestSuite_test_BlockStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_BlockStmt() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 154, "test_BlockStmt" ) {}
 void runTest() { suite_ScannerTestSuite.test_BlockStmt(); }
} testDescription_suite_ScannerTestSuite_test_BlockStmt;

static class TestDescription_suite_ScannerTestSuite_test_IfStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_IfStmt() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 157, "test_IfStmt" ) {}
 void runTest() { suite_ScannerTestSuite.test_IfStmt(); }
} testDescription_suite_ScannerTestSuite_test_IfStmt;

static class TestDescription_suite_ScannerTestSuite_test_IfElseStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_IfElseStmt() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 160, "test_IfElseStmt" ) {}
 void runTest() { suite_ScannerTestSuite.test_IfElseStmt(); }
} testDescription_suite_ScannerTestSuite_test_IfElseStmt;

static class TestDescription_suite_ScannerTestSuite_test_MatrixAssignStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_MatrixAssignStmt() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 163, "test_MatrixAssignStmt" ) {}
 void runTest() { suite_ScannerTestSuite.test_MatrixAssignStmt(); }
} testDescription_suite_ScannerTestSuite_test_MatrixAssignStmt;

static class TestDescription_suite_ScannerTestSuite_test_PrintStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_PrintStmt() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 166, "test_PrintStmt" ) {}
 void runTest() { suite_ScannerTestSuite.test_PrintStmt(); }
} testDescription_suite_ScannerTestSuite_test_PrintStmt;

static class TestDescription_suite_ScannerTestSuite_test_ForStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_ForStmt() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 169, "test_ForStmt" ) {}
 void runTest() { suite_ScannerTestSuite.test_ForStmt(); }
} testDescription_suite_ScannerTestSuite_test_ForStmt;

static class TestDescription_suite_ScannerTestSuite_test_AssignStmt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_AssignStmt() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 172, "test_AssignStmt" ) {}
 void runTest() { suite_ScannerTestSuite.test_AssignStmt(); }
} testDescription_suite_ScannerTestSuite_test_AssignStmt;

static class TestDescription_suite_ScannerTestSuite_test_AndExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_AndExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 175, "test_AndExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_AndExpr(); }
} testDescription_suite_ScannerTestSuite_test_AndExpr;

static class TestDescription_suite_ScannerTestSuite_test_OrExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_OrExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 178, "test_OrExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_OrExpr(); }
} testDescription_suite_ScannerTestSuite_test_OrExpr;

static class TestDescription_suite_ScannerTestSuite_test_AddExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_AddExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 181, "test_AddExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_AddExpr(); }
} testDescription_suite_ScannerTestSuite_test_AddExpr;

static class TestDescription_suite_ScannerTestSuite_test_MultExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_MultExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 184, "test_MultExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_MultExpr(); }
} testDescription_suite_ScannerTestSuite_test_MultExpr;

static class TestDescription_suite_ScannerTestSuite_test_SubExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_SubExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 187, "test_SubExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_SubExpr(); }
} testDescription_suite_ScannerTestSuite_test_SubExpr;

static class TestDescription_suite_ScannerTestSuite_test_DivExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_DivExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 190, "test_DivExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_DivExpr(); }
} testDescription_suite_ScannerTestSuite_test_DivExpr;

static class TestDescription_suite_ScannerTestSuite_test_EqualsExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_EqualsExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 193, "test_EqualsExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_EqualsExpr(); }
} testDescription_suite_ScannerTestSuite_test_EqualsExpr;

static class TestDescription_suite_ScannerTestSuite_test_LessEqualExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_LessEqualExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 196, "test_LessEqualExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_LessEqualExpr(); }
} testDescription_suite_ScannerTestSuite_test_LessEqualExpr;

static class TestDescription_suite_ScannerTestSuite_test_GreaterEqualExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_GreaterEqualExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 199, "test_GreaterEqualExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_GreaterEqualExpr(); }
} testDescription_suite_ScannerTestSuite_test_GreaterEqualExpr;

static class TestDescription_suite_ScannerTestSuite_test_NotEqualExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_NotEqualExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 202, "test_NotEqualExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_NotEqualExpr(); }
} testDescription_suite_ScannerTestSuite_test_NotEqualExpr;

static class TestDescription_suite_ScannerTestSuite_test_LessExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_LessExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 205, "test_LessExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_LessExpr(); }
} testDescription_suite_ScannerTestSuite_test_LessExpr;

static class TestDescription_suite_ScannerTestSuite_test_GreaterExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_GreaterExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 208, "test_GreaterExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_GreaterExpr(); }
} testDescription_suite_ScannerTestSuite_test_GreaterExpr;

static class TestDescription_suite_ScannerTestSuite_test_IntExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_IntExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 211, "test_IntExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_IntExpr(); }
} testDescription_suite_ScannerTestSuite_test_IntExpr;

static class TestDescription_suite_ScannerTestSuite_test_FloatExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_FloatExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 214, "test_FloatExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_FloatExpr(); }
} testDescription_suite_ScannerTestSuite_test_FloatExpr;

static class TestDescription_suite_ScannerTestSuite_test_StringExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_StringExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 217, "test_StringExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_StringExpr(); }
} testDescription_suite_ScannerTestSuite_test_StringExpr;

static class TestDescription_suite_ScannerTestSuite_test_NotExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_NotExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 220, "test_NotExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_NotExpr(); }
} testDescription_suite_ScannerTestSuite_test_NotExpr;

static class TestDescription_suite_ScannerTestSuite_test_LetExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_LetExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 223, "test_LetExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_LetExpr(); }
} testDescription_suite_ScannerTestSuite_test_LetExpr;

static class TestDescription_suite_ScannerTestSuite_test_IfElseExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_IfElseExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 226, "test_IfElseExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_IfElseExpr(); }
} testDescription_suite_ScannerTestSuite_test_IfElseExpr;

static class TestDescription_suite_ScannerTestSuite_test_ExprExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_ExprExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 229, "test_ExprExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_ExprExpr(); }
} testDescription_suite_ScannerTestSuite_test_ExprExpr;

static class TestDescription_suite_ScannerTestSuite_test_VarParenExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_VarParenExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 232, "test_VarParenExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_VarParenExpr(); }
} testDescription_suite_ScannerTestSuite_test_VarParenExpr;

static class TestDescription_suite_ScannerTestSuite_test_VarExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_VarExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 235, "test_VarExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_VarExpr(); }
} testDescription_suite_ScannerTestSuite_test_VarExpr;

static class TestDescription_suite_ScannerTestSuite_test_MatrixVarExpr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_ScannerTestSuite_test_MatrixVarExpr() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 238, "test_MatrixVarExpr" ) {}
 void runTest() { suite_ScannerTestSuite.test_MatrixVarExpr(); }
} testDescription_suite_ScannerTestSuite_test_MatrixVarExpr;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
