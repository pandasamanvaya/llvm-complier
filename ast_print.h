#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

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
				printf("}");
				if(root->ifnode.elsestat != NULL){
					printf("else{\n");
					if(root->ifnode.elsevar != NULL) 
						printAST(root->ifnode.elsevar);
					printAST(root->ifnode.elsestat);
					printf("}");
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
						printf("\n");
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
						printf("\n");
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
		case Return: printf("return ");
					if(root->returnstat.expr != NULL)
						printAST(root->returnstat.expr);
					break;
	}	
}