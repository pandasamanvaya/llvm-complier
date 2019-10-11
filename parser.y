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
%token  ROP
%token  RDOP
%token  SOP
%token  MOP
%token  AOP
%token  AND
%token  OR
%token  NOT
%token  TRUE
%token  FALSE
%token  EQUAL
%token  BREAK
%%

Goal: StatList '\n' 
	| Goal StatList '\n'
  ;
StatList: StatList Stat
  | Stat
  ;
Stat: ExprStat
  | CondStat
  ;
CondStat: IF '('Expr')' '\n' '{'StatList'}'
  | IF '('Expr')' '\n' '{'StatList'}' ELSE '{'StatList'}'
  ;
//All Expressions
ExprStat: Expr ';' '\n'
  | Expr
  | BREAK ';' '\n'
  ;
Expr: Var AOP Expr
  | Var EQUAL Expr
  | TerExpr
  ;
TerExpr: TerExpr '?' OrTerm ':' OrTerm
  | OrTerm
  ;
OrTerm: OrTerm OR AndTerm
  | AndTerm
  ;
AndTerm: AndTerm AND UnTerm
  | UnTerm
  ;
UnTerm: NOT UnTerm
  | RelTerm
  ;
RelTerm: SumTerm ROP SumTerm
  | SumTerm RDOP SumTerm
  | SumTerm
  ;
SumTerm: SumTerm SOP MulTerm
  | MulTerm
  ;
MulTerm: MulTerm MOP Term
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


