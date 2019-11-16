#include "ir_gen.h"
#include <iostream>

static LLVMContext Context;
static Module *ModuleOb = new Module("IR Generator", Context);
static IRBuilder<> Builder(Context);

void genIRBinOp(struct ASTNode *Node)
{

}

void setFuncArgs(Function *func, vector<string> args)
{
	int i=0;
	Function::arg_iterator l, r;
	for(l = func->arg_begin(), r = func->arg_end(); l!= r; l++, i++)
		l->setName(args[i]);
}

BasicBlock *createBB(Function *func, string name)
{
	return BasicBlock::Create(Context, name, func);
}

FuncArg genIRFunction(struct ASTNode *Node, plist parameterlist)
{
	Type *Return = genIRDtype(Node->functionnode.type);
	if(Node->functionnode.paramlist != NULL)
		parameterlist = genIRParamList(parameterlist, Node->functionnode.paramlist);
	vector<Type *> argType;
	vector<string> args;
	for(int i=0; i < parameterlist.size(); i++){
		argType.push_back(parameterlist[i].first);
		args.push_back(parameterlist[i].second);
	}

 	FunctionType *funcType = FunctionType::get(Return, argType, false);
	Function *func = Function::Create(funcType,	Function::ExternalLinkage,
									Node->functionnode.name, ModuleOb);
	return make_pair(func, args);
}

plist genIRParamList(plist parameterlist, struct ASTNode *Node)
{
	parameterlist.push_back(genIRParam(Node->paramlist.left));
	if(Node->paramlist.right != NULL){
		parameterlist = genIRParamList(parameterlist, Node->paramlist.right);
	}
	return parameterlist;
}

pair<Type *, string> genIRParam(struct ASTNode *Node)
{
	pair<Type *, string> parameter;
	parameter = make_pair(genIRDtype(Node->param.type), genIRId(Node->param.var));
	return parameter;
}

Type *genIRDtype(struct ASTNode *Node)
{
	if(Node->dtype == "int")
		return Builder.getInt32Ty();

}
string genIRId(struct ASTNode *Node)
{
	return Node->idlit;
}

void genIRCode(struct ASTNode *Node)
{
	switch(Node->nodetype){
		case Func:{
				plist parameterlist;
				FuncArg func = genIRFunction(Node, parameterlist);
				cout << func.second.size() << endl;
				setFuncArgs(func.first, func.second);
				BasicBlock *entry = createBB(func.first, "entry");
				Builder.SetInsertPoint(entry);
				verifyFunction(*func.first);
				break;
		}
	}
	ModuleOb->print(errs(), nullptr);

}

// Value *arithOp(IRBuilder<> Builder, Value *left, Value *right, char op)
// {
// 	switch(op){
// 		case '+': return Builder.CreateAdd(left, right, "sum");
// 		case '-': return Builder.CreateSub(left, right, "diff");
// 		case '*': return Builder.CreateMul(left, right, "mul");
// 		case '/': return Builder.CreateSDiv(left, right, "div");
// 		case '%': return Builder.CreateSRem(left, right, "rem");
// 	}
// }


// Function *createFunc(IRBuilder<> &Builder, vector<string> argType, string retType, string name)
// {
// 	//Creating Argument types
// 	vector<Type *> Args;
// 	for(uint i=0 ; i < argType.size(); i++){
// 		if(argType[i] == "int")
// 			Args.push_back(Type::getInt32Ty(Context));
// 	}
// 	//Creating return type
// 	Type *Return;
// 	if(retType == "int")
// 		Return = Builder.getInt32Ty();
// 	FunctionType *funcType = FunctionType::get(Return, Args, false);

// 	//Creating function instance
// 	Function *func = Function::Create(funcType, 
// 									Function::ExternalLinkage,
// 									name, 
// 									ModuleOb);

// 	return func;
// }



// Value *evalFunc(IRBuilder<> Builder, Function *func)
// {
// 	return arithOp(Builder, func->arg_begin(), func->arg_end(), '+');
// }

// int main()
// {
// 	vector<string> argType(2, "int");
// 	vector<string> argName;
// 	argName.push_back("a");
// 	argName.push_back("b");
// 	Function *func = createFunc(Builder, argType, "int", "BinOp");
// 	setFuncArgs(func, argName);
// 	BasicBlock *entry = createBB(func, "entry");
// 	Builder.SetInsertPoint(entry);
// 	Value *val = arithOp(Builder, func->arg_begin(), func->arg_end()-1, '+');
// 	Builder.CreateRet(val);
// 	verifyFunction(*func);
// 	ModuleOb->print(errs(), nullptr);

// 	return 0;
// }