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
	printf("Unary\n");
	node->nodetype = UnaryOp;
	node->unarynode.operand = operand;
	node->unarynode.optype = optype;
	node->unarynode.operator = operator;

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
	node->nodetype = INTLIT;
	printf("Bool\n");
	node->boollit = litval;

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
									printf("+ ");
								else
									printf("- ");
								break; 
							case MULOP:
								if(!strcmp(op, "*"))
									printf("* ");
								else if(!strcmp(op, "/"))
									printf("/ ");
								else printf("\% ");
								break;
							case ANDOP:
								printf("and ");
								break;
							case OROP:
								printf("or ");
								break;
							case RELOP:
								if(!strcmp(op, "<"))
									printf("< ");
								else
									printf("> ");
								break;
							case RELDOP:
								if(!strcmp(op, "<="))
									printf("<= ");
								else if(!strcmp(op, ">="))
									printf(">= ");
								else
									printf("== ");
								break;
							case ASSIGN:
								printf("= ");
								break;
							case DASSIGN:
								if(!strcmp(op, "+="))
									printf("+= ");
								else if(!strcmp(op, "-="))
									printf("-= ");
								else if(!strcmp(op, "*="))
									printf("*= ");
								else if(!strcmp(op, "/="))
									printf("/= ");
								else
									printf("!= ");
								break;
						}
						break;
						printPostFix(root->binarynode.right);

		case TernaryOp: printPostFix(root->ternarynode.first);
						printf("? ");
						printPostFix(root->ternarynode.second);
						printf(": ");
						printPostFix(root->ternarynode.third);
						// printf("? ");
						break;
		case INTLIT: printf("%d ", root->litval);
						break;
	}
};