BIN = c-
PARSER = parser

CC = g++
CCFLAGS = 

PRSR_SRS = $(PARSER).y $(PARSER).l
HDRS = scanType.h
OBJS = lex.yy.o $(PARSER).tab.o ScanFunc.o SymTbl/symbolTable.o main.o
FUNCS = ScanFunc.cpp SymTbl/symbolTable.cpp
HEADERS = scanType.h SymTbl/symbolTable.h 

YACC = bison
LEX = flex
YYFLAGS = -v -t -d 

$(BIN) : $(OBJS) $(FUNCS) $(HEADERS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(BIN)

lex.yy.c : $(PARSER).l $(PARSER).tab.h $(HDR)
	$(LEX) $(PARSER).l 

$(PARSER).tab.h $(PARSER).tab.c: $(PARSER).y
	$(YACC) $(YYFLAGS) $(PARSER).y

clean :
	rm -f *~ $(OBJS) $(BIN) lex.yy.c $(PARSER).tab.h $(PARSER).tab.c $(PARSER).output

tar : $(HDR) $(PRSR_SRS) makefile
	tar -cvf $(BIN).tar $(HDRS) $(SRCS) $(DOCS) makefile
