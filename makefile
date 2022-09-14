BIN = c-
PARSER = parser

CC = g++
CCFLAGS = 

PRSR_SRS = $(PARSER).y $(PARSER).l
HDRS = scanType.h
OBJS = lex.yy.o $(PARSER).tab.o

YYFLAGS = -v -t -d 

$(BIN) : $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(BIN)

lex.yy.c : $(PARSER).l $(PARSER).tab.h $(HDR)
	flex $(PARSER).l 

$(PARSER).tab.h $(PARSER).tab.c: $(PARSER).y
	bison $(YYFLAGS) $(PARSER).y

clean :
	rm -f *~ $(OBJS) $(BIN) lex.yy.c $(PARSER).tab.h $(BIN).tab.c 

tar : $(HDR) $(PRSR_SRS) makefile
	tar -cvf $(BIN).tar $(HDRS) $(SRCS) $(DOCS) makefile
