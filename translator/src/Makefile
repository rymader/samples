CXX_DIR = ../lib/cxxtest
CXXTEST = $(CXX_DIR)/bin/cxxtestgen #cxxtestgen.pl was for an older version of cxx
CXXFLAGS = --error-printer --abort-on-fail --have-eh

FLAGS = -Wall -g

# Program files.
readInput.o:	readInput.cpp readInput.h
	g++ $(FLAGS) -c readInput.cpp 

regex.o:	regex.cpp regex.h
	g++ $(FLAGS) -c regex.cpp 

scanner.o:	scanner.cpp scanner.h regex.h
	g++ $(FLAGS) -c scanner.cpp 

parser.o: parser.cpp parser.h scanner.h extToken.h parseResult.h
	g++ $(FLAGS) -c parser.cpp 
	
parseResult.o: parseResult.cpp parseResult.h
	g++ $(FLAGS) -c parseResult.cpp 

extToken.o: extToken.cpp extToken.h
	g++ $(FLAGS) -c extToken.cpp 

# Testing files and targets.
#run-tests:	parser_tests
#	./parser_tests

run-tests:	regex_tests scanner_tests parser_tests ast_tests i4_assessment_tests
	./regex_tests
	./scanner_tests
	./parser_tests
	./ast_tests
	./i4_assessment_tests
	
ast-tests: ast_tests
	./ast_tests

test-driver: ast_driver
	./ast_driver
	
translate: translator
	./translator

i4_test: i4_assessment_tests
	./i4_assessment_tests

regex_tests:	regex_tests.cpp regex.o
	g++ $(FLAGS) -I$(CXX_DIR) -o regex_tests regex.o regex_tests.cpp

regex_tests.cpp: regex.h regex_tests.h
	$(CXXTEST) $(CXXFLAGS) -o regex_tests.cpp regex_tests.h

scanner_tests:	scanner_tests.cpp scanner.o regex.o readInput.o
	g++ $(FLAGS) -I$(CXX_DIR)  -o scanner_tests \
		scanner.o regex.o readInput.o scanner_tests.cpp

scanner_tests.cpp:	scanner.o scanner_tests.h readInput.h
	$(CXXTEST) $(CXXFLAGS) -o scanner_tests.cpp scanner_tests.h

parser_tests: parser_tests.cpp parser.o parseResult.o readInput.o scanner.o regex.o extToken.o
	g++ $(FLAGS) -I$(CXX_DIR) -o parser_tests parser.o parser_tests.cpp\
		readInput.o parseResult.o scanner.o regex.o extToken.o
		
parser_tests.cpp: parser.o parser_tests.h scanner.h extToken.h parseResult.h readInput.h
	$(CXXTEST) $(CXXFLAGS) -o parser_tests.cpp parser_tests.h

ast_tests: ast_tests.cpp parser.o parseResult.o readInput.o scanner.o regex.o extToken.o
	g++ $(FLAGS) -I$(CXX_DIR) -o ast_tests parser.o ast_tests.cpp\
		readInput.o parseResult.o scanner.o regex.o extToken.o
		
ast_tests.cpp: parser.o ast_tests.h scanner.h extToken.h parseResult.h readInput.h
	$(CXXTEST) $(CXXFLAGS) -o ast_tests.cpp ast_tests.h

ast_driver: ast_driver.cpp parser.o parseResult.o readInput.o scanner.o regex.o extToken.o
	g++ $(FLAGS) -I$(CXX_DIR) -o ast_driver parser.o ast_driver.cpp\
		readInput.o parseResult.o scanner.o regex.o extToken.o
		
i4_assessment_tests: i4_assessment_tests.cpp parser.o parseResult.o readInput.o scanner.o regex.o extToken.o
	g++ $(FLAGS) -I$(CXX_DIR) -o i4_assessment_tests parser.o i4_assessment_tests.cpp\
		readInput.o parseResult.o scanner.o regex.o extToken.o
		
i4_assessment_tests.cpp: parser.o ast_tests.h scanner.h extToken.h parseResult.h readInput.h
	$(CXXTEST) $(CXXFLAGS) -o i4_assessment_tests.cpp i4_assessment_tests.h		
		
translator: translator.cpp parser.o parseResult.o readInput.o scanner.o regex.o extToken.o
	g++ $(FLAGS) -I$(CXX_DIR) -o translator parser.o translator.cpp\
		readInput.o parseResult.o scanner.o regex.o extToken.o		
		
clean:
	rm -Rf *.o \
		regex_tests regex_tests.cpp \
		scanner_tests scanner_tests.cpp 

