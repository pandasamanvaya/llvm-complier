
typedef enum  astnodetype {BinaryOp, UnaryOp, TernaryOp, StringOp, 
							Array1D, Array2D, Function, INTLIT, 
							BOOLLIT, IDLIT, While, For, If, Input, 
							InputList, Output, OutputList, Vardec, 
							Varlist, Dtype, Statement, Param, ParamList,
							VarDecList} ASTNodeType;
typedef enum  binaryoptype {ASSIGN, SUMOP, RELOP, RELDOP, DASSIGN, MULOP, ANDOP, OROP, NOTOP} BinaryOpType; 

extern struct ASTNode *getASTNodeBinaryOp(struct ASTNode *left, 
									struct ASTNode *right,
									BinaryOpType optype,
									char *operator);

extern struct ASTNode *getASTNodeStringOp(struct ASTNode *operand, 
									char *string);

extern struct ASTNode *getASTNodeWhile(struct ASTNode *condition);
extern struct ASTNode *getASTNodeIf(struct ASTNode *condition,
									struct ASTNode *ifvar,
									struct ASTNode *ifstat,
									struct ASTNode *elsevar,
									struct ASTNode *elsestat);

extern struct ASTNode *getASTNodeUnaryOp(struct ASTNode *operand, 
									BinaryOpType optype,
									char *operator);

extern struct ASTNode *getASTNodeTernaryOp(struct ASTNode *first, 
									struct ASTNode *second,
									struct ASTNode *third);
extern struct ASTNode *getASTNodeInputStat(struct ASTNode *statlist);
extern struct ASTNode *getASTNodeInputList(struct ASTNode *left,
										struct ASTNode *right);

extern struct ASTNode *getASTNodeOutputStat(struct ASTNode *statlist);
extern struct ASTNode *getASTNodeOutputList(struct ASTNode *left,
										char *str,
										struct ASTNode *right);

extern struct ASTNode *getASTNodeVardec(struct ASTNode *left,
										struct ASTNode *right);
extern struct ASTNode *getASTNodeVarList(struct ASTNode *str,
										struct ASTNode *list);
extern struct ASTNode *getASTNodeDType(char *type);
extern struct ASTNode *getASTNodeStat(struct ASTNode *left,
										struct ASTNode *right);
extern struct ASTNode *getASTNodeParamList(struct ASTNode *left,
										struct ASTNode *right);
extern struct ASTNode *getASTNodeVarDecList(struct ASTNode *left,
										struct ASTNode *right);

extern struct ASTNode *getASTNodeParam(struct ASTNode *type,
										struct ASTNode *var);

extern struct ASTNode *getASTNodeFunction(struct ASTNode *type,
										char *name,
										struct ASTNode *paramlist,
										struct ASTNode *varlist,
										struct ASTNode *statlist);

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

extern void printAST(struct ASTNode *root);


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
			struct ASTNode *type;
			struct ASTNode *paramlist;
			struct ASTNode *statlist;
			struct ASTNode *varlist;
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
			struct ASTNode *ifvar;
			struct ASTNode *ifstat;
			struct ASTNode *elsevar;
			struct ASTNode *elsestat;
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

		struct ASTInputStat{
			struct ASTNode *list;
		} inputstat;

		struct ASTInputList{
			struct ASTNode *left;
			struct ASTNode *right;
		} inputlist;

		struct ASTOutputStat{
			struct ASTNode *list;
		} outputstat;

		struct ASTOutputList{
			struct ASTNode *left;
			char *str;
			struct ASTNode *right;
		} outputlist;

		struct ASTVardec{
			struct ASTNode *left;
			struct ASTNode *right;
		} vardec;

		struct ASTVardecList{
			struct ASTNode *left;
			struct ASTNode *right;
		} vardeclist;
		
		struct ASTStat{
			struct ASTNode *left;
			struct ASTNode *right;
		} statment;
		
		struct ASTVarlist{
			struct ASTNode *type;
			struct ASTNode *list;
		} varlist;
		
		struct ASTParam{
			struct ASTNode *type;
			struct ASTNode *var;
		} param;

		struct ASTParamlist{
			struct ASTNode *left;
			struct ASTNode *right;
		} paramlist;

		int litval;
		union{
			char *boollit;
			char *idlit;
			char *dtype;
		};
	};

};

