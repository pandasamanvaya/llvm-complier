parser: scanner.l parser.y
	flex scanner.l
	bison -dt --verbose parser.y
# 	g++ -g -o interpreter lex.yy.c parser.tab.c ast.c ast_inter.cpp -lfl
	g++ -g -o parser lex.yy.c parser.tab.c ast.c ir_gen.cpp	`llvm-config --cxxflags --ldflags --system-libs --libs core` -lfl 

clean:
	rm lex.yy.c parser.tab.c parser.tab.h