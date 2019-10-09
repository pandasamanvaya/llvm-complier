%{
  #include <stdio.h>
  #include <iostream>
  using namespace std;

  // stuff from flex that bison needs to know about:
  extern "C" int yylex();
  extern int yyparse();
  extern FILE *yyin;
  void yyerror(char *s);
%}


%token  NUMBER 
%token  ID
%token  OP
%token  DOP
%token  INT
%token  CHAR
%token  BOOL
%token  VOID
%token  IF
%token  ELSE
%token  FOR
%token  WHILE
%token  INPUT
%token  PRINT
%token  TRUE
%token  FALSE
%token	IO
%token  END
%token  RELOP
%%

Goal: Expr END '\n' 
	| Goal Expr END'\n'
  ;

Expr: 	Term OP '('Expr')'
	| Term DOP '('Expr')'
  | Term OP Expr  
  | Term RELOP Expr  
  | Term DOP Expr
  | OP Expr
  | OP '('Expr')'  
  | Term
	
  ;

Term:	NUMBER 
	| ID
  | TRUE
  | FALSE
	;


%%

void yyerror(char *s)
{
        fprintf(stderr, "error: %s\n", s);
}


main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Over\n");
}


