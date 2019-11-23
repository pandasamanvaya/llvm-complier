#include <stdio.h>
#include <stdlib.h>
#include "ir_gen.h"

struct ASTNode *getASTNodeBinaryOp(struct ASTNode *left, 
									struct ASTNode *right, 
									BinaryOpType optype,
									string *op)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	// printf("%s\n", op->c_str());
	node->nodetype = BinaryOp;
	node->binarynode.left = left;
	node->binarynode.right = right;
	node->binarynode.optype = optype;
	node->binarynode.op = *op;
	// genIRBinOp(node);
	return node;
}

struct ASTNode *getASTNodeUnaryOp(struct ASTNode *operand, 
									BinaryOpType optype,
									string *op)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = UnaryOp;
	node->unarynode.operand = operand;
	node->unarynode.optype = optype;
	node->unarynode.op = *op;

	return node;
}

struct ASTNode *getASTNodeStringOp(struct ASTNode *operand, 
									string *str)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = StringOp;
	node->stringnode.operand = operand;
	node->stringnode.str = *str;

	return node;
}

struct ASTNode *getASTNode1DArray(string *name,
							 struct ASTNode *value)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Array1D;
	node->array1dnode.value = value;
	node->array1dnode.name = *name;

	return node;
}

struct ASTNode *getASTNode2DArray(string *name,
							 struct ASTNode *value1,
							 struct ASTNode *value2)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Array2D;
	node->array2dnode.value1 = value1;
	node->array2dnode.value2 = value2;
	node->array2dnode.name = *name;

	return node;
}

struct ASTNode *getASTNodeTernaryOp(struct ASTNode *first, 
									struct ASTNode *second,
									struct ASTNode *third)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));

	node->nodetype = TernaryOp;
	node->ternarynode.first = first;
	node->ternarynode.second = second;
	node->ternarynode.third = third;

	return node;
}

struct ASTNode *getASTNodeIntLiteral(int litval)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = INTLIT;
	node->litval = litval;
	return node;
}

struct ASTNode *getASTNodeBoolLiteral(string *litval)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = BOOLLIT;
	node->boollit = *litval;

	return node;
}

struct ASTNode *getASTNodeWhile(struct ASTNode *condition,
							struct ASTNode *varlist,
							struct ASTNode *statlist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = While;
	node->whilenode.condition = condition;
	node->whilenode.varlist = varlist;
	node->whilenode.statlist = statlist;

	return node;
}

struct ASTNode *getASTNodeIf(struct ASTNode *condition,
							struct ASTNode *ifvar,
							struct ASTNode *ifstat,
							struct ASTNode *elsevar,
							struct ASTNode *elsestat)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = If;
	node->ifnode.condition = condition;
	node->ifnode.ifvar = ifvar;
	node->ifnode.ifstat = ifstat;
	node->ifnode.elsevar = elsevar;
	node->ifnode.elsestat = elsestat;
	return node;
}

struct ASTNode *getASTNodeFor(struct ASTNode *init,
							struct ASTNode *condition,
							struct ASTNode *update,
							struct ASTNode *varlist,
							struct ASTNode *statlist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = For;
	node->fornode.init = init;
	node->fornode.condition = condition;
	node->fornode.update = update;
	node->fornode.varlist = varlist;
	node->fornode.statlist = statlist;

	return node;
}

struct ASTNode *getASTNodeFuncList(struct ASTNode *left,
								struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = FuncList;
	node->functionlist.left = left;
	node->functionlist.right = right;
	// genIRCode(node);
	// if(node->functionlist.right != NULL)
	// 	genIRCode(node->functionlist.right);

	return node;
}

struct ASTNode *getASTNodeFunction(struct ASTNode *type,
								string *name,
								struct ASTNode *paramlist,
								struct ASTNode *varlist,
								struct ASTNode *statlist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Func;
	node->functionnode.name = *name;
	node->functionnode.type = type;
	node->functionnode.paramlist = paramlist;
	node->functionnode.varlist = varlist;
	node->functionnode.statlist = statlist;
	return node;
}

struct ASTNode *getASTNodeInputStat(struct ASTNode *statlist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Input;
	node->inputstat.list = statlist;

	return node;
}

struct ASTNode *getASTNodeInputList(struct ASTNode *left,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = InputList;
	node->inputlist.left = left;
	node->inputlist.right = right;

	return node;
}

struct ASTNode *getASTNodeOutputStat(struct ASTNode *statlist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Output;
	node->outputstat.list = statlist;

	return node;
}

struct ASTNode *getASTNodeOutputList(struct ASTNode *left,
									string *str,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = OutputList;
	node->outputlist.left = left;
	node->outputlist.str = *str;
	node->outputlist.right = right;

	return node;
}

struct ASTNode *getASTNodeVarDecList(struct ASTNode *left,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = VarDecList;
	node->vardeclist.left = left;
	node->vardeclist.right = right;
	return node;
}

struct ASTNode *getASTNodeVarList(struct ASTNode *type,
									struct ASTNode *list)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Varlist;
	node->varlist.type = type;
	node->varlist.list = list;
	return node;
}

struct ASTNode *getASTNodeVardec(struct ASTNode *left,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Vardec;
	node->vardec.left = left;
	node->vardec.right = right;
	return node;
}

struct ASTNode *getASTNodeStat(struct ASTNode *left,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Statement;
	node->statement.left = left;
	node->statement.right = right;
	return node;
}

struct ASTNode *getASTNodeParamList(struct ASTNode *left,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = ParamList;
	node->paramlist.left = left;
	node->paramlist.right = right;
	return node;
}

struct ASTNode *getASTNodeParam(struct ASTNode *type,
							struct ASTNode *var)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Param;
	node->param.type = type;
	node->param.var = var;
	return node;
}

struct ASTNode *getASTNodeReturn(struct ASTNode *expr)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Return;
	node->returnstat.expr = expr;
	return node;
}

struct ASTNode *getASTNodeFunCall(string *name,
							struct ASTNode *arglist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = FunCall;
	node->funcall.name = *name;
	node->funcall.arglist = arglist;
	return node;
}

struct ASTNode *getASTNodeArg(struct ASTNode *left,
							struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = ArgList;
	node->arg.left = left;
	node->arg.right = right;
	return node;
}

struct ASTNode *getASTNodeDType(string *type)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Dtype;
	node->dtype = *type;
	// printf("%s", node->dtype);
	return node;
}

struct ASTNode *getASTNodeIDLiteral(string *litval)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = IDLIT;
	node->idlit = *litval;

	return node;
}

void printIR(struct ASTNode *node)
{
	printf("------------------------\n");
	printf("LLVM IR Code generated :-\n");
	printf("------------------------\n");
	genIRCode(node, 0);

}
