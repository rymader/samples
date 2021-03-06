/* A sven more small meaningless comment */
#ifndef SCANNER_H
#define SCANNER_H

#include <regex.h>

#include <string>

/* This enumerated type is used to keep track of what kind of
   construct was matched. 
 */



enum tokenEnumType { 

	intKwd, floatKwd,  stringKwd, matrixKwd,
	letKwd, inKwd, endKwd, ifKwd, thenKwd, elseKwd,
	forKwd, toKwd, printKwd,

	// Constants
	intConst, floatConst, stringConst, 

	// Names
	variableName ,

	// Punctuation
	leftParen, rightParen, 
	leftCurly, rightCurly, 
	leftSquare, rightSquare,

	comma, semiColon, 

	//Operators
	assign, 
	plusSign, star, dash, forwardSlash,
	lessThan, lessThanEqual, greaterThan, greaterThanEqual,
	equalsEquals, notEquals,
	andOp, orOp, notOp,

	// Special terminal types
	endOfFile ,
	lexicalError
} ;

/*const char* regexType[] = {"^Integer","^Float","^String","^Matrix","^let","^in","^end","^if","^then","^else","^for","^to","^print"
,"^[0-9]+","^[0-9]*\\.[0-9]+","^\"[^\"]*\"","^[a-zA-Z_]+[0-9_]*","^\\(","^\\)","^\\{","^\\}","^\\[","^(\\])","^,","^;","^=","^\\+"
,"^\\*","^-","^/","^<","^<=","^>","^>=","^==","^!=","^&&","^\\|\\|","^!"};*/

typedef enum tokenEnumType tokenType ;

class RegexTypePair {
	public:
	tokenType type;
	regex_t regex;

	RegexTypePair(tokenType newType, regex_t newRegex) {type = newType; regex = newRegex;};
};
// Below you need to write your class definitions for Token and Scanner.

class Token {
	public:
		tokenType terminal;
		std::string lexeme;
		Token * next;
		Token(tokenType term, std::string lex, Token * nxt) {terminal = term; lexeme = lex; next = nxt;}
		Token(std::string lex, tokenType term, Token * nxt) {terminal = term; lexeme = lex; next = nxt;}
		Token() {}
};

class Scanner {



	public:

		static RegexTypePair regexTypeList[39];
		static regex_t * whiteSpaceRegexes[3];

		Token *tokenListHead;
		Scanner() {tokenListHead = NULL;}
		//~Scanner() {while(tokenListHead != NULL) {Token * t = tokenListHead; delete t; tokenListHead = tokenListHead->next;}};
		void addToList(Token *t);
		void printList();
		regex_t* inIt();
		int consumeWhiteSpaceAndBlockComments (regex_t *, regex_t *, regex_t *, const char *);
		Token *scan(const char *);
};

#endif /* SCANNER_H */
