#include "ir_gen.h"
#include <iostream>

static LLVMContext Context;
static Module *ModuleOb = new Module("IR Generator", Context);
static IRBuilder<> Builder(Context);

vector<plist> variables;

// void genIRBinOp(struct ASTNode *Node)
// {

// }
Value *arithOp(Value *left, Value *right, string op)
{
	if(op == "+")		return Builder.CreateAdd(left, right, "sum");
	else if (op == "-") return Builder.CreateSub(left, right, "diff");
	else if (op == "*") return Builder.CreateMul(left, right, "mul");
	else if (op == "/") return Builder.CreateSDiv(left, right, "div");
	else if (op == "%") return Builder.CreateSRem(left, right, "rem");
}

Value *genIRStatlist(struct ASTNode *Node, struct IRFunction *Func)
{
	Value *val = genIRStat(Node->statement.left, Func);
	if(Node->statement.right != NULL)
		val = genIRStatlist(Node->statement.right, Func);
	return val;
}

Value *genIRStat(struct ASTNode *Node, struct IRFunction *Func)
{
	switch(Node->nodetype){
		case BinaryOp:{
			switch(Node->binarynode.optype){
				case SUMOP: {
							Value *left = genIRStat(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							return arithOp(left, right, Node->binarynode.op);
							break;
						}
				case MULOP: {
							Value *left = genIRStat(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							return arithOp(left, right, Node->binarynode.op);
							break;
						}
				case ASSIGN:{
							// Value *left = getAddress(Node->binarynode.left, Func);
							Value *left = getAddress(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							return Builder.CreateStore(right, left);

							break;
						}
				case DASSIGN:{
							break;
				}
				default: break;

				}
				break;
			}
		case IDLIT:	return genOperand(Node, Func);
		case INTLIT: return genOperand(Node, Func);
		default: break;

	}
}

Value *getAddress(struct ASTNode *Node, struct IRFunction *Func)
{
	Function::arg_iterator l, r;
	int i=0;
	//Checking for function parameter
	for(l = Func->func->arg_begin(), r = Func->func->arg_end(); l!= r; l++, i++){
		if(Func->args[i] == Node->idlit){
			return l;
		}
	}
	//Checking for local variable
	for(uint i=0; i < Func->alloc.size(); i++){
		if(Func->alloc[i].second == Node->idlit){
			return Func->alloc[i].first;
		}
	}
	return null;
}

Value *genOperand(struct ASTNode *Node, struct IRFunction *Func)
{
	switch(Node->nodetype){
		case INTLIT: return Builder.getInt32(Node->litval);
		case IDLIT: {
					Value *val = getIdVal(Node->idlit, Func);
					if(val != null)
						return val;
					cout << "Variable " << Node->idlit << " not defined";
					return val;
				}
		default: break;

	}
}

Value *getIdVal(string id, struct IRFunction *Func)
{
	Function::arg_iterator l, r;
	int i=0;
	//Checking for function parameter
	for(l = Func->func->arg_begin(), r = Func->func->arg_end(); l!= r; l++, i++){
		if(Func->args[i] == id)
			return l;
	}
	//Checking for local variable
	for(uint i=0; i < Func->alloc.size(); i++){
		if(Func->alloc[i].second == id){
			return Builder.CreateLoad(Func->alloc[i].first);
		}
	}
	return null;
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

alist allocMem(plist parameterlist, BasicBlock *bb)
{
	alist alloc;
	for(uint i=0; i < parameterlist.size(); i++){
		AllocaInst *inst = new AllocaInst(parameterlist[i].first, 0, parameterlist[i].second, bb);
		alloc.push_back(make_pair(inst, parameterlist[i].second));
	}
	return alloc;
}

struct IRFunction *genIRFunction(struct ASTNode *Node)
{
	struct IRFunction *newfunc;
	newfunc = (struct IRFunction*) malloc(sizeof(struct IRFunction));
	plist parameterlist;
	vlist variablelist;

	//Return Type
	Type *Return = genIRDtype(Node->functionnode.type);
	//Parameter list
	if(Node->functionnode.paramlist != NULL)
		parameterlist = genIRParamList(parameterlist, Node->functionnode.paramlist);
	vector<Type *> argType;
	for(uint i=0; i < parameterlist.size(); i++){
		argType.push_back(parameterlist[i].first);
		newfunc->args.push_back(parameterlist[i].second);
	}
 	FunctionType *funcType = FunctionType::get(Return, argType, false);
	Function *func = Function::Create(funcType,	Function::ExternalLinkage,
									Node->functionnode.name, ModuleOb);
	setFuncArgs(func, newfunc->args);
	parameterlist.clear();
	//Variable list
	if(Node->functionnode.varlist != NULL)
		variablelist = genIRVarList(variablelist, Node->functionnode.varlist);

	for(uint i=0; i < variablelist.size(); i++){
		for(uint j=0; j < variablelist[i].second.size(); j++)
			parameterlist.push_back(make_pair(variablelist[i].first, (variablelist[i].second)[j]));
	}
	variables.push_back(parameterlist);
	BasicBlock *entry = createBB(func, "entry");
	Builder.SetInsertPoint(entry);

	newfunc->func = func;
	newfunc->alloc = allocMem(parameterlist, entry);
	newfunc->bb = entry;

	return newfunc;
}

vlist genIRVarList(vlist variablelist, struct ASTNode *Node)
{
	variablelist.push_back(genIRVarDec(Node->vardeclist.left));
	if(Node->vardeclist.right != NULL)
		variablelist = genIRVarList(variablelist, Node->vardeclist.right);
	return variablelist;
}

pair<Type *, vector<string>> genIRVarDec(struct ASTNode *Node)
{
	pair<Type *, vector<string>> variablelist;
	variablelist = make_pair(genIRDtype(Node->varlist.type), genIRVar(Node->varlist.list));
	return variablelist;	
}

vector<string> genIRVar(struct ASTNode *Node)
{
	vector<string> args;
	args.push_back(genIRId(Node->vardec.left));
	while(Node->vardec.right != NULL){
		Node = Node->vardec.right;
		args.push_back(genIRId(Node->vardec.left));
	}
	return args;
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
				// plist parameterlist;
				IRFunction *Func = genIRFunction(Node);
				Value *last_inst = genIRStatlist(Node->functionnode.statlist, Func);
				if(Func->func != NULL)
					verifyFunction(*Func->func);
				break;
		}
		default: break;
	}
	ModuleOb->print(errs(), nullptr);

}


