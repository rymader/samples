
#include <cxxtest/TestSuite.h>

#include "readInput.h"
#include "scanner.h"
#include "regex.h"
#include <stdio.h>
using namespace std ;

class ScannerTestSuite : public CxxTest::TestSuite 
{
	public:
    /* A Scanner object is created in the test_setup_code method.
       This is a test, beginning with "test_", so that it is executed
       by the testing framework.  The scanner is used in some tests of
       the method "scan".
     */
    Scanner *s ;
    void test_setup_code ( ) {
        s = new Scanner() ;
    }


    // Tests for components and functions used by "scan"
    // --------------------------------------------------

    /* You may need to write several tests to adequately test the
       functions that are called from "scan".  Once you are confident
       that the components used by "scan" work properly, then you can
       run tests on the "scan" method itself.
    */

    // Here you should place tests for these other functions.

	void test_consume_block_Comments()
	{
		//printf("cbc\n");
		char * text = "\n\n  ";
		regex_t *blockComment = makeRegex ("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/");
		regex_t *whiteSpace = makeRegex("^[\n\t\r ]+");	
		regex_t *lineComment = makeRegex ("^//[^\n]*\n");
		int chars = s->consumeWhiteSpaceAndBlockComments (whiteSpace,blockComment, lineComment, text);
		TS_ASSERT_EQUALS(chars, 4);
	}

	void test_add_to_list2()
	{
		//printf("TEST2!!!!!!\n");
		s = new Scanner();
		(*s).tokenListHead = new Token(endOfFile, "", NULL);
		Token * t  = new Token(intKwd, "9", NULL);
		Token tk = *t;
		s->addToList(t);
		TS_ASSERT_EQUALS((*(*s).tokenListHead).terminal, intKwd);
	}

	void test_add_to_list3()
	{
		//printf("TEST3!!!!!!\n");
		s = new Scanner();
		(*s).tokenListHead = new Token(endOfFile, "", NULL);
		Token * t  = new Token(intKwd, "9", NULL);
		Token tk = *t;
		s->addToList(t);
		t  = new Token(floatKwd, "9.99", NULL);
		tk = *t;
		s->addToList(t);
		TS_ASSERT_EQUALS((*(*s).tokenListHead).terminal, intKwd);
	}


	void test_scan1 ( ) 
   	{
        Token *tks = s->scan ("$ abc 1  ") ;
        TS_ASSERT (tks != NULL) ;
        //TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "$");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, variableName) ;
        TS_ASSERT_EQUALS (tks->lexeme, "abc");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, intConst) ;
        TS_ASSERT_EQUALS (tks->lexeme, "1");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    /* Below is one of the tests for these components in the project
       solution created by your instructor..  It uses a helper
       function function called "tokenMaker_tester", which you have
       not been given.  You are expected to design your own components
       for "scan" and your own mechanisms for easily testing them.
	
        void xtest_TokenMaker_leftCurly ( ) {
            tokenMaker_tester ("{ ", "^\\{", leftCurly, "{" ) ;
        }

        Note that this test is here named "xtest_Token..." The leading
        "x" is so that cxxTest doesn't scan the line above and think
        it is an actual test that isn't commented out.  cxxTest is
        very simple and doesn't even process block comments.
    */


    /* You must have at least one separate test case for each terminal
       symbol.  Thus, you need a test that will pass or fail based
       solely on the regular expression (and its corresponding code)
       for each terminal symbol.

       This requires a test case for each element of the enumerated
       type tokenType.  This may look something like the sample test
       shown in the comment above.
    */

    void test_tokenMaker(const char* input, const char* test, int len) 
    {
		regex_t *re = makeRegex(input);
		TS_ASSERT (re);
		int numMatchedChars = matchRegex (re, test);
		TS_ASSERT_EQUALS (numMatchedChars, len);
    }
	
	void test_tokenMaker_intKwd()
	{
		test_tokenMaker("^Integer","Integer",7);
	}
    
    void test_tokenMaker_floatKwd () 
    {
		test_tokenMaker("^Float", "Float", 5);
    }

    void test_tokenMaker_stringKwd () 
    {
		test_tokenMaker("^String", "String", 6);
		regex_t *re = makeRegex("^String");
    }

    void test_tokenMaker_matrixKwd () 
    {
		test_tokenMaker("^Matrix", "Matrix", 6);
	}

