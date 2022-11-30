BIN = c-
PARSER = parser

CC = g++
CFLAGS = -std=c++11
CXXFLAGS = $(CFLAGS)

PRSR_SRS = $(PARSER).y $(PARSER).l
HDRS = scanType.h
OBJS = lex.yy.o $(PARSER).tab.o ScanFunc.o SymTbl/symbolTable.o Semantic.o main.o IO.o YYError/yyerror.o MemLocFinder/MemLoc.o CodeGen/CodeGen.o
SRC = ScanFunc.cpp SymTbl/symbolTable.cpp lex.yy.c Semantic.cpp main.cpp IO.cpp YYError/yyerror.cpp MemLocFinder/MemLoc.cpp CodeGen/CodeGen.cpp
HEADERS = scanType.h SymTbl/symbolTable.h Semantic.h IO.h YYError/yyerror.h MemLocFinder/MemLoc.h CodeGen/CodeGen.h

YACC = bison
LEX = flex
YYFLAGS = -v -t -d 

$(BIN) : $(OBJS) $(SRC) $(HEADERS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(BIN)

lex.yy.c : $(PARSER).l $(PARSER).tab.h $(HDR)
	$(LEX) $(PARSER).l 

$(PARSER).tab.h $(PARSER).tab.c: $(PARSER).y
	$(YACC) $(YYFLAGS) $(PARSER).y

clean :
	rm -f *~ $(OBJS) $(BIN) lex.yy.c $(PARSER).tab.h $(PARSER).tab.c $(PARSER).output

tar : $(HDR) $(PRSR_SRS) makefile
	tar -cvf $(BIN).tar $(HDRS) $(SRC) $(DOCS) makefile
