#include "ir_gen.h"
#include <iostream>

vector<pair<GlobalVariable *, string>> globlist;
vector<string> funcname;
// void genIRBinOp(struct ASTNode *Node)
// {

// }
Value *arithOp(Value *left, Value *right, string op)
{
	if(op == "+" || op == "+=")		return Builder.CreateAdd(left, right, "sum");
	else if (op == "-" || op == "-=") return Builder.CreateNSWSub(left, right, "diff");
	else if (op == "*" || op == "*=") return Builder.CreateNSWMul(left, right, "mul");
	else if (op == "/" || op == "/=") return Builder.CreateSDiv(left, right, "div");
	else if (op == "%" || op == "%=") return Builder.CreateURem(left, right, "rem");
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
	if(op == ">")		return Builder.CreateICmpSGT(left, right, "gt");
	else if(op == ">=")	return Builder.CreateICmpSGE(left, right, "ge");
	else if(op == "<")	return Builder.CreateICmpSLT(left, right, "lt");
	else if(op == "<=")	return Builder.CreateICmpSLE(left, right, "le");
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
						if(right != null)
							return arithOp(left, right, Node->binarynode.op);
						else return null;
					}
				case MULOP:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return arithOp(left, right, Node->binarynode.op);
					}
				case ASSIGN:{
						Value *leftop = getAddress(Node->binarynode.left, Func);
						if(leftop == null){
							cout << "Error:Variable " << Node->binarynode.left->idlit
							<< " not defined" << endl;
							exit(1);
						}
						Value *right = genIRStat(Node->binarynode.right, Func);
						return Builder.CreateStore(right, leftop);;
					}
				case DASSIGN:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						Value *leftop = getAddress(Node->binarynode.left, Func);
						if(leftop == null){
							cout << "Error:Variable " << Node->binarynode.left->idlit
							<< " not defined" << endl;
							exit(1);
						}
						left = arithOp(left, right, Node->binarynode.op);
						return Builder.CreateStore(left, leftop);
					}
				case ANDOP:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return Builder.CreateAnd(left, right, "and");
					}
				case OROP:{
						Value *left = genIRStat(Node->binarynode.left, Func);
						Value *right = genIRStat(Node->binarynode.right, Func);
						return Builder.CreateOr(left, right, "or");
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
							return Builder.CreateNot(operand, "not");
						}
						else{
							if(Node->unarynode.op == "-"){
								Value *operand = genIRStat(Node->unarynode.operand, Func);
								return arithOp(Builder.getInt32(-1), operand, "*");
							}
							else
								return genIRStat(Node->unarynode.operand, Func);
						}
						break;
			}
		case TernaryOp:{
					Value *cond = genIRStat(Node->ternarynode.first, Func);
					BasicBlock *first = createBB(Func->func, "first");
					BasicBlock *second = createBB(Func->func, "second");
					BasicBlock *Merge = createBB(Func->func, "Merge");
					Builder.CreateCondBr(cond, first, second);

					Builder.SetInsertPoint(first);
					Value *one = genIRStat(Node->ternarynode.second, Func);
					Builder.CreateBr(Merge);
					Builder.SetInsertPoint(second);
					Value *two = genIRStat(Node->ternarynode.third, Func);
					Builder.CreateBr(Merge);

					Builder.SetInsertPoint(Merge);
					PHINode *Phi = Builder.CreatePHI(Builder.getInt32Ty(),2);
					Phi->addIncoming(one, first);
					Phi->addIncoming(two, second);
					return Phi;
			}
		case IDLIT:	{return genOperand(Node, Func);}
		case INTLIT: {return genOperand(Node, Func);}
		case FLT_LIT: return genOperand(Node, Func);
		case Array1D: return getArrayVal(Node, Func);
		case BOOLLIT: return genOperand(Node, Func);
		case Return : return Builder.CreateRet(genIRStat(Node->returnstat.expr, Func));
		case StringOp: {
				Value *leftop = getAddress(Node->stringnode.operand, Func);
 				Builder.CreateStore(genString(Node->stringnode.str), leftop);
 				AllocaInst *str = new AllocaInst(Builder.getInt8PtrTy(), 0, "str", Func->bb);
 				BitCastInst *bit = new BitCastInst(leftop, Builder.getInt8PtrTy());
 				return Builder.CreateStore(bit, str);
			}
		case FunCall:{
					Function *call = findFunc(Node->funcall.name);
					vector<Value*>args;
					args = genFuncArgs(args, Node->funcall.arglist, Func);
					return Builder.CreateCall(call, makeArrayRef(args), "call");
			}
		case If:{
				Value *cond = genIRStat(Node->ifnode.condition, Func);
				BasicBlock *If = createBB(Func->func, "If");
				BasicBlock *Else, *Merge;
				if(Node->ifnode.elsestat != NULL){
					Else  = createBB(Func->func, "Else");
					Builder.CreateCondBr(cond, If, Else);
					Merge = createBB(Func->func, "Merge");

				}
				else{
					Merge = createBB(Func->func, "Merge");
					Builder.CreateCondBr(cond, If, Merge);
				} 
				Builder.SetInsertPoint(If);
				Value *IfVal = genIRStatlist(Node->ifnode.ifstat, Func); 
				Builder.CreateBr(Merge);
				if(Node->ifnode.elsestat != NULL){
					Builder.SetInsertPoint(Else);
					Value *ElseVal = genIRStatlist(Node->ifnode.elsestat, Func);
					Builder.CreateBr(Merge);
				}

				Builder.SetInsertPoint(Merge);
				return null;
			}
		case For:{
				BasicBlock *For = createBB(Func->func, "for");
				Value *start = genIRStat(Node->fornode.init, Func);
				Value *cond = genIRStat(Node->fornode.condition, Func);
				BasicBlock *After = createBB(Func->func, "afterfor");
				Builder.CreateCondBr(cond, For, After);
				Builder.SetInsertPoint(For);
				Value *stat = genIRStatlist(Node->fornode.statlist, Func);
				Value *update = genIRStat(Node->fornode.update, Func);
				cond = genIRStat(Node->fornode.condition, Func);
				Builder.CreateCondBr(cond, For, After);
				Builder.SetInsertPoint(After);
				return null;
			}
		case While:{
				BasicBlock *While = createBB(Func->func, "while");
				BasicBlock *After = createBB(Func->func, "afterwhile");
				Value *cond = genIRStat(Node->whilenode.condition, Func);
				Builder.CreateCondBr(cond, While, After);
				Builder.SetInsertPoint(While);
				Value *stat = genIRStatlist(Node->whilenode.statlist, Func);
				cond = genIRStat(Node->whilenode.condition, Func);
				Builder.CreateCondBr(cond, While, After);
				Builder.SetInsertPoint(After);

				return null;
			}
		case Output:{
				vector<Value *> args;
				vector<pair<string, Value *>>arg;
				arg = genPrintList(arg, Node->outputstat.list, Func);
				string str = "";
				for(uint i=0; i < arg.size(); i++){
					str += arg[i].first;
					args.push_back(arg[i].second);
				}
				Value *spec = Builder.CreateGlobalStringPtr(str);
				args.insert(args.begin(), spec);

				// args.push_back(arg[0]);
				Function *print = ModuleOb->getFunction("printf");
				if (!print) {
			        PointerType *Pty = PointerType::get(Builder.getInt8Ty(), 0);
			        FunctionType *FuncTy9 = FunctionType::get(Builder.getInt32Ty(), Pty, true);

			        print = Function::Create(FuncTy9, GlobalValue::ExternalLinkage, "printf", ModuleOb);
			        print->setCallingConv(CallingConv::C);
			    }
				return Builder.CreateCall(print, args, "print");
			}
		
		default: break;

	}
	return null;
}