    void test_tokenMaker_letKwd () 
    {
		test_tokenMaker("^let", "let", 3);
    }

    void test_tokenMaker_ifKwd () 
    {
		test_tokenMaker("^if", "if", 2);
    }


    void test_tokenMaker_inKwd () 
    {
		test_tokenMaker("^in","in",2);
    }

    void test_tokenMaker_endKwd () 
    {
		test_tokenMaker("^end", "end", 3);
    }

    void test_tokenMaker_thenKwd () 
    {
		test_tokenMaker("^then","then",4);
    }

    void test_tokenMaker_elseKwd () 
    {
		test_tokenMaker("^else","else",4);
    }

    void test_tokenMaker_toKwd () 
    {
		test_tokenMaker("^to","to",2);
    }

    void test_tokenMaker_printKwd () 
    {
		test_tokenMaker("^print","print",5);
    }

    void test_tokenMaker_assign () 
    {
		test_tokenMaker("^=","=",1);
    }

    void test_tokenMaker_plusSign () 
    {
		test_tokenMaker("^\\+", "+", 1);
    }

    void test_tokenMaker_star () 
    {
		test_tokenMaker("^\\*", "*", 1);
    }

    void test_tokenMaker_fowardSlash () 
    {
		test_tokenMaker("^/", "/", 1);
    }

    void test_tokenMaker_dash () 
    {
		test_tokenMaker("^-", "-", 1);
    }


    void test_tokenMaker_lessThan () 
    {
		test_tokenMaker("^<", "<", 1);
	}

    void test_tokenMaker_lessThanEqual () 
    {
		test_tokenMaker("^<=", "<=", 2);
    }

    void test_tokenMaker_greaterThan () 
    {
		test_tokenMaker("^>", ">", 1);
    }

    void test_tokenMaker_greaterThanEqual () 
    {
		test_tokenMaker("^>=", ">=", 2);
	}

    void test_tokenMaker_equalEquals () 
    {
		test_tokenMaker("^==", "==", 2);
    }

    void test_tokenMaker_notEquals () 
    {
		test_tokenMaker("^!=", "!=", 2);
    }


   void test_tokenMaker_intConst () 
   {
		test_tokenMaker("^[0-9]+", "12347", 5);
   }

   void test_tokenMaker_floatConst () 
   {
		test_tokenMaker("^[0-9]*\\.[0-9]+", "4.3", 3);
   }


   void test_tokenMaker_variableName () 
   {
		test_tokenMaker("^[a-zA-Z_]+[0-9_]*", "Word_2_", 7);
   }

   void test_tokenMaker_leftParen () 
   {
	   test_tokenMaker("^\\(", "((", 1);
   }

   void test_tokenMaker_rightParen () 
   {
		test_tokenMaker("^\\)", ")", 1);
   }

   void test_tokenMaker_leftCurly () 
   {
	   test_tokenMaker("^\\{", "{", 1);
   }

   void test_tokenMaker_rightCurly () 
   {
	   test_tokenMaker("^\\}", "}", 1);
   }

   void test_tokenMaker_leftSquare () 
   {
	   test_tokenMaker("^\\[", "[", 1);
   }

   void test_tokenMaker_rightSquare () 
   {
	   test_tokenMaker("^\\]", "]", 1);
   }

   void test_tokenMaker_comma () 
   {
	   test_tokenMaker("^,", ",", 1);
   }

   void test_tokenMaker_semiColon () 
   {
	   test_tokenMaker("^;", ";", 1);
   }

   void test_tokenMaker_andOp () 
   {
	   test_tokenMaker("^&&", "&&", 2);
   }

   void test_tokenMaker_orOp () 
   {
	   test_tokenMaker("^\\|\\|",  "||", 2);
   }

   void test_tokenMaker_notOp () 
   {
	   test_tokenMaker("^!", "!", 1);
   }

   void test_tokenMaker_stringConst () 
   {
	   test_tokenMaker("^\"[^\"]*\"", "\"!1#Hello.?\"", 12); 
   }
   
//Terminal Tests:
	void terminal_evaluation(tokenType type, char * text)
	{
		Token *tks = s->scan (text);
        TS_ASSERT (tks != NULL);
        TS_ASSERT_EQUALS (tks->terminal, type) ;
	}


	void test_terminal_intKwd ()
	{
		terminal_evaluation(intKwd, "Integer");
	}
	
