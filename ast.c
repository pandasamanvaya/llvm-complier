#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

struct ASTNode *getASTNodeBinaryOp(struct ASTNode *left, 
									struct ASTNode *right, 
									BinaryOpType optype,
									char *operator)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	// printf("%s\n", operator);
	node->nodetype = BinaryOp;
	node->binarynode.left = left;
	node->binarynode.right = right;
	node->binarynode.optype = optype;
	node->binarynode.operator = operator;

	return node;
}

struct ASTNode *getASTNodeUnaryOp(struct ASTNode *operand, 
									BinaryOpType optype,
									char *operator)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = UnaryOp;
	node->unarynode.operand = operand;
	node->unarynode.optype = optype;
	node->unarynode.operator = operator;

	return node;
}

struct ASTNode *getASTNodeStringOp(struct ASTNode *operand, 
									char *string)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = StringOp;
	node->stringnode.operand = operand;
	node->stringnode.string = string;

	return node;
}

struct ASTNode *getASTNode1DArray(char *name,
							 struct ASTNode *value)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Array1D;
	node->array1dnode.value = value;
	node->array1dnode.name = name;

	return node;
}

struct ASTNode *getASTNode2DArray(char *name,
							 struct ASTNode *value1,
							 struct ASTNode *value2)
{
	struct ASTNode *node; 
	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Array2D;
	node->array2dnode.value1 = value1;
	node->array2dnode.value2 = value2;
	node->array2dnode.name = name;

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

struct ASTNode *getASTNodeBoolLiteral(char *litval)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = BOOLLIT;
	node->boollit = litval;

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

struct ASTNode *getASTNodeFunction(struct ASTNode *type,
								char *name,
								struct ASTNode *paramlist,
								struct ASTNode *varlist,
								struct ASTNode *statlist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Function;
	node->functionnode.name = name;
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
									char *str,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = OutputList;
	node->outputlist.left = left;
	node->outputlist.str = str;
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

struct ASTNode *getASTNodeStat(struct ASTNode *left,
									struct ASTNode *right)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Statement;
	node->statment.left = left;
	node->statment.right = right;
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

struct ASTNode *getASTNodeFunCall(char *name,
							struct ASTNode *arglist)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = FunCall;
	node->funcall.name = name;
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

struct ASTNode *getASTNodeDType(char *type)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Dtype;
	node->dtype = type;
	// printf("%s", node->dtype);
	return node;
}

struct ASTNode *getASTNodeIDLiteral(char *litval)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = IDLIT;
	node->idlit = litval;

	return node;
}

