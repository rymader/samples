#include <iostream>
#include <string.h>
#include "regex.h"
#include "scanner.h"
#include <stdio.h>  
#include <unistd.h>

using namespace std;



RegexTypePair Scanner::regexTypeList[39] = {*(new RegexTypePair(intKwd, *makeRegex("^Integer"))), 
											*(new RegexTypePair(floatKwd, *makeRegex("^Float"))), 
											*(new RegexTypePair(stringKwd, *makeRegex("^String"))), 
											*(new RegexTypePair(matrixKwd, *makeRegex("^Matrix"))), 
											*(new RegexTypePair(letKwd, *makeRegex("^let"))), 
											*(new RegexTypePair(inKwd, *makeRegex("^in"))), 
											*(new RegexTypePair(endKwd, *makeRegex("^end"))), 
											*(new RegexTypePair(ifKwd, *makeRegex("^if"))), 
											*(new RegexTypePair(thenKwd, *makeRegex("^then"))), 
											*(new RegexTypePair(elseKwd, *makeRegex("^else"))), 
											*(new RegexTypePair(forKwd, *makeRegex("^for"))), 
											*(new RegexTypePair(toKwd, *makeRegex("^to"))), 
											*(new RegexTypePair(printKwd, *makeRegex("^print"))), 
											*(new RegexTypePair(intConst, *makeRegex("^[0-9]+"))), 
											*(new RegexTypePair(floatConst, *makeRegex("^[0-9]*\\.[0-9]+"))), 
											*(new RegexTypePair(stringConst, *makeRegex("^\"[^\"]*\""))), 
											*(new RegexTypePair(variableName, *makeRegex("^[a-zA-Z_]+[0-9_]*"))), 
											*(new RegexTypePair(leftParen, *makeRegex("^\\("))), 
											*(new RegexTypePair(rightParen, *makeRegex("^\\)"))), 
											*(new RegexTypePair(leftCurly, *makeRegex("^\\{"))), 
											*(new RegexTypePair(rightCurly, *makeRegex("^\\}"))), 
											*(new RegexTypePair(leftSquare, *makeRegex("^\\["))), 
											*(new RegexTypePair(rightSquare, *makeRegex("^\\]"))), 
											*(new RegexTypePair(comma, *makeRegex("^,"))), 
											*(new RegexTypePair(semiColon, *makeRegex("^;"))), 
											*(new RegexTypePair(assign, *makeRegex("^="))), 
											*(new RegexTypePair(plusSign, *makeRegex("^\\+"))), 
											*(new RegexTypePair(star, *makeRegex("^\\*"))), 
											*(new RegexTypePair(dash, *makeRegex("^-"))), 
											*(new RegexTypePair(forwardSlash, *makeRegex("^/"))), 
											*(new RegexTypePair(lessThan, *makeRegex("^<"))), 
											*(new RegexTypePair(lessThanEqual, *makeRegex("^<="))), 
											*(new RegexTypePair(greaterThan, *makeRegex("^>"))), 
											*(new RegexTypePair(greaterThanEqual, *makeRegex("^>="))), 
											*(new RegexTypePair(equalsEquals, *makeRegex("^=="))), 
											*(new RegexTypePair(notEquals, *makeRegex("^!="))), 
											*(new RegexTypePair(andOp, *makeRegex("^&&"))), 
											*(new RegexTypePair(orOp, *makeRegex("^\\|\\|"))), 
											*(new RegexTypePair(notOp, *makeRegex("^!")))};

regex_t * Scanner::whiteSpaceRegexes[3] = {makeRegex("^[\n\t\r ]+"), makeRegex ("^/\\*([^\\*]|\\*+[^\\*/])*\\*+/"), makeRegex ("^//[^\n]*\n")};
 

//token constructor
// Supportting Functions



void Scanner::printList()
{
	Token t = *tokenListHead;
	while(t.terminal!=endOfFile)
	{
		printf("Terminal: %i, Lexeme %s, %x\n", t.terminal, t.lexeme.c_str(), t.next);
		t = *(t.next);
		sleep(1);
	}
}

	