	void test_terminal_floatKwd ()
	{
		terminal_evaluation(floatKwd, "Float");
	}
	
	void test_terminal_stringKwd ()
	{
		terminal_evaluation(stringKwd, "String");
	}
	
	void test_terminal_matrixKwd ()
	{
		terminal_evaluation(matrixKwd, "Matrix");
	}
	
	void test_terminal_letKwd ()
	{
		terminal_evaluation(letKwd, "let");
	}
	
	void test_terminal_inKwd ()
	{
		terminal_evaluation(inKwd, "in");
	}
	
	void test_terminal_endKwd ()
	{
		terminal_evaluation(endKwd, "end");
	}
	
	void test_terminal_ifKwd ()
	{
		terminal_evaluation(ifKwd, "if");
	}
	
	void test_terminal_thenKwd ()
	{
		terminal_evaluation(thenKwd, "then");
	}
	
	void test_terminal_elseKwd ()
	{
		terminal_evaluation(elseKwd, "else");
	}
	
	void test_terminal_forKwd ()
	{
		terminal_evaluation(forKwd, "for");
	}
	
	void test_terminal_toKwd ()
	{
		terminal_evaluation(toKwd, "to");
	}
	
	void test_terminal_printKwd ()
	{
		terminal_evaluation(printKwd, "print");
	}
	
	void test_terminal_intConst ()
	{
		terminal_evaluation(intConst, "567");
	}
	
	void test_terminal_floatConst ()
	{
		terminal_evaluation(floatConst, "3.14159");
	}
	
	void test_terminal_stringConst ()
	{
		terminal_evaluation(stringConst, "\"string\"");
	}
	
	void test_terminal_variableName ()
	{
		terminal_evaluation(variableName, "cakes");
	}
	
	void test_terminal_leftParen ()
	{
		terminal_evaluation(leftParen, "(");
	}
	
	void test_terminal_rightParen ()
	{
		terminal_evaluation(rightParen, ")");
	}
	
	void test_terminal_leftCurly ()
	{
		terminal_evaluation(leftCurly, "{");
	}
	
	void test_terminal_rightCurly ()
	{
		terminal_evaluation(rightCurly, "}");
	}
	
	void test_terminal_leftSquare ()
	{
		terminal_evaluation(leftSquare, "[");
	}
	
	void test_terminal_rightSquare ()
	{
		terminal_evaluation(rightSquare, "]");
	}
	
	void test_terminal_comma ()
	{
		terminal_evaluation(comma, ",");
	}
	
	void test_terminal_semiColon ()
	{
		terminal_evaluation(semiColon, ";");
	}
	
	void test_terminal_assign ()
	{
		terminal_evaluation(assign, "=");
	}
	
	void test_terminal_plusSign ()
	{
		terminal_evaluation(plusSign, "+");
	}
	
	void test_terminal_star ()
	{
		terminal_evaluation(star, "*");
	}
	
	void test_terminal_dash ()
	{
		terminal_evaluation(dash, "-");
	}
	
	void test_terminal_forwardSlash ()
	{
		terminal_evaluation(forwardSlash, "/");
	}
	
	void test_terminal_lessThan ()
	{
		terminal_evaluation(lessThan, "<");
	}
	
	void test_terminal_lessThanEqual ()
	{
		terminal_evaluation(lessThanEqual, "<=");
	}
	
	void test_terminal_greaterThan ()
	{
		terminal_evaluation(greaterThan, ">");
	}
	
	void test_terminal_greaterThanEqual ()
	{
		terminal_evaluation(greaterThanEqual, ">=");
	}
	
	void test_terminal_equalsEquals ()
	{
		terminal_evaluation(equalsEquals, "==");
	}
	
	void test_terminal_notEquals ()
	{
		terminal_evaluation(notEquals, "!=");
	}
	
	void test_terminal_andOp ()
	{
		terminal_evaluation(andOp, "&&");
	}
	
	void test_terminal_orOp ()
	{
		terminal_evaluation(orOp, "||");
	}
	
	void test_terminal_notOp ()
	{
		terminal_evaluation(notOp, "!");
	}
	
	void test_terminal_lexicalError ()
	{
		terminal_evaluation(lexicalError, "$");
	}
    
    // Tests for "scan"
    // --------------------------------------------------

    /* Below are some helper functions and sample tests for testing the 
       "scan" method on Scanner.
    */

