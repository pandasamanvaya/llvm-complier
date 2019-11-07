
typedef enum  astnodetype {BinaryOp, UnaryOp, TernaryOp, INTLIT} ASTNodeType;
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

extern struct ASTNode *getASTNodeUnaryOp(struct ASTNode *operand, 
									BinaryOpType optype,
									char *operator);

extern struct ASTNode *getASTNodeTernaryOp(struct ASTNode *first, 
									struct ASTNode *second,
									struct ASTNode *third);

extern struct ASTNode *getASTNodeIntLiteral(int litval);
extern struct ASTNode *getASTNodeBoolLiteral(char *litval);

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

		struct ASTExprTernaryOp {
			struct ASTNode *first;
			struct ASTNode *second;
			struct ASTNode *third; 
		} ternarynode;	

		int litval;
		char *boollit;
	};

};

