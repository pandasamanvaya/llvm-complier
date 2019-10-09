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

Expr: RelTerm ROP Expr
  | RelTerm RDOP Expr
  | RelTerm
  ;
RelTerm: SumTerm ROP RelTerm
  | SumTerm RDOP RelTerm
  | SumTerm
  ;
SumTerm: MulTerm SOP SumTerm
  | MulTerm SDOP MulTerm
  | MulTerm
  ;
MulTerm: OrTerm MOP MulTerm
  | OrTerm MDOP MulTerm
  | OrTerm
  ;
OrTerm: AndTerm OR OrTerm
  | AndTerm
  ;
AndTerm: UnTerm AND AndTerm
  | UnTerm
  ;
UnTerm: NOT UnTerm
  | Term
  ;
Term: Var
  | NonVar
  ;
Var: ID
  | Var'['Expr']'
  ;
NonVar: '('Expr')'
  | Constant
  ;
Constant:	NUMBER 
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


