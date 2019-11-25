#include <iostream>
#include "ast.h"
#include <vector>
using namespace std;
#define INT pair<string, int>
#define FLOAT pair<string, float>
#define VAR pair<string, vector<INT>>
#define invalid -1e5

int evalFunction(struct ASTNode *Node);
vector<VAR> genVarList(vector<VAR> varlist, struct ASTNode *Node);
VAR genVarDec(struct ASTNode *Node);
vector<INT> genVar(struct ASTNode *Node);
INT genId(struct ASTNode *Node);
int evalStatList(struct ASTNode *Node);
int evalStat(struct ASTNode *Node);
void assginValue(string op, int val);
int idLitVal(struct ASTNode *Node);
extern void interpret(struct ASTNode *Node);
