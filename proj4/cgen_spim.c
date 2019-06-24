#include "globals.h"
#include "cgen.h"

static int 

static void genDec(TreeNode * tree){
	TreeNode *p1, *p2, *p3;
	int savedLoc1, savedLoc2, currentLoc;
	int loc;
	switch(tree->kind.decl){
		case FunK:
			fprintf(code,"%s :\n",tree->attr.decl.name);
		case VarK:

			break;
		case VarArrK:
			break;
		case ParaK:
			break;
	}
}
static void genStmt(TreeNode * tree){
    TreeNode *p1, *p2, *p3;
    switch(tree->kind.stmt){
        case FompndK:
			break;
		case CompndK:
			break;
		case SelcK:
			break;
		case IterK:
			break;
		case RetK:
			break;
		case CallK:
			break;
        default:
            break;
    }
} /* genStmt */

/* procedure genExp generates codeat an expression node */
static void genExp( TreeNode * tree){
    int loc;
    TreeNode *p1 = tree->child[0], *p2 = tree->child[1];
    switch (tree->kind.exp){
        case ConstK:
			fprintf(code,"\tli $t0, %d\n",tree->attr.val);
			break;
        case IdK:
			if(tree->child[0]){
				//array
			}
			break;
        case OpK:
			switch(tree->attr.op){
				case PLUS :
				case MINUS :
				case TIMES :
				case OVER :
				case LT :
				case LET :
				case GT :
				case GET :
				case EQ :
				case NEQ :
				case ASSIGN :
			}
			break;
        default:
            break;
    }
} /* genExp */

/* procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen( TreeNode * tree){
    if (tree != NULL){ 
        switch (tree->nodekind){
            case DeclK:
				genDec(tree);
				break;
			case StmtK:
                genStmt(tree);
                break;
            case ExpK:
                genExp(tree);
                break;
            default:
                break;
        }
        cGen(tree->sibling);
    }
}

/***********************************************/
/* the primary function of the code generator */
/***********************************************/
/* procedure codeGen generates code to a code
 * file by traversal of .the syntax tree. The
 * second parameter (codéfile) is the file name
 * of the code file, and is used to print the
 * file name as a comment in the code file
 */
void codeGen(TreeNode * syntaxTree, char * codefile){
    char* s = malloc(strlen(codefile)+7);
    strcpy(s, "File: ");
    strcat(s,codefile);
    //fprintf(code, ".data\n");
	fprintf(code, "\n.text\n");
	fprintf(code, ".align 2\n");
	fprintf(code, ".globl main\n");
	//initialize
	fprintf(code, "$sp, 0x7fffffff");
	
	cGen(syntaxTree);
}

