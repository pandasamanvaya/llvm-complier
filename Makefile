parser: scanner.l parser.y
	flex scanner.l
	bison -t --verbose parser.y
	g++ -o parser lex.yy.c parser.tab.c -lfl

clean:
	rm lex.yy.c parser.tab.c parser.tab.h