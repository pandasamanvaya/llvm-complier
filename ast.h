#include <string>
using namespace std;

extern void printIR(struct ASTNode *node);
// extern void interpreter(struct ASTNode *node);
typedef enum  astnodetype {BinaryOp, UnaryOp, TernaryOp, StringOp, 
							Array1D, Array2D, Func, FuncList, INTLIT, 
							BOOLLIT, IDLIT, FLT_LIT, While, For, If,  
							InputList, Output, OutputList, Vardec, Input,
							Varlist, Dtype, Statement, Param, ParamList,
							VarDecList, DecList, FunCall, ArgList, Return} ASTNodeType;
typedef enum  binaryoptype {ASSIGN, SUMOP, RELOP, RELDOP, DASSIGN, MULOP, ANDOP, OROP, NOTOP} BinaryOpType; 

extern  struct ASTNode *getASTNodeBinaryOp(struct ASTNode *left, 
									struct ASTNode *right,
									BinaryOpType optype,
									string *op);

extern  struct ASTNode *getASTNodeStringOp(struct ASTNode *operand, 
									string *str);

extern  struct ASTNode *getASTNodeDecList(struct ASTNode *global,
										struct ASTNode *funclist);

extern  struct ASTNode *getASTNodeWhile(struct ASTNode *condition,
										struct ASTNode *statlist);
extern  struct ASTNode *getASTNodeFor(struct ASTNode *init,
									struct ASTNode *condition, 
									struct ASTNode *update,
									struct ASTNode *statlist);
extern  struct ASTNode *getASTNodeReturn(struct ASTNode *expr);

extern  struct ASTNode *getASTNodeFunCall(string *name,
										struct ASTNode *varlist);
extern  struct ASTNode *getASTNodeArg(struct ASTNode *left,
									struct ASTNode *right);

extern  struct ASTNode *getASTNodeIf(struct ASTNode *condition,
									struct ASTNode *ifstat,
									struct ASTNode *elsestat);

extern  struct ASTNode *getASTNodeUnaryOp(struct ASTNode *operand, 
									BinaryOpType optype,
									string *op);

extern  struct ASTNode *getASTNodeTernaryOp(struct ASTNode *first, 
									struct ASTNode *second,
									struct ASTNode *third);
extern  struct ASTNode *getASTNodeInputStat(struct ASTNode *statlist);
extern  struct ASTNode *getASTNodeInputList(struct ASTNode *left,
										struct ASTNode *right);

extern  struct ASTNode *getASTNodeOutputStat(struct ASTNode *statlist);
extern  struct ASTNode *getASTNodeOutputList(struct ASTNode *left,
										string *str,
										struct ASTNode *right);

extern  struct ASTNode *getASTNodeVardec(struct ASTNode *left,
										struct ASTNode *right);
extern  struct ASTNode *getASTNodeVarList(struct ASTNode *str,
										struct ASTNode *list);
extern  struct ASTNode *getASTNodeDType(string *type);
extern  struct ASTNode *getASTNodeStat(struct ASTNode *left,
										struct ASTNode *right);
extern  struct ASTNode *getASTNodeParamList(struct ASTNode *left,
										struct ASTNode *right);
extern  struct ASTNode *getASTNodeVarDecList(struct ASTNode *left,
										struct ASTNode *right);

extern  struct ASTNode *getASTNodeParam(struct ASTNode *type,
										struct ASTNode *var);

extern	struct ASTNode *getASTNodeFuncList(struct ASTNode *left,
										struct ASTNode *right);

extern  struct ASTNode *getASTNodeFunction(struct ASTNode *type,
										string *name,
										struct ASTNode *paramlist,
										struct ASTNode *varlist,
										struct ASTNode *statlist);

extern  struct ASTNode *getASTNodeIntLiteral(int litval);
extern  struct ASTNode *getASTNodeFloatLiteral(float litval);
extern  struct ASTNode *getASTNodeBoolLiteral(string *litval);
extern  struct ASTNode *getASTNodeIDLiteral(string *litval);
extern  struct ASTNode *getASTNode1DArray(string *name,
									struct ASTNode *value);
extern  struct ASTNode *getASTNode2DArray(string * name,
									struct ASTNode *value1, 
									struct ASTNode *value2);

struct ASTNode {
	ASTNodeType nodetype;

	union {
	
		struct {
			BinaryOpType optype; 
			struct ASTNode *left;
			struct ASTNode *right;
			string op; 
		} binarynode;	

		struct {
			BinaryOpType optype; 
			struct ASTNode *operand;
			string op; 
		} unarynode;	

		struct {
			struct ASTNode *operand;
			string str; 
		} stringnode;	

		struct {
			string name; 
			struct ASTNode *type;
			struct ASTNode *paramlist;
			struct ASTNode *statlist;
			struct ASTNode *varlist;
		} functionnode;	

		struct{
			struct ASTNode *global;
			struct ASTNode *funclist;
		} declist;

		struct{
			struct ASTNode *left;
			struct ASTNode *right;
		} functionlist;

		struct {
			struct ASTNode *condition;
			struct ASTNode *statlist;
		} whilenode;

		struct {
			struct ASTNode *init;
			struct ASTNode *condition;
			struct ASTNode *update;
			struct ASTNode *statlist;
		} fornode;
		
		struct {
			struct ASTNode *condition;
			struct ASTNode *ifstat;
			struct ASTNode *elsestat;
		}ifnode;

		struct {
			string name; 
			struct ASTNode *value;
		} array1dnode;	

		struct {
			string name; 
			struct ASTNode *value1;
			struct ASTNode *value2;
		} array2dnode;	

		struct {
			struct ASTNode *first;
			struct ASTNode *second;
			struct ASTNode *third; 
		} ternarynode;	

		struct {
			struct ASTNode *expr;
		} returnstat;

		struct {
			struct ASTNode *list;
		} inputstat;

		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} inputlist;

		struct {
			struct ASTNode *list;
		} outputstat;

		struct {
			struct ASTNode *left;
			string str;
			struct ASTNode *right;
		} outputlist;

		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} vardec;

		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} vardeclist;
		
		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} statement;
		
		struct {
			struct ASTNode *type;
			struct ASTNode *list;
		} varlist;
		
		struct {
			struct ASTNode *type;
			struct ASTNode *var;
		} param;

		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} paramlist;

		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} arg;

		struct {
			string name;
			struct ASTNode *arglist;
		} funcall;

		union{
			int litval;
			float flt_litval;
		};
		union{
			string boollit;
			string idlit;
			string dtype;
		};
	};

};

