#include "ast_inter.h"

vector<vector<INT>> intvariable;
vector<vector<FLOAT>> floatvariable;
int evalFunction(struct ASTNode *Node)
{
	vector<INT>intvar;
	vector<FLOAT>floatvar;
	vector<VAR> varlist;
	if(Node->functionnode.varlist != NULL){
		varlist = genVarList(varlist, Node->functionnode.varlist);
	}
	for(uint i=0; i < varlist.size(); i++){
		if(varlist[i].first == "int"){
			for(uint j=0; j < varlist[i].second.size(); j++)
				intvar.push_back((varlist[i].second)[j]);
		}
		else{
			for(uint j=0; j < varlist[i].second.size(); j++)
				floatvar.push_back((varlist[i].second)[j]);	
		}
	}
	intvariable.push_back(intvar);
	floatvariable.push_back(floatvar);

	return evalStatList(Node->functionnode.statlist);
}

vector<VAR> genVarList(vector<VAR> varlist, struct ASTNode *Node)
{
	varlist.push_back(genVarDec(Node->vardeclist.left));
	if(Node->vardeclist.right != NULL)
		varlist = genVarList(varlist, Node->vardeclist.right);
	return varlist;
}

VAR genVarDec(struct ASTNode *Node)
{
	VAR list;
	list = make_pair(Node->varlist.type->idlit, genVar(Node->varlist.list));
	return list;
}

vector<INT> genVar(struct ASTNode *Node)
{
	vector<INT> args;
	args.push_back(genId(Node->vardec.left));
	if(Node->vardec.right != NULL){
		Node = Node->vardec.right;
		args.push_back(genId(Node->vardec.left));
	}
	return args;
}

INT genId(struct ASTNode *Node)
{
	if(Node->nodetype == IDLIT)
		return make_pair(Node->idlit, 0);
	else if(Node->nodetype == Array1D)
		return make_pair(Node->array1dnode.name, Node->array1dnode.value->litval);
}

int evalStatList(struct ASTNode *Node)
{
	int val = evalStat(Node->statement.left);
	if(Node->statement.right != NULL)
		val = evalStatList(Node->statement.right);
	return val;
}

int arithOp(int left, int right, string op)
{
	if(op == "+" || op == "+=")		return left+right;
	else if (op == "-" || op == "-=") return left-right;
	else if (op == "*" || op == "*=") return left*right;
	else if (op == "/" || op == "/=") return left/right;
	else if (op == "%" || op == "%=") return left%right;
	return invalid;
}

int relOp(int left, int right, string op)
{
	if(op == ">")		return (left>right);
	else if(op == ">=")	return (left>=right);
	else if(op == "<")	return (left<right);
	else if(op == "<=")	return (left<=right);
	else if(op == "==")	{return (left==right);}
	else if(op == "!=")	return (left!=right);
	return invalid;
}

int evalStat(struct ASTNode *Node)
{
	switch(Node->nodetype){
		case BinaryOp:{
			switch(Node->binarynode.optype){
				case SUMOP:{
				 			return arithOp(evalStat(Node->binarynode.left),
				 				evalStat(Node->binarynode.right),
				 				Node->binarynode.op);
					}
				case MULOP:{
							return arithOp(evalStat(Node->binarynode.left),
								evalStat(Node->binarynode.right),
								Node->binarynode.op);
					}
				case ASSIGN:{
						string leftop = Node->binarynode.left->idlit;
						int right = evalStat(Node->binarynode.right);
						assginValue(leftop, right);
						return invalid;
					}
				case DASSIGN:{
						string leftop = Node->binarynode.left->idlit;
						int right = evalStat(Node->binarynode.right);
						int left = evalStat(Node->binarynode.left);
						assginValue(leftop, arithOp(left,right, Node->binarynode.op));
						return invalid;
					}
				case ANDOP: return evalStat(Node->binarynode.left) && evalStat(Node->binarynode.right);
				case OROP: return evalStat(Node->binarynode.left) || evalStat(Node->binarynode.right);
				case RELOP:{
						return relOp(evalStat(Node->binarynode.left),
							evalStat(Node->binarynode.right), 
							Node->binarynode.op);
					}
				case RELDOP:{
						return relOp(evalStat(Node->binarynode.left),
							evalStat(Node->binarynode.right), 
							Node->binarynode.op);
					}	
			}
		}
				break;
		case UnaryOp: {
				if(Node->unarynode.optype == NOTOP)
					return !(evalStat(Node->unarynode.operand));
				else{
					if(Node->unarynode.op == "-")
						return -(evalStat(Node->unarynode.operand));
					else
						return evalStat(Node->unarynode.operand);
				}
			}
				break;
		case INTLIT: return Node->litval;
		case FLT_LIT: return Node->litval;
		case IDLIT: return idLitVal(Node);
		case Return : return evalStat(Node->returnstat.expr);
		case If:{
				// cout << evalStat(Node->ifnode.condition) << endl;
				if(evalStat(Node->ifnode.condition)){
					return evalStatList(Node->ifnode.ifstat);
				}
				else{
					if(Node->ifnode.elsestat != NULL)
						return evalStatList(Node->ifnode.elsestat);
					else
						return invalid;
				}
			}
		case For:{
				int init = evalStat(Node->fornode.init);
				while(evalStat(Node->fornode.condition)){
					int stat = evalStatList(Node->fornode.statlist);
					int update = evalStat(Node->fornode.update);
				}
				return invalid;
			}
		case While:{
				while(evalStat(Node->whilenode.condition))
					int stat = evalStatList(Node->whilenode.statlist);
				return invalid;
			}
		case Output:{
				return evalStat(Node->outputstat.list);
			}
		case OutputList:{
				if(Node->outputlist.left != NULL){
					cout << evalStat(Node->outputlist.left); 
				}
				if(Node->outputlist.right != NULL)
					return evalStat(Node->outputlist.right); 
				return invalid;
			}
		default : return invalid;
	}
}

void assginValue(string op, int val)
{
	bool found = false;
	for(uint i=0; i < intvariable.size(); i++){
		for(uint j=0; j < intvariable[i].size(); j++){
			if(op == intvariable[i][j].first){
				intvariable[i][j].second = val;
				found = true;
				break;
			}
		}
	}
	if(!found){
		cout << "Error : Variable " << op << " not declared" << endl;
		exit(1);
	}
}

int idLitVal(struct ASTNode *Node)
{	
	for(uint i=0; i < intvariable.size(); i++){
		for(uint j=0; j < intvariable[i].size(); j++){
			if(Node->idlit == intvariable[i][j].first)
				return intvariable[i][j].second;
		}
	}
	cout << "Variable not defined" << endl;
	return invalid;
}

void interpret(struct ASTNode *Node)
{
	switch(Node->nodetype){
		case DecList:{
					interpret(Node->declist.funclist);
					if(Node->declist.global != NULL);
						// globalVar(Node->declist.global);
			}
				break;
		case FuncList:{
					interpret(Node->functionlist.left);
					if(Node->functionlist.right != NULL)
						interpret(Node->functionlist.right);
			}
				break;
		case Func:{
					if(Node->functionnode.type->dtype == "int"){
						int val = evalFunction(Node);
						if(val == invalid){
							cout << "Value not returned from function" << endl;
							exit(1);
						}
					}
			}
				break;
		default: break;
	}
}