PointerType *getPtr(Value *val)
{
	if(val->getType() == Builder.getInt32Ty())
		return PointerType::get(Builder.getInt32Ty(), 0);
	else
		return Builder.getInt8PtrTy();
}

vector<pair<string, Value *>> genInputList(vector<pair<string, Value *>> args, struct ASTNode *Node, IRFunction *Func)
{
	if(Node->inputlist.left != NULL){
		Value *val = genIRStat(Node->inputlist.left, Func);
		string type = typeToString(val->getType());
		args.push_back(make_pair(type, val));
	}
	if(Node->inputlist.right != NULL)
		args = genInputList(args, Node->inputlist.right, Func);
	return args;
}

vector<pair<string, Value *>> genPrintList(vector<pair<string, Value *>> args, struct ASTNode *Node, IRFunction *Func)
{
	if(Node->outputlist.left != NULL){
		Value *val = genIRStat(Node->outputlist.left, Func);
		string type = typeToString(val->getType());
		args.push_back(make_pair(type, val));
	}
	if(Node->outputlist.str != "NULL")
		args.push_back(make_pair("%s", genString(Node->outputlist.str)));
	
	if(Node->outputlist.right != NULL)
		args = genPrintList(args, Node->outputlist.right, Func);
	return args;
}
string typeToString(Type *type)
{
	if(type == Builder.getFloatTy())
		return "%f";
	if(type == Builder.getInt8Ty())
		return "%s";
	else return "%d";
}

Value *genString(string s)
{
	if(s == "\\n")
		s = "\n";
	else if(s == "\\t")
		s = "\t";
	return Builder.CreateGlobalStringPtr(s);
}
vector <Value *> genFuncArgs(vector<Value *>args, struct ASTNode *Node, IRFunction *Func)
{
	if(Node->arg.left != NULL)
		args.push_back(genIRStat(Node->arg.left, Func));
	if(Node->arg.right != NULL)
		args = genFuncArgs(args, Node->arg.right, Func);
	return args;
}
Function *findFunc(string name)
{
	for(uint i=0; i < funcname.size(); i++){
		if(name == funcname[i])
			return ModuleOb->getFunction(name);
	}
	cout << "Error:Function " << name << " not defined" << endl;
	exit(1);
}

