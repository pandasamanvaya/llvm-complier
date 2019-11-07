parser: scanner.l parser.y
	flex scanner.l
	bison -dt --verbose parser.y
	gcc -g -o parser lex.yy.c parser.tab.c ast.c -lfl

clean:
	rm lex.yy.c parser.tab.c parser.tab.h