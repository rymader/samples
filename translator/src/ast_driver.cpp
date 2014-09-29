//#include <cxxtest/TestSuite.h>
#include <iostream> 
#include "parser.h"
#include "readInput.h"

#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std ;

int main(int argc, char ** argv) {
  Parser p ;

  ParseResult pr = p.parse( readInputFromFile ("../samples/test.dsl") ) ;
  if(!pr.ok) {
    cout << "FAILURE TO PARSE!\n";
  }
  if(!pr.ast) {
    cout << "EMPTY AST!\n";
    return 1;
  }
  cout<< pr.ast->unparse()<<endl;
  return 0;
}
