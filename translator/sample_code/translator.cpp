#include <iostream> 
#include "parser.h"
#include "readInput.h"

#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std ;

void writeFile ( const string text, const string filename ) {
        ofstream out(filename.c_str()); 
        out << (string) text << endl ;
    }

int main(int argc, char ** argv) {
  Parser p ;

  ParseResult pr = p.parse( readInputFromFile ("../samples/simple_5.dsl") ) ;
  if(!pr.ok) {
    cout << "FAILURE TO PARSE!\n";
  }
  
  if(!pr.ast) {
    cout << "EMPTY AST!\n";
    return 1;
  }
  
  writeFile(pr.ast->cppCode(), "../samples/Program.cpp");
  return 0;
}
