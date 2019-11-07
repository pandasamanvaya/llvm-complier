%{
#include "parser.tab.h"
extern int yylex();
int lineno = 0;
%}
 
%%
[ \t] 				{ /* eat white spaces */}
[{]					{return '{';}
[}]					{return '}';}
[(]					{return '(';}
[)]					{return ')';}
[\]]				{return ']';}
[\[]				{return '[';}
["'][^"']+["'] 		{yylval.text = strdup(yytext); return STRING;}
int					{yylval.text = strdup(yytext); return INT;}
char				{yylval.text = strdup(yytext); return CHAR;}
bool				{yylval.text = strdup(yytext); return BOOL;}
void				{yylval.text = strdup(yytext); return VOID;}
True				{yylval.text = strdup(yytext); return TRUE;}
False				{yylval.text = strdup(yytext); return FALSE;}
if 					{yylval.text = strdup(yytext); return IF;}
for 				{yylval.text = strdup(yytext); return FOR;}
while				{yylval.text = strdup(yytext); return WHILE;}
else				{yylval.text = strdup(yytext); return ELSE;}
print				{yylval.text = strdup(yytext); return PRINT;}
input				{yylval.text = strdup(yytext); return INPUT;}
and					{yylval.text = strdup(yytext); return AND;}
or					{yylval.text = strdup(yytext); return OR;}
not					{yylval.text = strdup(yytext); return NOT;}
break				{yylval.text = strdup(yytext); return BREAK;}
return 				{yylval.text = strdup(yytext); return RETURN;}
[><=][=]			{yylval.text = strdup(yytext); return RDOP;}
[><]				{yylval.text = strdup(yytext); return ROP;}
[=]					{yylval.text = strdup(yytext); return EQUAL;}
[-+*/!][=]			{yylval.text = strdup(yytext); return AOP;}
[-+]				{yylval.text = strdup(yytext); return SOP;}
[*/%]				{yylval.text = strdup(yytext); return MOP;}
[>][>]				{yylval.text = strdup(yytext); return IN;}
[<][<]				{yylval.text = strdup(yytext); return OUT;}
[a-zA-Z][a-zA-Z0-9_]* 	{return ID;}
[0-9]+				{return NUMBER;}
\n					{++lineno;}
;					{return ';';}
[?]					{return '?';}
[:]					{return ':';}
[,]					{return ',';}
.					{;}
%%
