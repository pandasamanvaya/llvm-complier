%{
#include "parser.tab.h"
extern int yylex();
int lineno = 0;
%}
 
%%
[ \t] 				{printf("%s", yytext); /* eat white spaces */}
[{]					{printf("%s", yytext); return '{';}
[}]					{printf("%s", yytext); return '}';}
[(]					{printf("%s", yytext); return '(';}
[)]					{printf("%s", yytext); return ')';}
[\]]				{printf("%s", yytext); return ']';}
[\[]				{printf("%s", yytext); return '[';}
["'][^"']+["'] 		{yylval.text = strdup(yytext); return STRING;}
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
print				{yylval.text = "print"; printf("%s", yytext); return PRINT;}
input				{yylval.text = "input"; printf("%s", yytext); return INPUT;}
and					{yylval.text = "and"; printf("%s", yytext); return AND;}
or					{yylval.text = "or"; printf("%s", yytext); return OR;}
not					{yylval.text = "not"; printf("%s", yytext); return NOT;}
break				{yylval.text = "break"; printf("%s", yytext); return BREAK;}
return 				{yylval.text = "return"; printf("%s", yytext); return RETURN;}
[><=][=]			{yylval.text = strdup(yytext); printf("%s", yytext); return RDOP;}
[><]				{yylval.text = strdup(yytext); printf("%s", yytext); return ROP;}
[-+*/!][=]			{yylval.text = strdup(yytext); printf("%s", yytext); return AOP;}
[=]					{yylval.text = strdup(yytext); printf("%s", yytext); return EQUAL;}
[-+]				{yylval.text = strdup(yytext); printf("%s", yytext); return SOP;}
[*/%]				{yylval.text = strdup(yytext); printf("%s", yytext); return MOP;}
[>][>]				{yylval.text = strdup(yytext); printf("%s", yytext); return IN;}
[<][<]				{yylval.text = strdup(yytext); printf("%s", yytext); return OUT;}
[a-zA-Z][a-zA-Z0-9_]* 	{yylval.text = strdup(yytext); printf("%s", yytext); return ID;}
[0-9]+				{yylval.number = atoi(yytext); printf("%d", yylval.number); return NUMBER;}
\n					{printf("\n"); ++lineno;}
;					{printf("%s", yytext); return ';';}
[?]					{printf("%s", yytext); return '?';}
[:]					{printf("%s", yytext); return ':';}
[,]					{printf("%s", yytext); return ',';}
.					{;}
%%
