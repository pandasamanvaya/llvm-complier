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
%token  RETURN
%token  IN
%token  OUT
%%

Goal: DecList;

DecList: DecList Dec
  | Dec
  ;
Dec: FuncDec
  | VarDec
  ;
//Variable
VarDec: Type VarList ';';
VarList: VarList',' Var
  | Var
  ;
//Function
FuncDec: Type ID '(' ParamList ')' '{'StatList'}'
  | Type ID '(' ParamList ')' ';'
  ;
Type: INT | CHAR | BOOL | VOID;
ParamList: ParamList ';' Param 
  | Param
  ;
Param: Type VarList
  | ;
StatList: Statement 
	| StatList Statement
  ;
Statement: ExprStat
  | CondStat
  | LoopStat
  | IOStat
  | RetStat
  ;
//I/O 
IOStat: InpStat ';'
  | OutStat ';' 
  ;
InpStat: INPUT IN InpList  
  ;
InpList: Var IN InpList
  | Var
  ;
OutStat: PRINT OUT OutList
  ;
OutList: OutList OUT Term
  | Term
  ;
//Return
RetStat: RETURN ';'
  | RETURN Expr ';'
  ;
//Loops
LoopStat: FOR '(' Expr ';' Expr ';' Expr ')' '{'StatList'}'
  | WHILE '('Expr')'  '{'StatList '}'
  ;
//Conditions 
CondStat: IF '('Expr')' '{' StatList'}'
  | IF '('Expr')'  '{'StatList'}' ELSE '{'StatList'}'   
  ;
//All Expressions
ExprStat: Expr ';'  
  | Expr
  | BREAK ';' 
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


