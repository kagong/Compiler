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
    TreeNode *p1 = tree -> child[0] , *p2 = tree -> child[1] , *p3 = tree ->child [2];
    switch(tree->kind.stmt){
        case FompndK:
			break;
		case CompndK:
			break;
		case SelcK:
            int label_num1, label_num2;
            cGen(p1);
            label_num1 = allocate_label();
            fprintf(code,"\tbeqz $t0, L%d\n",label_num1);
            cGen(p2);
            if(p3 != NULL){
                label_num2 = allocate_label();
                fprintf(code,"\tb L%d\n",label_num2);
                fprintf(code,"L%d:\n",label_num1);
                cGen(p3);
                fprintf(code,"L%d:\n",label_num2);
            }
            else
                fprintf(code,"L%d:\n",label_num1);
            
			break;
		case IterK:
            int label_num1, label_num2;
            label_num1 = allocate_label();
            label_num2 = allocate_label();
            fprintf(code,"L%d:\n",label_num1);
            cGen(p1);
            fprintf(code,"\tbeqz $t0, L%d\n",label_num2);
            cGen(p2);
            fprintf(code,"\tb L%d\n",label_num1);
            fprintf(code,"L%d:\n",label_num2);
			break;
		case RetK:
            cGen(p1);
            fprintf(code,"\taddi $a0, $t0, 0\n",label_num1);//jal 함순 선언에서
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

