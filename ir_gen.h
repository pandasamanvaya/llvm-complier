#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Constants.h"
#include "llvm/ADT/StringRef.h"
#include <vector>
#include "ast.h"
#define plist vector<pair<Type *, pair<string, Value *>>>
#define vlist vector<pair<Type *, vector<pair<string, Value *>>>>
#define alist vector<pair<AllocaInst *, string>>
#define null (Value *)Constant::getNullValue
using namespace llvm;
using namespace std;

static LLVMContext Context;
static IRBuilder<> Builder(Context);
static Module *ModuleOb = new Module("IR Generator", Context);

extern void genIRCode(struct ASTNode *Node, int i);
void genIRBinOp(struct ASTNode *Node);
vector<pair<Value *, string>> setFuncArgs(Function *func, vector<string> args);
struct IRFunction *genIRFunction(struct ASTNode *Node);
plist genIRParamList(plist parameterlist, struct ASTNode *Node);
pair<Type *, pair<string, Value *>> genIRParam(struct ASTNode *Node);
Type *genIRDtype(struct ASTNode *Node);
pair<string, Value *> genIRId(struct ASTNode *Node);
Value *genIRStatlist(struct ASTNode *Node, struct IRFunction *Func);
pair<Type *, vector<pair<string, Value *>>> genIRVarDec(struct ASTNode *Node);
vector<pair<string, Value *>> genIRVar(struct ASTNode *Node);
Value *genIRStat(struct ASTNode *Node, struct IRFunction *Func);
Value *arithOp(Value *left, Value *right, string op);
Value *genOperand(struct ASTNode *Node, struct IRFunction *Func);
Value *getIdVal(string id, struct IRFunction *Func);
vlist genIRVarList(vlist variablelist, struct ASTNode *Node);
Value *getAddress(struct ASTNode *Node, struct IRFunction *Func);
Value *getArrayVal(struct ASTNode *Node, struct IRFunction *Func);
Value *getArrayAddress(struct ASTNode *Node, struct IRFunction *Func);
BasicBlock *createBB(Function *func, string name);
Function *findFunc(string name);
vector <Value *> genFuncArgs(vector<Value *>args, struct ASTNode *Node, IRFunction *Func);
Constant *genString(string s);
vector<Value *> genPrintList(vector<Value *> args, struct ASTNode *Node, IRFunction *Func);

struct IRFunction{
	Function *func;
	BasicBlock *bb;
	alist alloc;
	vector<pair<Value *, string>> args;
};