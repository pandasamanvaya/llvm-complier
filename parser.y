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

%token <text> ID INT CHAR BOOL VOID IF ELSE FOR WHILE INPUT PRINT ROP STRING
%token <text> RDOP SOP MOP AOP AND OR NOT TRUE FALSE EQUAL BREAK RETURN IN OUT
%token <number> NUMBER
%type <node> Expr Var OrTerm AndTerm MulTerm SumTerm TerExpr Constant FunCall
%type <node> Term RelTerm UnTerm NonVar Type ExprStat LoopStat CondStat
%%

Goal: DecList;            
DecList: DecList Dec
  | Dec                                   
  ;
Dec: FuncDec                                 
  | VarDec                                
  ;
//Variable
VarDec: Type VarList ';'     
  ;
VarList: VarList',' Var       
  | Var                                             
  ;

//Function
FuncDec: Type ID '(' ParamList ')' '{'VarDec StatList'}' 
  | Type ID '(' ParamList ')' '{'StatList'}'
  | Type ID '(' ParamList ')' ';'
  ;
Type: INT          {printf("int ");}
    | CHAR         {printf("char ");}
    | BOOL         {printf("bool ");}
    | VOID         {printf("void ");}
  ;
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
LoopStat: FOR '(' Expr ';' Expr ';' Expr ')' '{' VarDec StatList'}' {$$ = getASTNodeFor($3, $5, $7);}
  | FOR '(' Expr ';' Expr ';' Expr ')' '{' StatList'}' {$$ = getASTNodeFor($3, $5, $7);}
  | WHILE '('Expr')' '{' VarDec StatList '}'    {$$ = getASTNodeWhile($3);}
  | WHILE '('Expr')' '{' StatList '}'           {$$ = getASTNodeWhile($3);}
  ;
//Conditions 
CondStat: IF '('Expr')' '{' VarDec StatList'}'        {$$ = getASTNodeIf($3);}
  | IF '('Expr')' '{' StatList'}'                     {$$ = getASTNodeIf($3);}
  | IF '('Expr')' '{' VarDec StatList'}' ELSE '{' VarDec StatList'}'   {$$ = getASTNodeIf($3);}
  | IF '('Expr')' '{'VarDec StatList'}' ELSE '{'StatList'}'   {$$ = getASTNodeIf($3);}
  | IF '('Expr')' '{'StatList'}' ELSE '{' VarDec StatList'}'  {$$ = getASTNodeIf($3);}
  | IF '('Expr')' '{'StatList'}' ELSE '{'StatList'}'          {$$ = getASTNodeIf($3);}
  ;
//All Expressions
ExprStat: Expr ';'                   
  | BREAK ';'                       {printf("%s;", $1);} 
  ;
Expr: Var AOP Expr                  {$$ = getASTNodeBinaryOp($1, $3, DASSIGN, $2);}
  | Var EQUAL Expr                  {$$ = getASTNodeBinaryOp($1, $3, ASSIGN, $2);}
  | Var EQUAL STRING                {$$ = getASTNodeStringOp($1, $3);}
  | TerExpr                         
  ;
TerExpr: TerExpr '?' OrTerm ':' OrTerm  {$$ = getASTNodeTernaryOp($1, $3, $5);}
  | OrTerm                                
  ;
OrTerm: OrTerm OR AndTerm           {$$ = getASTNodeBinaryOp($1, $3, OROP, $2);}
  | AndTerm                         
  ;
AndTerm: AndTerm AND UnTerm         {$$ = getASTNodeBinaryOp($1, $3, ANDOP, $2);}
  | UnTerm                          
  ;
UnTerm: NOT UnTerm                  {$$ = getASTNodeUnaryOp($2, NOTOP, $1);}
  | SOP UnTerm                      {$$ = getASTNodeUnaryOp($2, SUMOP, $1);}
  | RelTerm                         
  ;
RelTerm: SumTerm ROP SumTerm        {$$ = getASTNodeBinaryOp($1, $3, RELOP, $2);}
  | SumTerm RDOP SumTerm            {$$ = getASTNodeBinaryOp($1, $3, RELDOP, $2);}
  | SumTerm                         
  ;
SumTerm: SumTerm SOP MulTerm        {$$ = getASTNodeBinaryOp($1, $3, SUMOP, $2);}
  | MulTerm                         
  ;
MulTerm: MulTerm MOP Term           {$$ = getASTNodeBinaryOp($1, $3, MULOP, $2);}
  | Term                                          
  ;
Term: Var                           
  | NonVar                          
  ;
Var: ID                              {$$ = getASTNodeIDLiteral($1);}
  | ID '[' ']'                       {$$ = getASTNode1DArray($1, NULL);}
  | ID '['Expr']'                    {$$ = getASTNode1DArray($1, $3);}
  | ID '[' ']' '['Expr']'            {$$ = getASTNode2DArray($1, NULL, $5);}
  | ID '['Expr']' '['Expr']'         {$$ = getASTNode2DArray($1, $3, $6);}
  ;
NonVar: '('Expr')'                   {$$ = $2;}
  | Constant                         
  | FunCall                          
  ;
FunCall: ID '(' ArgList ')'          
  ;
ArgList: ArgList ',' Expr
  | Expr                              
  |;
 Constant:	NUMBER               {$$ = getASTNodeIntLiteral($1); }
	| TRUE                         {$$ = getASTNodeBoolLiteral($1);}
  | FALSE                        {$$ = getASTNodeBoolLiteral($1);}
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