void printAST(struct ASTNode *root)
{	
	switch (root->nodetype) 
	{
		case BinaryOp:
						printAST(root->binarynode.left);
						char *op = root->binarynode.operator;
						switch (root->binarynode.optype) 
						{
							case SUMOP:
								if(!strcmp(op, "+"))
									printf(" + ");
								else
									printf(" - ");
								break; 
							case MULOP:
								if(!strcmp(op, "*"))
									printf(" * ");
								else if(!strcmp(op, "/"))
									printf(" / ");
								else printf(" %% ");
								break;
							case ANDOP:
								printf(" and ");
								break;
							case OROP:
								printf(" or ");
								break;
							case RELOP:
								if(!strcmp(op, "<"))
									printf(" < ");
								else
									printf(" > ");
								break;
							case RELDOP:
								if(!strcmp(op, "<="))
									printf(" <= ");
								else if(!strcmp(op, ">="))
									printf(" >= ");
								else
									printf(" == ");
								break;
							case ASSIGN:
								printf(" = ");
								break;
							case DASSIGN:
								if(!strcmp(op, "+="))
									printf(" += ");
								else if(!strcmp(op, "-="))
									printf(" -= ");
								else if(!strcmp(op, "*="))
									printf(" *= ");
								else if(!strcmp(op, "/="))
									printf(" /= ");
								else 
									printf(" != ");
								break;
						}
						printAST(root->binarynode.right);
						break;

		case TernaryOp: printAST(root->ternarynode.first);
						printf("? ");
						printAST(root->ternarynode.second);
						printf(": ");
						printAST(root->ternarynode.third);
						break;
		case UnaryOp:  printf("%s ", root->unarynode.operator);
						printAST(root->unarynode.operand);
						break;
		case StringOp: printAST(root->stringnode.operand);
						printf(" = ");
						printf("%s", root->stringnode.string);
						break;
		case Array1D:
					printf("%s[", root->array1dnode.name);
					if(root->array1dnode.value != NULL)
						printAST(root->array1dnode.value);
					printf("]");
					break;
		case Array2D:
					printf("%s[", root->array2dnode.name);
					if(root->array2dnode.value1 != NULL)
						printAST(root->array2dnode.value1);
					printf("][");
					printAST(root->array2dnode.value2);
					printf("]");
					break;
		case Function:
					printAST(root->functionnode.type);
					printf(" %s( ", root->functionnode.name);
					if(root->functionnode.paramlist != NULL)
						printAST(root->functionnode.paramlist);
					printf(")\n{\n");
					if(root->functionnode.varlist != NULL)
						printAST(root->functionnode.varlist);
					printAST(root->functionnode.statlist);
					printf("}");
					break;
		case Dtype:	printf("%s ", root->dtype);
						break;
		case INTLIT: printf("%d", root->litval);
						break;
		case BOOLLIT: printf("%s", root -> boollit);
						break;
		case IDLIT:	printf("%s", root -> idlit);
						break;
		case While: printf("while(");
					printAST(root->whilenode.condition);
					printf("){\n");
					if(root->whilenode.varlist != NULL)
						printAST(root->whilenode.varlist);
					printAST(root->whilenode.statlist);
					printf("}");
						break;
		case For: 	printf("for( ");
					printAST(root->fornode.init);
					printf("; ");
					printAST(root->fornode.condition);
					printf("; ");
					printAST(root->fornode.update);
					printf("){\n");
					if(root->fornode.varlist != NULL)
						printAST(root->fornode.varlist);
					printAST(root->fornode.statlist);
					printf("}");
						break;
		case If: printf("if ("); 
				printAST(root->ifnode.condition);
				printf("){\n");
				if(root->ifnode.ifvar != NULL)
					printAST(root->ifnode.ifvar);
				printAST(root->ifnode.ifstat);
				printf("}\n");
				if(root->ifnode.elsestat != NULL){
					printf("else{\n");
					if(root->ifnode.elsevar != NULL) 
						printAST(root->ifnode.elsevar);
					printAST(root->ifnode.elsestat);
					printf("}\n");
				}
						break;
		case Input: printf("input >> ");
					printAST(root->inputstat.list);
						break;
		case InputList: printAST(root->inputlist.left);
						if(root->inputlist.right != NULL){
							printf(" >> ");
							printAST(root->inputlist.right);
						}
						break;
		case Output: printf("print");
					printAST(root->outputstat.list);
						break;
		case OutputList:
						if(root->outputlist.left != NULL){
							printf(" << ");
							printAST(root->outputlist.left);
						}
						if(root->outputlist.str != NULL){
							printf(" << ");
							printf("%s", root->outputlist.str);
						}
						if(root->outputlist.right != NULL){
							printAST(root->outputlist.right);
						}
						break;
		case VarDecList: printAST(root->vardeclist.left);
						printf(";\n");
					if(root->vardeclist.right != NULL)
						printAST(root->vardeclist.right);
						break;

		case Vardec: printAST(root->vardec.left);
					if(root->vardec.right != NULL){
						printf(", ");
						printAST(root->vardec.right);
					}
						break;

		case Varlist: printAST(root->varlist.type); 
					printAST(root->varlist.list);
						break;
		case Statement: printAST(root->statment.left);
						printf(";\n");
					if(root->statment.right != NULL)
						printAST(root->statment.right);
						break;

		case ParamList: printAST(root->paramlist.left);
					if(root->paramlist.right != NULL){
						printf(", ");
						printAST(root->paramlist.right);
					}
						break;
		case Param:
					if(root->param.type != NULL){
						printAST(root->param.type);
						printAST(root->param.var);
					}
						break;
		case FunCall: printf("%s (", root->funcall.name);
					printAST(root->funcall.arglist);
					printf(")");	
					break;
		case ArgList: 
					if(root->arg.left != NULL)
						printAST(root->arg.left);
					if(root->arg.right != NULL){
						printf(", ");
						printAST(root->arg.right);
					}
					break;
	}
};