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
%type <node> Term RelTerm UnTerm NonVar Type ExprStat LoopStat CondStat InpList
%type <node> InpStat OutList OutStat VarList VarDec StatList Statement ParamList 
%type <node> Param FuncDec VarDecList
%%

Goal: DecList;            
DecList: FuncDecList                                 
  | VarDecList                                
  ;
VarDecList: VarDec ';' VarDecList          {$$ = getASTNodeVarDecList($1, $3);}
  | VarDec ';'                             {$$ = getASTNodeVarDecList($1, NULL);}                                     
  ;
//Variable
VarDec: Type VarList                       {$$ = getASTNodeVarList($1, $2);}
  ;
VarList: Var ',' VarList                   {$$ = getASTNodeVardec($1, $3);}
  | Var                                    {$$ = getASTNodeVardec($1, NULL);}
  ;
//Function
FuncDecList: FuncDec VarDecList             {printAST($2);}
  | FuncDec                                 {printAST($1);}
  ; 
FuncDec: Type ID '(' ParamList ')' '{'VarDecList StatList'}' {$$ = getASTNodeFunction($1, $2, $4, $7, $8);}
  | Type ID '(' ParamList ')' '{'StatList'}'                 {$$ = getASTNodeFunction($1, $2, $4, NULL, $7);}
  | Type ID '(' ')' '{'VarDecList StatList'}'                {$$ = getASTNodeFunction($1, $2, NULL, $6, $7);}
  | Type ID '(' ')' '{'StatList'}'                           {$$ = getASTNodeFunction($1, $2, NULL, NULL, $6);}
  ;
Type: INT          {$$ = getASTNodeDType("int");}
    | CHAR         {$$ = getASTNodeDType("char");}
    | BOOL         {$$ = getASTNodeDType("bool");}
    | VOID         {$$ = getASTNodeDType("void");}
  ;
ParamList: ParamList ',' Param              {$$ = getASTNodeParamList($1, $3);}  
  | Param                                   {$$ = getASTNodeParamList($1, NULL);}
  ;
Param: Type Var                             {$$ = getASTNodeParam($1, $2);}
  ;                                  
//Statement
StatList: Statement                         {$$ = getASTNodeStat($1, NULL);}
	| Statement StatList                      {$$ = getASTNodeStat($1, $2);}
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
InpStat: INPUT IN InpList                   {$$ = getASTNodeInputStat($3);}
;
InpList: Var IN InpList                     {$$ = getASTNodeInputList($1, $3);}
  | Var                                     {$$ = getASTNodeInputList($1, NULL);}
  ;
OutStat: PRINT OUT OutList                  {$$ = getASTNodeOutputStat($3);}
  ;
OutList: Expr OUT OutList                   {$$ = getASTNodeOutputList($1, NULL, $3);}
  | Expr                                    {$$ = getASTNodeOutputList($1, NULL, NULL);}
  | STRING OUT OutList                      {$$ = getASTNodeOutputList(NULL, $1, $3);}
  | STRING                                  {$$ = getASTNodeOutputList(NULL, $1, NULL);}      
  ;
//Return
RetStat: RETURN ';'
  | RETURN Expr ';'
  ;
//Loops
LoopStat: FOR '(' Expr ';' Expr ';' Expr ')' '{' VarDecList StatList'}' {$$ = getASTNodeFor($3, $5, $7);}
  | FOR '(' Expr ';' Expr ';' Expr ')' '{' VarDecList StatList'}'
  | WHILE '('Expr')' '{' VarDecList StatList '}'    {$$ = getASTNodeWhile($3);}
  | WHILE '('Expr')' '{' StatList '}'
  ;
//Conditions 
CondStat: IF '('Expr')' '{' VarDecList StatList'}'        {$$ = getASTNodeIf($3, $6, $7, NULL, NULL);}
  | IF '('Expr')' '{' StatList'}'                         {$$ = getASTNodeIf($3, NULL, $6, NULL, NULL);}
  | IF '('Expr')' '{' VarDecList StatList'}' ELSE '{' VarDecList StatList'}'   {$$ = getASTNodeIf($3, $6, $7, $11, $12);}
  | IF '('Expr')' '{' VarDecList StatList'}' ELSE '{' StatList'}'         {$$ = getASTNodeIf($3, $6, $7, NULL, $11);}
  | IF '('Expr')' '{' StatList'}' ELSE '{' VarDecList StatList'}'         {$$ = getASTNodeIf($3, NULL, $6, $10, $11);}
  | IF '('Expr')' '{' StatList'}' ELSE '{' StatList'}'                    {$$ = getASTNodeIf($3, NULL, $6, NULL, $10);}
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
