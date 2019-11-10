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
True				{yylval.text = "True"; printf("%s", yytext); return TRUE;}
False				{yylval.text = "False"; printf("%s", yytext); return FALSE;}
if 					{yylval.text = "if"; printf("%s", yytext); return IF;}
for 				{yylval.text = "for"; printf("%s", yytext); return FOR;}
while				{yylval.text = "while"; printf("%s", yytext); return WHILE;}
else				{yylval.text = "else"; printf("%s", yytext); return ELSE;}
print				{yylval.text = "print"; return PRINT;}
input				{yylval.text = "input"; return INPUT;}
and					{yylval.text = "and"; printf("%s", yytext); return AND;}
or					{yylval.text = "or"; printf("%s", yytext); return OR;}
not					{yylval.text = "not"; printf("%s", yytext); return NOT;}
break				{yylval.text = "break"; printf("%s", yytext); return BREAK;}
return 				{yylval.text = "return"; printf("%s", yytext); return RETURN;}
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
