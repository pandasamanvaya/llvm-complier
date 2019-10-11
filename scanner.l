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
[\]]				{cout << yytext << " "; return ']';}
[\[]				{cout << yytext << " "; return '[';}
["'][^"']+["'] 		{cout << yytext << " "; return STRING;}
int					{cout << yytext << " "; return INT;}
char				{cout << yytext << " "; return CHAR;}
bool				{cout << yytext << " "; return BOOL;}
void				{cout << yytext << " "; return VOID;}
True				{cout << yytext << " "; return TRUE;}
False				{cout << yytext << " "; return FALSE;}
if 					{cout << yytext << " "; return IF;}
for 				{cout << yytext << " "; return FOR;}
while				{cout << yytext << " "; return WHILE;}
else				{cout << yytext << " "; return ELSE;}
print				{cout << yytext << " "; return PRINT;}
input				{cout << yytext << " "; return INPUT;}
and					{cout << yytext << " "; return AND;}
or					{cout << yytext << " "; return OR;}
not					{cout << yytext << " "; return NOT;}
break				{cout << yytext << " "; return BREAK;}
return 				{cout << yytext << " "; return RETURN;}
[><=][=]			{cout << yytext << " "; return RDOP;}
[><]				{cout << yytext << " "; return ROP;}
[=]					{cout << yytext << " "; return EQUAL;}
[-+*/!][=]			{cout << yytext << " "; return AOP;}
[-+]				{cout << yytext << " "; return SOP;}
[*/%]				{cout << yytext << " "; return MOP;}
[>][>]				{cout << yytext << " "; return IN;}
[<][<]				{cout << yytext << " "; return OUT;}
[a-zA-Z][a-zA-Z0-9_]* 	{cout << yytext << " "; return ID;}
[0-9]+				{cout << yytext << " "; return NUMBER;}
\n					{++lineno;}
;					{cout << yytext <<endl; return ';';}
[?]					{cout << yytext << " "; return '?';}
[:]					{cout << yytext << " "; return ':';}
[,]					{cout << yytext << " "; return ',';}
.					{cout << "Unrecognised char";}
%%
