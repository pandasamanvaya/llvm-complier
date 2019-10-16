%{
  #include <stdio.h>
  #include <iostream>
  using namespace std;

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
%token  STRING
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
FuncDec: Type ID '(' ParamList ')' '{'VarDec StatList'}'
  | Type ID '(' ParamList ')' '{'StatList'}'
  | Type ID '(' ParamList ')' ';'
  ;
Type: INT | CHAR | BOOL | VOID;
ParamList: ParamList ',' Param 
  | Param
  ;
Param: Type Var
  | ;
//Statement
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
OutList: OutList OUT Expr
  | Expr
  | OutList OUT STRING
  | STRING
  ;
//Return
RetStat: RETURN ';'
  | RETURN Expr ';'
  ;
//Loops
LoopStat: FOR '(' ExprList ';' ExprList ';' ExprList ')' '{' VarDec StatList'}'
  | FOR '(' ExprList ';' ExprList ';' ExprList ')' '{' StatList'}'
  | WHILE '('Expr')'  '{' VarDec StatList '}'
  | WHILE '('Expr')'  '{' StatList '}'
  ;
ExprList: ExprList ',' Expr
  | Expr
  ;
//Conditions 
CondStat: IF '('Expr')' '{' VarDec StatList'}'
  | IF '('Expr')' '{' StatList'}'
  | IF '('Expr')'  '{' VarDec StatList'}' ELSE '{' VarDec StatList'}'   
  | IF '('Expr')'  '{'VarDec StatList'}' ELSE '{'StatList'}'   
  | IF '('Expr')'  '{'StatList'}' ELSE '{' VarDec StatList'}'
  | IF '('Expr')'  '{'StatList'}' ELSE '{'StatList'}'
  ;
//All Expressions
ExprStat: Expr ';'  
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
  | SOP UnTerm
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
  | ID '[' ']'
  | ID Dim
  | ID '[' ']'Dim
  ;
Dim: Dim '['Expr']'
  |'['Expr']'
  ;
NonVar: '('Expr')'
  | Constant
  | FunCall
  ;
FunCall: ID '(' ArgList ')'
  ;
ArgList: ArgList ',' Expr
  | Expr
  |;
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


