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
%token	IO
%token  END
%token  ROP
%token  RDOP
%token  SOP
%token  SDOP
%token  MOP
%token  MDOP
%token  AND
%token  OR
%token  NOT
%token  TRUE
%token  FALSE
%%

Goal: Expr END '\n' 
	| Goal Expr END'\n'
  ;

Expr: 	AndTerm OR '('Expr')'
  | AndTerm
  ;
AndTerm: UnTerm AND AndTerm
  | UnTerm
  ;
UnTerm: NOT UnTerm
  | RelTerm
  ;
RelTerm: SumTerm ROP SumTerm
  | SumTerm RDOP SumTerm
  | SumTerm
  ;
SumTerm: MulTerm SOP SumTerm
  | MulTerm SDOP MulTerm
  | MulTerm
  ;
MulTerm: Term MOP MulTerm
  | Term MDOP MulTerm
  | Term
  ;

Term:	NUMBER 
	| ID
  | ID'['Expr']'
  | ID'['Expr']''['Expr']'
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


