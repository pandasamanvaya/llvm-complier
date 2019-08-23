%{
#include "parser.tab.h"
int lineno = 0;
%}

%% 
[ \t] 			{ /* eat white spaces */  }
[a-zA-Z][a-zA-Z]* 	{return ID;}
[0-9][0-9]*		{return NUMBER;}
[i][n][t]		{return INT;}
[c][h][a][r]	{return CHAR;}
[b][o][o][l]	{return BOOL;}
[v][o][i][d]	{return VOID;}
[+-*=></%!][=]		{return OP;}
[T][r][u][e]		{return TRUE;}
[F][a][l][s][e]		{return FALSE;}
