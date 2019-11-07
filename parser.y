%{
  #include <stdio.h>
  #include "ast.h"
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  void yyerror(char *s);
%}

%union{
  char *text;
  struct ASTNode *node;
  int number;
}

%token  NUMBER ID INT CHAR BOOL VOID IF ELSE FOR WHILE INPUT PRINT ROP STRING
%token  RDOP SOP MOP AOP AND OR NOT TRUE FALSE EQUAL BREAK RETURN IN OUT
%type <node> Expr Var OrTerm AndTerm MulTerm SumTerm TerExpr Constant 
%type <node> Term RelTerm UnTerm
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
  | WHILE '('Expr')' '{' VarDec StatList '}'
  | WHILE '('Expr')' '{' StatList '}'
  ;
ExprList: ExprList ',' Expr
  | Expr                         {printPostFix($1);}   
  ;
//Conditions 
CondStat: IF '('Expr')' '{' VarDec StatList'}'
  | IF '('Expr')' '{' StatList'}'
  | IF '('Expr')' '{' VarDec StatList'}' ELSE '{' VarDec StatList'}'   
  | IF '('Expr')' '{'VarDec StatList'}' ELSE '{'StatList'}'   
  | IF '('Expr')' '{'StatList'}' ELSE '{' VarDec StatList'}'
  | IF '('Expr')' '{'StatList'}' ELSE '{'StatList'}'
  ;
//All Expressions
ExprStat: Expr ';'                  {printPostFix($1);}  
  | BREAK ';' 
  ;
Expr: Var AOP Expr                  {$$ = getASTNodeBinaryOp($1, $3, DASSIGN, yylval.text);}
  | Var EQUAL Expr                  {$$ = getASTNodeBinaryOp($1, $3, ASSIGN, yylval.text); printf("%s\n", yylval.text);}
  | TerExpr                         
  ;
TerExpr: TerExpr '?' OrTerm ':' OrTerm  {$$ = getASTNodeTernaryOp($1, $3, $5);}
  | OrTerm                                
  ;
OrTerm: OrTerm OR AndTerm           {$$ = getASTNodeBinaryOp($1, $3, OROP, yylval.text);}
  | AndTerm                         
  ;
AndTerm: AndTerm AND UnTerm         {$$ = getASTNodeBinaryOp($1, $3, ANDOP, yylval.text);}
  | UnTerm                          
  ;
UnTerm: NOT UnTerm                  {$$ = getASTNodeUnaryOp($2, NOTOP, yylval.text);}
  | SOP UnTerm                      {$$ = getASTNodeUnaryOp($2, SUMOP, yylval.text);}
  | RelTerm                         
  ;
RelTerm: SumTerm ROP SumTerm        {$$ = getASTNodeBinaryOp($1, $3, RELOP, yylval.text);}
  | SumTerm RDOP SumTerm            {$$ = getASTNodeBinaryOp($1, $3, RELDOP, yylval.text);}
  | SumTerm                         
  ;
SumTerm: SumTerm SOP MulTerm        {$$ = getASTNodeBinaryOp($1, $3, SUMOP, yylval.text);}
  | MulTerm                         
  ;
MulTerm: MulTerm MOP Term           {$$ = getASTNodeBinaryOp($1, $3, MULOP, yylval.text);}
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
 Constant:	NUMBER               {$$ = getASTNodeIntLiteral(yylval.number);}
	| TRUE                         {$$ = getASTNodeBoolLiteral(yylval.text);}
  | FALSE                        {$$ = getASTNodeBoolLiteral(yylval.text);}
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