Value *getArrayVal(struct ASTNode *Node, struct IRFunction *Func)
{
	return Builder.CreateAlignedLoad(getArrayAddress(Node, Func), 16);	
}

Value *getArrayAddress(struct ASTNode *Node, struct IRFunction *Func)
{
	Value *val = genIRStat(Node->array1dnode.value, Func);
	Value *base;
	//Checking for function parameter
	for(uint i=0; i<Func->args.size(); i++){
		if(Func->args[i].second == Node->idlit){
			base = Func->args[i].first;
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
	for(uint i=0; i < globlist.size(); i++){
		if(Node->idlit == globlist[i].second){
			base = globlist[i].first;
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
		return getArrayAddress(Node, Func);
	}

	//Checking for function parameter
	for(uint i=0; i<Func->args.size(); i++){
		if(Func->args[i].second == Node->idlit){
			return Func->args[i].first;
		}
	}
	//Checking for local variable
	for(uint i=0; i < Func->alloc.size(); i++){
		if(Func->alloc[i].second == Node->idlit){
			return Func->alloc[i].first;
		}
	}
	//Checking for global variable
	for(uint i=0; i < globlist.size(); i++){
		if(Node->idlit == globlist[i].second)
			return globlist[i].first;
	}	
	return null;
}

Value *genOperand(struct ASTNode *Node, struct IRFunction *Func)
{
	switch(Node->nodetype){
		case INTLIT: return Builder.getInt32(Node->litval);
		case FLT_LIT: {cout << Node->flt_litval;return ConstantFP::get(Builder.getFloatTy(), Node->flt_litval);}
		case IDLIT: {
					Value *val = getIdVal(Node->idlit, Func);
					if(val == null){
						cout << "Error:Variable " << Node->idlit << " not defined" << endl;
						exit(1);
					}
					return val;
				}
		case Array1D: return getArrayVal(Node, Func);
		case BOOLLIT: {
					if(Node->boollit == "True")
						return Builder.getInt1(true);
					else
						return Builder.getInt1(false);
				}
		default: break;

	}
	return null;
}

Value *getIdVal(string id, struct IRFunction *Func)
{
	//Checking for function parameter
	for(uint i=0; i<Func->args.size(); i++){
		if(Func->args[i].second == id){
			return Func->args[i].first;
		}
	}
	//Checking for local variable
	for(uint i=0; i < Func->alloc.size(); i++){
		if(Func->alloc[i].second == id){
			return Builder.CreateAlignedLoad(Func->alloc[i].first, 4);
		}
	}
	//Checking for global variable
	cout << globlist.size() << endl;
	for(uint i=0; i < globlist.size(); i++){
		cout << "Checking" << endl;
		if(id == globlist[i].second)
			return globlist[i].first;
	}
	
	
	return null;
}


vector<pair<Value *, string>> setFuncArgs(Function *func, vector<string> args)
{
	int i=0;
	vector<pair<Value *, string>> arg;
	Function::arg_iterator l, r;
	for(l = func->arg_begin(), r = func->arg_end(); l!= r; l++, i++){
		l->setName(args[i]);
		arg.push_back(make_pair(l, args[i]));
	}
	return arg;
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
	struct IRFunction *newfunc = NULL;
	newfunc = (struct IRFunction *) malloc(sizeof(struct IRFunction));
	plist parameterlist;
	vlist variablelist;
	vector<string> arg;

	funcname.push_back(Node->functionnode.name);
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
		arg.push_back(parameterlist[i].second.first);
	}

 	FunctionType *funcType = FunctionType::get(Return, argType, false);
	Function *func = cast<Function>(ModuleOb->getOrInsertFunction(Node->functionnode.name, funcType));

	if(parameterlist.size() > 0)
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
	newfunc->bb = entry;

	newfunc->alloc = allocMem(parameterlist, entry);
	newfunc->args = setFuncArgs(func, arg);

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
	else if(Node->dtype == "char")
		return Builder.getInt8Ty();
	else if(Node->dtype == "bool")
		return Builder.getInt1Ty();
	else return Builder.getDoubleTy();

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
	else return make_pair(Node->idlit, null);
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
				free(Func);
			}
				break;
		case FuncList:{
				genIRCode(Node->functionlist.left, i+1);
				if(Node->functionlist.right != NULL){
					genIRCode(Node->functionlist.right, i+1);
				}
			}
				break;
		case DecList:{
				if(Node->declist.global != NULL){
					genGlobalVar(Node->declist.global);
				}
				genIRCode(Node->declist.funclist, i+1);
			}
				break;
		default: break;
	}
	if(i==0){
		ModuleOb->print(errs(), nullptr);
		// ModuleOb->dump();
	}
}


