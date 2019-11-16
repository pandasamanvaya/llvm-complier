#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include <vector>
#include "ast.h"
#define plist vector<pair<Type *, string>>
#define FuncArg pair<Function *, vector<string>>
using namespace llvm;
using namespace std;

extern void genIRCode(struct ASTNode *Node);
void genIRBinOp(struct ASTNode *Node);
void setFuncArgs(Function *func, vector<string> args);
FuncArg genIRFunction(struct ASTNode *Node, plist parameterlist);
plist genIRParamList(plist parameterlist, struct ASTNode *Node);
pair<Type *, string> genIRParam(struct ASTNode *Node);
Type *genIRDtype(struct ASTNode *Node);
string genIRId(struct ASTNode *Node);
