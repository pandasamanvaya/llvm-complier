#include "ir_gen.h"
#include <iostream>

vector<pair<GlobalVariable *, string>> globlist;

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
	return null;
}

Value *genIRStatlist(struct ASTNode *Node, struct IRFunction *Func)
{
	Value *val = genIRStat(Node->statement.left, Func);
	if(Node->statement.right != NULL)
		val = genIRStatlist(Node->statement.right, Func);
	return val;
}

Value *relOp(Value *left, Value *right, string op)
{
	if(op == ">")		return Builder.CreateICmpUGT(left, right, "gt");
	else if(op == ">=")	return Builder.CreateICmpUGE(left, right, "ge");
	else if(op == "<")	return Builder.CreateICmpULT(left, right, "lt");
	else if(op == "<=")	return Builder.CreateICmpULE(left, right, "le");
	else if(op == "==")	return Builder.CreateICmpEQ(left, right, "eq");
	else if(op == "!=")	return Builder.CreateICmpNE(left, right, "ne");
	return null;
}

Value *genIRStat(struct ASTNode *Node, struct IRFunction *Func)
{
	switch(Node->nodetype){
		case BinaryOp:{
			switch(Node->binarynode.optype){
				case SUMOP:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return arithOp(left, right, Node->binarynode.op);
					}
				case MULOP:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return arithOp(left, right, Node->binarynode.op);
					}
				case ASSIGN:{
						Value *leftop = getAddress(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return Builder.CreateAlignedStore(right, leftop, sizeof(leftop));;
					}
				case DASSIGN:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						Value *leftop = getAddress(Node->binarynode.left, Func);
						left = arithOp(left, right, Node->binarynode.op);
						return Builder.CreateAlignedStore(left, leftop, sizeof(leftop));
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
				case RELOP:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return relOp(left, right, Node->binarynode.op);	
					}
				case RELDOP:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return relOp(left, right, Node->binarynode.op);
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
		case TernaryOp:{
					
			}
		case IDLIT:	{return genOperand(Node, Func);}
		case INTLIT: return genOperand(Node, Func);
		case FLT_LIT: return genOperand(Node, Func);
		case Array1D: return getArrayVal(Node, Func);
		case Return : return Builder.CreateRet(genIRStat(Node->returnstat.expr, Func));
		case If:{
				Value *cond = genIRStat(Node->ifnode.condition, Func);
				// Value *Condtn = Builder.CreateICmpNE(cond,Builder.getInt32(0));
				BasicBlock *If = createBB(Func->func, "If");
				BasicBlock *Else = createBB(Func->func, "Else");
				BasicBlock *Merge = createBB(Func->func, "Merge");
				Builder.CreateCondBr(cond, If, Else);

				Builder.SetInsertPoint(If);
				Value *IfVal = genIRStatlist(Node->ifnode.ifstat, Func); 
				Builder.CreateBr(Merge);
				Builder.SetInsertPoint(Else);
				Value *ElseVal = genIRStatlist(Node->ifnode.elsestat, Func);
				Builder.CreateBr(Merge);

				Builder.SetInsertPoint(Merge);
				return null;
			}
		case For:{
				BasicBlock *header = Builder.GetInsertBlock();
				BasicBlock *For = createBB(Func->func, "for");
				Value *start = genIRStat(Node->fornode.init, Func);
				Builder.CreateBr(For);
				Builder.SetInsertPoint(For);
				Value *cond = genIRStat(Node->fornode.condition, Func);
				Value *stat = genIRStatlist(Node->fornode.statlist, Func);
				Value *update = genIRStat(Node->fornode.update, Func);
				BasicBlock *ForEnd = Builder.GetInsertBlock();
				BasicBlock *After = createBB(Func->func, "afterfor");
				Builder.CreateCondBr(cond, For, After);
				Builder.SetInsertPoint(After);

				return null;
			}
		case While:{
				BasicBlock *header = Builder.GetInsertBlock();
				BasicBlock *While = createBB(Func->func, "while");
				Builder.CreateBr(While);
				Builder.SetInsertPoint(While);
				Value *cond = genIRStat(Node->whilenode.condition, Func);
				Value *stat = genIRStatlist(Node->whilenode.statlist, Func);
				BasicBlock *WhileEnd = Builder.GetInsertBlock();
				BasicBlock *After = createBB(Func->func, "afterwhile");
				Builder.CreateCondBr(cond, While, After);
				Builder.SetInsertPoint(After);

				return null;
			}
		default: break;

	}
	return null;
}

