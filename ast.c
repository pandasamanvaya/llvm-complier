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

struct ASTNode *getASTNodeWhile(struct ASTNode *condition)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = While;
	node->whilenode.condition = condition;

	return node;
}

struct ASTNode *getASTNodeIf(struct ASTNode *condition)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = If;
	node->ifnode.condition = condition;

	return node;
}

struct ASTNode *getASTNodeFor(struct ASTNode *init,
							struct ASTNode *condition,
							struct ASTNode *update)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = For;
	node->fornode.init = init;
	node->fornode.condition = condition;
	node->fornode.update = update;

	return node;
}

struct ASTNode *getASTNodeFunction(char *name)
{
	struct ASTNode *node; 

	node = (struct ASTNode *) malloc(sizeof(struct ASTNode));
	node->nodetype = Function;
	node->functionnode.name = name;

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

void printPostFix(struct ASTNode *root)
{	
	switch (root->nodetype) 
	{
		case BinaryOp:
						printPostFix(root->binarynode.left);
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
						printPostFix(root->binarynode.right);
						break;

		case TernaryOp: printPostFix(root->ternarynode.first);
						printf("? ");
						printPostFix(root->ternarynode.second);
						printf(": ");
						printPostFix(root->ternarynode.third);
						// printf("? ");
						break;

		case StringOp: printPostFix(root->stringnode.operand);
						printf(" = ");
						printf("%s", root->stringnode.string);
						break;
		case Array1D:
					printf("%s[", root->array1dnode.name);
					if(root->array1dnode.value != NULL)
						printPostFix(root->array1dnode.value);
					printf("]");
					break;
		case Array2D:
					printf("%s[", root->array2dnode.name);
					if(root->array2dnode.value1 != NULL)
						printPostFix(root->array2dnode.value1);
					printf("][");
					printPostFix(root->array2dnode.value2);
					printf("]");
					break;
		case Function:
					printf("%s(", root->functionnode.name);
					break;
		case INTLIT: printf("%d", root->litval);
						break;
		case BOOLLIT: printf("%s", root -> boollit);
						break;
		case IDLIT:	printf("%s", root -> idlit);
						break;
		case While: printPostFix(root->whilenode.condition);
						break;
		case For: printPostFix(root->fornode.init);
					printPostFix(root->fornode.condition);
					printPostFix(root->fornode.update);
						break;
		case If: printPostFix(root->ifnode.condition);
						break;
	}
};