int Scanner::consumeWhiteSpaceAndBlockComments (regex_t *whiteSpace, regex_t *blockComment, regex_t *lineComment, const char *text) 
{
	int numMatchedChars = 0 ;
	int totalNumMatchedChars = 0 ;
	int stillConsumingWhiteSpace ;

	do {
	    stillConsumingWhiteSpace = 0 ;  // exit loop if not reset by a match

	    // Try to match white space
	    numMatchedChars = matchRegex (whiteSpace, text) ;
	    totalNumMatchedChars += numMatchedChars ;
	    if (numMatchedChars > 0) 
	    {
	        text = text + numMatchedChars ;
	        stillConsumingWhiteSpace = 1 ;
	    }

	    // Try to match block comments
	    numMatchedChars = matchRegex (blockComment, text) ;
	    totalNumMatchedChars += numMatchedChars ;
	    if (numMatchedChars > 0) 
	    {
	        text = text + numMatchedChars ;
	        stillConsumingWhiteSpace = 1 ;
	    }
	    
	    //Try to match line comments
	    numMatchedChars = matchRegex (lineComment, text);
		totalNumMatchedChars += numMatchedChars ;
		if(numMatchedChars > 0)
		{
			text = text + numMatchedChars;
			stillConsumingWhiteSpace = 1;
		}	
	}
	while ( stillConsumingWhiteSpace ) ;    

	return totalNumMatchedChars ;
}


void Scanner::addToList(Token *t)
{
	Token *temp = tokenListHead;
	//printf("head: %d\n", temp->terminal);
	if(temp->terminal == endOfFile)
	{
		tokenListHead = t;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = t;
		
	}
	//printf("head: %d\n", temp->terminal);
	//printf("head: %d, tail: %d\n", tokenListHead->terminal);
	//t.next = new Token(endOfFile, "", NULL);
}

Token * Scanner::scan(const char *c)
{
	//Initialization for addToList Function:
	Token * tk = new Token(endOfFile, "", NULL);
	tokenListHead = tk;
	//tokenListTail = tk;
	//1. create all the regexes
	char const *text = c;
	// First check if file is empty
	if (text == NULL)
		cout << "Error, no file selected." << endl;

	// Now make regex for the tokens
	else
	{

		
	
		int numMatchedChars = 0;

		numMatchedChars = consumeWhiteSpaceAndBlockComments(whiteSpaceRegexes[0], whiteSpaceRegexes[1], whiteSpaceRegexes[2], text);
		text = text + numMatchedChars;

		tokenType matchType;
		string lexeme;
		int maxNumMatchedChars;
		//RegexTypePair* regexList[39] = {inIt()};
		while (text[0] != '\0')
		{
			matchType = lexicalError;
			lexeme = *(new string());
			numMatchedChars = 0;
			maxNumMatchedChars = 0;
			int i;
			for(i = 0; i< 39; i++)
			{
				numMatchedChars = matchRegex(&(regexTypeList[i].regex), text);
				if(numMatchedChars > maxNumMatchedChars)
				{
					maxNumMatchedChars = numMatchedChars;
					matchType = regexTypeList[i].type;	
				}
			}
			if(maxNumMatchedChars == 0)
			{
				lexeme.assign(text, text+1);
				text = text+1;
			}
			else
			{
				lexeme.assign(text, text+maxNumMatchedChars);
				text = text + maxNumMatchedChars;
			}
			
			Token * tokenToAdd = new Token(matchType, lexeme, NULL);
			//printf("term: %d, lexeme: \"%s\"\n", tokenToAdd->terminal, tokenToAdd->lexeme.c_str());
			addToList(tokenToAdd);
	
			numMatchedChars = consumeWhiteSpaceAndBlockComments(whiteSpaceRegexes[0], whiteSpaceRegexes[1], whiteSpaceRegexes[2], text);
			//printf("consumed: %d\n", numMatchedChars);
			text = text + numMatchedChars;
		}
		addToList(new Token(endOfFile, "", NULL));

		return tokenListHead;
	}
}

