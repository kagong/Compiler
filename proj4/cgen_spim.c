#include "globals.h"
#include "cgen.h"



static void genDec(TreeNode * tree){
	TreeNode *p1, *p2, *p3;
	int savedLoc1, savedLoc2, currentLoc;
	int loc;
	switch(tree->kind.decl){
		case FunK:
			fprintf(code,"%s :\n",tree->attr.decl.name);
			break;
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
    TreeNode * p1, * p2;
    switch (tree->kind.exp){
        case ConstK:

        case IdK:

        case OpK:

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
	fprintf(code, ".globl main\n");
	
	cGen(syntaxTree);
}