Value *getArrayVal(struct ASTNode *Node, struct IRFunction *Func)
{
	return Builder.CreateAlignedLoad(getArrayAddress(Node, Func), 16);	
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
	//Checking for global variable
	uint j=0;
	for(auto i=ModuleOb->global_begin(); i != ModuleOb->global_end(); i++){
		if(globlist[j++].second == Node->idlit){
			GlobalVariable *gv = &*i;
			base = gv;
			break;
		}
	}
	Value* index[2] = {ConstantInt::get(val->getType(), 0), val};
	Value *arr = Builder.CreateGEP(base, ArrayRef<Value *>(index, 2));
	return arr;
}

Value *getAddress(struct ASTNode *Node, struct IRFunction *Func)
{
	if(Node->nodetype == Array1D){
		cout << "Called" << endl;
		return getArrayAddress(Node, Func);
	}

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
	//Checking for global variable
	uint j=0;
	for(auto i=ModuleOb->global_begin(); i != ModuleOb->global_end(); i++){
		if(globlist[j++].second == Node->idlit){
			GlobalVariable *gv = &*i;
			return gv;
			break;
		}
	}
	return null;
}

Value *genOperand(struct ASTNode *Node, struct IRFunction *Func)
{
	switch(Node->nodetype){
		case INTLIT: return Builder.getInt32(Node->litval);
		case FLT_LIT: return ConstantFP::get(Builder.getFloatTy(), Node->flt_litval);
		case IDLIT: {
					Value *val = getIdVal(Node->idlit, Func);
					if(val != null)
						cout << "Variable " << Node->idlit << " not defined" << endl;
					return val;
				}
		case Array1D: return getArrayVal(Node, Func);
		default: break;

	}
	return null;
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
			return Builder.CreateAlignedLoad(Func->alloc[i].first, 4);
		}
	}
	//Checking for global variable
	uint j=0;
	for(auto i=ModuleOb->global_begin(); i != ModuleOb->global_end(); i++){
		cout << globlist[j++].second << endl;
		if(globlist[j].second == id){
			GlobalVariable *gv = &*i;
			Constant *val = gv->getInitializer();
			// if(val != null)
				// return val;
			return Builder.getInt32(0);
			break;
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
	else if(Node->dtype == "void")
		return Builder.getVoidTy();
	else if(Node->dtype == "float")
		return Builder.getFloatTy();

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

void genGlobalVar(struct ASTNode *Node)
{
	vlist globalvar;
	plist parameterlist;
	globalvar = genIRVarList(globalvar, Node);

	for(uint i=0; i < globalvar.size(); i++){
		for(uint j=0; j < globalvar[i].second.size(); j++)
			parameterlist.push_back(make_pair(globalvar[i].first, (globalvar[i].second)[j]));
	}
	cout << "here" << endl;
	for(uint i=0; i < parameterlist.size(); i++){
		if(parameterlist[i].second.second != null){
			ConstantInt *num = dyn_cast<ConstantInt>(parameterlist[i].second.second);
			ArrayType *arr = ArrayType::get(parameterlist[i].first, num->getSExtValue());
			ModuleOb->getOrInsertGlobal(parameterlist[i].second.first, arr);
		}
		else
			ModuleOb->getOrInsertGlobal(parameterlist[i].second.first, parameterlist[i].first);

		GlobalVariable *gVar = ModuleOb->getNamedGlobal(parameterlist[i].second.first);
		gVar->setLinkage(GlobalValue::ExternalLinkage);
		gVar->setAlignment(4);
		cout << parameterlist[i].second.first << endl;
		globlist.push_back(make_pair(gVar, parameterlist[i].second.first));
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
					Builder.CreateRet(nullptr);
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
		case DecList:{
				genIRCode(Node->declist.funclist, i+1);
				if(Node->declist.global != NULL)
					genGlobalVar(Node->declist.global);
			}
				break;
		default: break;
	}
	if(i==0)
		ModuleOb->print(errs(), nullptr);
}


