%{
#include "parser.tab.h"
extern int yylex();
int lineno = 0;
%}
 
%%
[ \t] 				{/* eat white spaces */}
[{]					{return '{';}
[}]					{return '}';}
[(]					{return '(';}
[)]					{return ')';}
[\]]				{return ']';}
[\[]				{return '[';}
["'][^"']+["'] 		{yylval.text = strdup(yytext);return STRING;}
int					{yylval.text = "int"; return INT;}
char				{yylval.text = "char"; return CHAR;}
bool				{yylval.text = "bool"; return BOOL;}
void				{yylval.text = "void"; return VOID;}
True				{yylval.text = "True"; return TRUE;}
False				{yylval.text = "False"; return FALSE;}
if 					{yylval.text = "if"; return IF;}
for 				{yylval.text = "for"; return FOR;}
while				{yylval.text = "while"; return WHILE;}
else				{yylval.text = "else"; return ELSE;}
print				{yylval.text = "print"; return PRINT;}
input				{yylval.text = "input"; return INPUT;}
and					{yylval.text = "and"; return AND;}
or					{yylval.text = "or"; return OR;}
not					{yylval.text = "not"; return NOT;}
break				{yylval.text = "break"; return BREAK;}
return 				{yylval.text = "return"; return RETURN;}
[><=][=]			{yylval.text = strdup(yytext); return RDOP;}
[><]				{yylval.text = strdup(yytext); return ROP;}
[-+*/!][=]			{yylval.text = strdup(yytext); return AOP;}
[=]					{yylval.text = strdup(yytext); return EQUAL;}
[-+]				{yylval.text = strdup(yytext); return SOP;}
[*/%]				{yylval.text = strdup(yytext); return MOP;}
[>][>]				{yylval.text = strdup(yytext); return IN;}
[<][<]				{yylval.text = strdup(yytext); return OUT;}
[a-zA-Z][a-zA-Z0-9_]* 	{yylval.text = strdup(yytext);return ID;}
[0-9]+				{yylval.number = atoi(yytext); return NUMBER;}
\n					{++lineno;}
;					{return ';';}
[?]					{return '?';}
[:]					{return ':';}
[,]					{return ',';}
.					{;}
%%
