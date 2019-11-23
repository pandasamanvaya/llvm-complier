%{
#include <string>
#include <string.h>
using namespace std;
#include "parser.tab.h"
extern "C" int yylex();
%}
%option yylineno
%%
[ \t] 				{/* eat white spaces */}
[{]					{return '{';}
[}]					{return '}';}
[(]					{return '(';}
[)]					{return ')';}
[\]]				{return ']';}
[\[]				{return '[';}
["'][^"']+["'] 		{yylval.text = new string(strdup(yytext));return STRING;}
int					{yylval.text = new string("int"); return INT;}
char				{yylval.text = new string("char"); return CHAR;}
bool				{yylval.text = new string("bool"); return BOOL;}
void				{yylval.text = new string("void"); return VOID;}
True				{yylval.text = new string("True"); return TRUE;}
False				{yylval.text = new string("False"); return FALSE;}
if 					{yylval.text = new string("if"); return IF;}
for 				{yylval.text = new string("for"); return FOR;}
while				{yylval.text = new string("while"); return WHILE;}
else				{yylval.text = new string("else"); return ELSE;}
print				{yylval.text = new string("print"); return PRINT;}
input				{yylval.text = new string("input"); return INPUT;}
and					{yylval.text = new string("and"); return AND;}
or					{yylval.text = new string("or"); return OR;}
not					{yylval.text = new string("not"); return NOT;}
break				{yylval.text = new string("break"); return BREAK;}
return 				{yylval.text = new string("return"); return RETURN;}
[><=!][=]			{yylval.text = new string(strdup(yytext)); return RDOP;}
[><]				{yylval.text = new string(strdup(yytext)); return ROP;}
[-+*/][=]			{yylval.text = new string(strdup(yytext)); return AOP;}
[=]					{yylval.text = new string(strdup(yytext)); return EQUAL;}
[-+]				{yylval.text = new string(strdup(yytext)); return SOP;}
[*/%]				{yylval.text = new string(strdup(yytext)); return MOP;}
[>][>]				{yylval.text = new string(strdup(yytext)); return IN;}
[<][<]				{yylval.text = new string(strdup(yytext)); return OUT;}
[a-zA-Z][a-zA-Z0-9_]* 	{yylval.text = new string(strdup(yytext));return ID;}
[0-9]+				{yylval.number = atoi(yytext); return NUMBER;}
\n					{}
;					{return ';';}
[?]					{return '?';}
[:]					{return ':';}
[,]					{return ',';}
.					{;}
%%