    // Test that a list of tokens has no lexicalError tokens.
    bool noLexicalErrors (Token *tks) 
    {
        Token *currentToken = tks ;
        while (currentToken != NULL) 
        {
            if (currentToken->terminal == lexicalError) 
            {
                printf("priblem: %s\n",currentToken->lexeme.c_str());
				return false ;
            }
            else 
            {
                currentToken = currentToken->next ;
            }
        }
        return true ;
    }

    /* A quick, but inaccurate, test for scanning files.  It only
       checks that no lexical errors occurred, not that the right
       tokens were returned. 
    */
    void scanFileNoLexicalErrors ( const char* filename ) 
    {
    	s = new Scanner();
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT (noLexicalErrors(tks));
    }


    /* This function checks that the terminal fields in the list of
       tokens matches a list of terminals.
    */
    bool sameTerminals (Token *tks, int numTerms, tokenType *ts) 
    {
        Token *currentToken = tks ;
        int termIndex = 0 ;
        while (currentToken != NULL && termIndex < numTerms ) 
        {
            if (currentToken->terminal != ts[termIndex]) 
            {
		        printf("%i: %i should be %i\n",termIndex,currentToken->terminal , ts[termIndex]);
				fflush(stdout);
                return false ;
            }
            else 
            {
                ++ termIndex ;
                currentToken = currentToken->next ;
            }
        }
        return true ;
    }


    /* Below are the provided test files that your code should also
       pass.

       You may initially want to rename these tests to "xtest_..." so
       that the CxxTest framework does not see it as a test and won't
       run it as one.  This way you can focus on the tests that you'll
       write above for the individual terminal types first. Then focus
       on these tests.

    */

    // The "endOfFile" token is always the last one in the list of tokens.
    void test_scan_empty ( ) 
    {
    	//printf("scan_empty\n");
    	s = new Scanner();
        Token *tks = s->scan ("   ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    void test_scan_empty_comment ( ) 
    {
        Token *tks = s->scan (" /* a comment */ ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }

    // When a lexical error occurs, the scanner creates a token with a 
    // single-character lexeme and lexicalError as the terminal.
   void test_scan_lexicalErrors ( ) 
   {
        Token *tks = s->scan ("$&1  ") ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "$");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, lexicalError) ;
        TS_ASSERT_EQUALS (tks->lexeme, "&");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, intConst) ;
        TS_ASSERT_EQUALS (tks->lexeme, "1");
        tks = tks->next ;
        TS_ASSERT (tks != NULL) ;
        TS_ASSERT_EQUALS (tks->terminal, endOfFile) ;
        TS_ASSERT (tks->next == NULL) ;
    }


    // A test for scanning numbers and a variable.
    void test_scan_nums_vars ( ) 
    {
        Token *tks = s->scan (" 123 x 12.34 ") ;
        TS_ASSERT (tks != NULL) ;
        tokenType ts[] = { intConst, variableName, floatConst, endOfFile } ;
        TS_ASSERT ( sameTerminals ( tks, 4, ts ) ) ;
    }



    /* This test checks that the scanner returns a list of tokens with
       the correct terminal fields.  It doesn't check that the lexeme
       are correct.
     */
    
    void test_scan_bad_syntax_good_tokens ( ) 
    {
        const char *filename = "../samples/bad_syntax_good_tokens.dsl" ;
        char *text =  readInputFromFile ( filename )  ;
        TS_ASSERT ( text ) ;
        Token *tks = s->scan ( text ) ;
        TS_ASSERT (tks != NULL) ;
        tokenType ts[] = { 
            intConst, intConst, intConst, intConst, 

            stringConst, stringConst, stringConst,

            floatConst, floatConst, floatConst,

			matrixKwd,



            semiColon, comma, 
            leftCurly, leftParen, rightCurly, rightParen,

            plusSign, star, dash, forwardSlash, 

            equalsEquals, lessThanEqual, 
            greaterThanEqual, notEquals, 
            assign,

            variableName, variableName, variableName, variableName, 
            variableName, variableName, variableName,


            intKwd, floatKwd,  stringKwd, 

            endOfFile
       	} ;
        int count = 37; 
        TS_ASSERT ( sameTerminals ( tks, count, ts ) ) ;
    }

    void test_scan_sample_forestLoss ( ) 
    {
        scanFileNoLexicalErrors ("../samples/forest_loss_v2.dsl") ;
    }
};

