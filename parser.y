%{
  #include <string>
  #include <stdio.h>
  using namespace std;
  #include "ast_print.h"
  extern "C" int yylex();
  extern "C" int yyparse();
  extern FILE *yyin;
  extern int yylineno;
  void yyerror(char *s);
%}

%union{
  struct ASTNode *node;
  string *text;
  int number;
}

%token <text> ID INT CHAR BOOL VOID IF ELSE FOR WHILE INPUT PRINT ROP STRING
%token <text> RDOP AOP AND OR NOT TRUE FALSE EQUAL BREAK RETURN IN OUT SOP MOP
%token <number> NUMBER
%type <node> Expr Var OrTerm AndTerm MulTerm SumTerm TerExpr Constant FunCall
%type <node> Term RelTerm UnTerm NonVar Type ExprStat LoopStat CondStat InpList
%type <node> InpStat OutList OutStat VarList VarDec StatList Statement ParamList 
%type <node> Param FuncDec VarDecList IOStat ArgList RetStat FuncDecList
%%

Goal: DecList                              {};
DecList: FuncDecList                       {printf("AST Generated code:-\n");printAST($1);printIR($1);}
  | VarDecList                             {printAST($1);}   
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
FuncDecList: FuncDec FuncDecList            {$$ = getASTNodeFuncList($1, $2);}
  | FuncDec                                 {$$ = getASTNodeFuncList($1, NULL);}
  ; 
FuncDec: Type ID '(' ParamList ')' '{'VarDecList StatList'}' {$$ = getASTNodeFunction($1, $2, $4, $7, $8);}
  | Type ID '(' ParamList ')' '{'StatList'}'                 {$$ = getASTNodeFunction($1, $2, $4, NULL, $7);}
  | Type ID '(' ')' '{'VarDecList StatList'}'                {$$ = getASTNodeFunction($1, $2, NULL, $6, $7);}
  | Type ID '(' ')' '{'StatList'}'                           {$$ = getASTNodeFunction($1, $2, NULL, NULL, $6);}
  ;
Type: INT          {$$ = getASTNodeDType($1);}
    | CHAR         {$$ = getASTNodeDType($1);}
    | BOOL         {$$ = getASTNodeDType($1);}
    | VOID         {$$ = getASTNodeDType($1);}
  ;
ParamList: Param ',' ParamList              {$$ = getASTNodeParamList($1, $3);}  
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
IOStat: InpStat ';'                         {$$ = $1;}
  | OutStat ';'                             {$$ = $1;}
  ;
InpStat: INPUT IN InpList                   {$$ = getASTNodeInputStat($3);}
;
InpList: Var IN InpList                     {$$ = getASTNodeInputList($1, $3);}
  | Var                                     {$$ = getASTNodeInputList($1, NULL);}
  ;
OutStat: PRINT OUT OutList                  {$$ = getASTNodeOutputStat($3);}
  ;
OutList: Expr OUT OutList                   {$$ = getASTNodeOutputList($1, NULL, $3);}
  | Expr                                    {$$ = getASTNodeOutputList($1, new string("NULL"), NULL);}
  | STRING OUT OutList                      {$$ = getASTNodeOutputList(NULL, $1, $3);}
  | STRING                                  {$$ = getASTNodeOutputList(NULL, $1, NULL);}      
  ;
//Return
RetStat: RETURN ';'                         {$$ = getASTNodeReturn(NULL);}
  | RETURN Expr ';'                         {$$ = getASTNodeReturn($2);}
  ;
//Loops
LoopStat: FOR '(' Expr ';' Expr ';' Expr ')' '{' VarDecList StatList'}' {$$ = getASTNodeFor($3, $5, $7, $10, $11);}
  | FOR '(' Expr ';' Expr ';' Expr ')' '{'StatList'}'                   {$$ = getASTNodeFor($3, $5, $7, NULL, $10);}
  | WHILE '('Expr')' '{' VarDecList StatList '}'    {$$ = getASTNodeWhile($3, $6, $7);}
  | WHILE '('Expr')' '{' StatList '}'               {$$ = getASTNodeWhile($3, NULL, $6);}
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
AndTerm: AndTerm AND RelTerm         {$$ = getASTNodeBinaryOp($1, $3, ANDOP, $2);}
  | RelTerm                          
  ;
RelTerm: SumTerm ROP SumTerm        {$$ = getASTNodeBinaryOp($1, $3, RELOP, $2);}
  | SumTerm RDOP SumTerm            {$$ = getASTNodeBinaryOp($1, $3, RELDOP, $2);}
  | SumTerm                         
  ;
SumTerm: SumTerm SOP MulTerm        {$$ = getASTNodeBinaryOp($1, $3, SUMOP, $2);}
  | MulTerm                         
  ;
MulTerm: MulTerm MOP UnTerm           {$$ = getASTNodeBinaryOp($1, $3, MULOP, $2);}
  | UnTerm                                          
  ;
UnTerm: NOT UnTerm                  {$$ = getASTNodeUnaryOp($2, NOTOP, $1);}
  | SOP UnTerm                      {$$ = getASTNodeUnaryOp($2, SUMOP, $1);}
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
  | FunCall                          {$$ = $1;}
  ;
FunCall: ID '(' ArgList ')'          {$$ = getASTNodeFunCall($1, $3);}
  ;
ArgList: Expr ',' ArgList            {$$ = getASTNodeArg($1, $3);}
  | Expr                             {$$ = getASTNodeArg($1, NULL);}
  |                                  {$$ = getASTNodeArg(NULL, NULL);} 
  ;
 Constant:	NUMBER               {$$ = getASTNodeIntLiteral($1); }
	| TRUE                         {$$ = getASTNodeBoolLiteral($1);}
  | FALSE                        {$$ = getASTNodeBoolLiteral($1);}
	;
%%

void yyerror(char *s)
{
  fprintf(stderr, "error: %s line %d\n", s, yylineno);
}

int main(int argc, char **argv)
{
  yyparse();
}
