#include "ir_gen.h"
#include <iostream>

vector<plist> variables;

// void genIRBinOp(struct ASTNode *Node)
// {

// }
Value *arithOp(Value *left, Value *right, string op)
{
	if(op == "+" || op == "+=")		return Builder.CreateAdd(left, right, "sum");
	else if (op == "-" || op == "-=") return Builder.CreateSub(left, right, "diff");
	else if (op == "*" || op == "*=") return Builder.CreateMul(left, right, "mul");
	else if (op == "/" || op == "/=") return Builder.CreateSDiv(left, right, "div");
	else if (op == "%" || op == "%=") return Builder.CreateSRem(left, right, "rem");
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
						}
				case MULOP: {
							Value *left = genIRStat(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							return arithOp(left, right, Node->binarynode.op);
						}
				case ASSIGN:{
							Value *left = getAddress(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							return Builder.CreateStore(right, left);
						}
				case DASSIGN:{
							Value *leftop = getAddress(Node->binarynode.left, Func);
							Value *left = genOperand(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							left = arithOp(left, right, Node->binarynode.op);
							return Builder.CreateStore(left, leftop);
						}
				case ANDOP:{
							Value *left = genIRStat(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							return Builder.CreateAnd(left, right);
						}
				case OROP:{
							Value *left = genIRStat(Node->binarynode.left, Func);
							Value *right = genIRStat(Node->binarynode.right, Func);
							return Builder.CreateOr(left, right);
						}

				default: break;

				}
				break;
			}
		case UnaryOp:{
						if(Node->unarynode.optype == NOTOP){
							Value *operand = genIRStat(Node->unarynode.operand, Func);
							return Builder.CreateNot(operand);
						}
						break;
			}
		case IDLIT:	return genOperand(Node, Func);
		case INTLIT: return genOperand(Node, Func);
		case Array1D: return getArrayVal(Node, Func);
		case Return : return Builder.CreateRet(genIRStat(Node->returnstat.expr, Func));
		default: break;

	}
}

Value *getArrayVal(struct ASTNode *Node, struct IRFunction *Func)
{
	return Builder.CreateLoad(getArrayAddress(Node, Func));	
}

Value *getArrayAddress(struct ASTNode *Node, struct IRFunction *Func)
{
	Value *val = genIRStat(Node->array1dnode.value, Func);
	Function::arg_iterator l, r;
	int i=0;
	Value *base;
	//Checking for function parameter
	for(l = Func->func->arg_begin(), r = Func->func->arg_end(); l!= r; l++, i++){
		if(Func->args[i] == Node->idlit){
			base = l;
			break;
		}
	}
	//Checking for local variable
	for(uint i=0; i < Func->alloc.size(); i++){
		if(Func->alloc[i].second == Node->idlit){
			base = Func->alloc[i].first;
			break;
		}
	}
	Value *arr = Builder.CreateGEP(Builder.getInt32Ty(), base, val);
	return arr;
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
		case Array1D: return getArrayVal(Node, Func);
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
		if(parameterlist[i].second.second == null){
			AllocaInst *inst = new AllocaInst(parameterlist[i].first, 0, parameterlist[i].second.first, bb);
			alloc.push_back(make_pair(inst, parameterlist[i].second.first));
		}
		else{
			ConstantInt *num = dyn_cast<ConstantInt>(parameterlist[i].second.second);
			ArrayType *arr = ArrayType::get(parameterlist[i].first, num->getSExtValue());
			AllocaInst *inst = new AllocaInst(arr, 0, parameterlist[i].second.first, bb);
			alloc.push_back(make_pair(inst, parameterlist[i].second.first));
		}
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
		if(parameterlist[i].second.second == null)
			argType.push_back(parameterlist[i].first);
		else{
			ConstantInt *num = dyn_cast<ConstantInt>(parameterlist[i].second.second);
			ArrayType *arr = ArrayType::get(parameterlist[i].first, num->getSExtValue());
			argType.push_back(arr->getPointerTo(0));
		}
		newfunc->args.push_back(parameterlist[i].second.first);
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

pair<Type *, vector<pair<string, Value *>>> genIRVarDec(struct ASTNode *Node)
{
	pair<Type *, vector<pair<string, Value*>>> variablelist;
	variablelist = make_pair(genIRDtype(Node->varlist.type), genIRVar(Node->varlist.list));
	return variablelist;	
}

vector<pair<string, Value *>> genIRVar(struct ASTNode *Node)
{
	vector<pair<string, Value *>> args;
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

pair<Type *, pair<string, Value *>> genIRParam(struct ASTNode *Node)
{
	pair<Type *, pair<string, Value *>> parameter;
	parameter = make_pair(genIRDtype(Node->param.type), genIRId(Node->param.var));
	return parameter;
}

Type *genIRDtype(struct ASTNode *Node)
{
	if(Node->dtype == "int")
		return Builder.getInt32Ty();

}
pair<string, Value *> genIRId(struct ASTNode *Node)
{	
	if(Node->nodetype == IDLIT)
		return make_pair(Node->idlit, null);
	else if(Node->nodetype == Array1D){
		string name = Node->array1dnode.name;
		Value *val = Builder.getInt32(Node->array1dnode.value->litval);
		return make_pair(name, val);
	}
}

void genIRCode(struct ASTNode *Node, int i)
{
	switch(Node->nodetype){
		case Func:{
				// plist parameterlist;
				IRFunction *Func = genIRFunction(Node);
				Value *last_inst = genIRStatlist(Node->functionnode.statlist, Func);
				if(!isa<ReturnInst>(last_inst))
					Builder.CreateRet(Builder.getInt32(10));
				if(Func->func != NULL)
					verifyFunction(*Func->func);
				// free(Func);
			}
				break;
		case FuncList:{
				genIRCode(Node->functionlist.left, i+1);
				if(Node->functionlist.right != NULL)
					genIRCode(Node->functionlist.right, i+1);
			}
				break;
		default: break;
	}
	if(i==0)
		ModuleOb->print(errs(), nullptr);
}


