
typedef enum  astnodetype {BinaryOp, UnaryOp, TernaryOp, StringOp, 
							Array1D, Array2D, Function, INTLIT, 
							BOOLLIT, IDLIT, While, For, If} ASTNodeType;
typedef enum  binaryoptype {ASSIGN, SUMOP, RELOP, RELDOP, DASSIGN, MULOP, ANDOP, OROP, NOTOP} BinaryOpType; 

// static const *sumop[] = {"+", "-"};
// static const *mulop[] = {"*", "/"};
// static const *relop[] = {">", "<"};
// static const *reldop[] = {">=", "<=", "=="};
// static const *assign[] = {"="};
// static const *dassign[] = {"+=", "-=", "*=", "/=", "!="};
// static const *andop[] = {"and"};
// static const *orop[] = {"or"};

extern struct ASTNode *getASTNodeBinaryOp(struct ASTNode *left, 
									struct ASTNode *right,
									BinaryOpType optype,
									char *operator);

extern struct ASTNode *getASTNodeStringOp(struct ASTNode *operand, 
									char *string);

extern struct ASTNode *getASTNodeWhile(struct ASTNode *condition);
extern struct ASTNode *getASTNodeIf(struct ASTNode *condition);

extern struct ASTNode *getASTNodeUnaryOp(struct ASTNode *operand, 
									BinaryOpType optype,
									char *operator);

extern struct ASTNode *getASTNodeTernaryOp(struct ASTNode *first, 
									struct ASTNode *second,
									struct ASTNode *third);

extern struct ASTNode *getASTNodeFunction(char *name);
extern struct ASTNode *getASTNodeIntLiteral(int litval);
extern struct ASTNode *getASTNodeBoolLiteral(char *litval);
extern struct ASTNode *getASTNodeIDLiteral(char *litval);
extern struct ASTNode *getASTNode1DArray(char *name,
									struct ASTNode *value);
extern struct ASTNode *getASTNode2DArray(char *name,
									struct ASTNode *value1, 
									struct ASTNode *value2);

extern struct ASTNode *getASTNodeFor(struct ASTNode *init,
									struct ASTNode *condition, 
									struct ASTNode *update);

extern void printPostFix(struct ASTNode *root);


struct ASTNode {
	ASTNodeType nodetype;

	union {
	
		struct ASTExprBinOp {
			BinaryOpType optype; 
			struct ASTNode *left;
			struct ASTNode *right;
			char *operator; 
		} binarynode;	

		struct ASTExprUnOp {
			BinaryOpType optype; 
			struct ASTNode *operand;
			char *operator; 
		} unarynode;	

		struct ASTExprStrOp {
			struct ASTNode *operand;
			char *string; 
		} stringnode;	

		struct ASTFunction {
			char *name; 
			char *returntype;
		} functionnode;	

		struct ASTWhile {
			struct ASTNode *condition;
		} whilenode;

		struct ASTFor {
			struct ASTNode *init;
			struct ASTNode *condition;
			struct ASTNode *update;
		} fornode;
		
		struct ASTIf{
			struct ASTNode *condition;
		}ifnode;

		struct ASTExpr1DArray {
			char *name; 
			struct ASTNode *value;
		} array1dnode;	

		struct ASTExpr2DArray {
			char *name; 
			struct ASTNode *value1;
			struct ASTNode *value2;
		} array2dnode;	

		struct ASTExprTernaryOp {
			struct ASTNode *first;
			struct ASTNode *second;
			struct ASTNode *third; 
		} ternarynode;	

		int litval;
		char *boollit;
		char *idlit;
	};

};

