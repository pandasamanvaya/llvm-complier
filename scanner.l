%{
#include <iostream>
#include "parser.tab.h"
using namespace std;
extern "C" int yylex();
int lineno = 0;
%}
 
%%
[ \t] 				{ /* eat white spaces */  }
[{]					{cout << yytext << " "; return '{';}
[}]					{cout << yytext << " "; return '}';}
[(]					{cout << yytext << " "; return '(';}
[)]					{cout << yytext << " "; return ')';}
int					{cout << yytext << " "; return INT;}
char				{cout << yytext << " "; return CHAR;}
bool				{cout << yytext << " "; return BOOL;}
void				{cout << yytext << " "; return VOID;}
True				{cout << yytext << " "; return 'True';}
False				{cout << yytext << " "; return 'False';}
if 					{cout << yytext << " "; return IF;}
for 				{cout << yytext << " "; return FOR;}
while				{cout << yytext << " "; return WHILE;}
else				{cout << yytext << " "; return ELSE;}
print				{cout << yytext << " "; return PRINT;}
input				{cout << yytext << " "; return INPUT;}
and					{cout << yytext << " "; return 'and';}
or					{cout << yytext << " "; return 'or;}
not					{cout << yytext << " "; return 'not';}
[=><!][=]			{cout << yytext << " "; return RDOP;}
[=><]				{cout << yytext << " "; return ROP;}
[-+][=]				{cout << yytext << " "; return SDOP;}
[-+]				{cout << yytext << " "; return SOP;}
[*/][=]				{cout << yytext << " "; return MDOP;}
[*/%]				{cout << yytext << " "; return MOP;}
[<>][<>]			{cout << yytext << " "; return IO;}
["'a-zA-Z][a-zA-Z0-9_\[\]'"]* 	{cout << yytext << " "; return ID;}
[0-9][0-9]*			{cout << yytext << " "; return NUMBER;}
\n					{++lineno; return '\n'; }
;					{cout << yytext; return END;}
.					{cout << "Unrecognised char";}
%%
