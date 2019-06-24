#include "globals.h"
#include "symtab.h"
#include "code.h"
#include "cgen.h"

static int tmpOffset = 0;

static void cGen (TreeNode * tree);

static void genDec(TreeNode * tree){
	TreeNode *p1, *p2, *p3;
	int savedLoc1, savedLoc2, currentLoc;
	int loc;
	switch(tree->kind.decl){
		case FunK:
			
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
    int savedLoc1, savedLoc2 ,currentLoc;
    int loc;
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
		/* tiny */
		case IfK:
            if (TraceCode) emitComment("->if");
            p1 = tree->child[0];
            p2 = tree->child[1];
            p3 = tree->child[2];
            /* generate code for test expression */
            cGen(p1);
            savedLoc1 = emitSkip(1);
            emitComment (" if: jump to else belongs here");
            /*recurse on then part */
            cGen(p2);
            savedLoc2 = emitSkip(1);
            emitComment( "if: jump to end belongs here");
            currentLoc = emitSkip(0);
            emitBackup(savedLoc1);
            emitRM_Abs("JEQ" ,ac, currentLoc, "if: jmp to else");
            emitRestore();
            /* recurse on else part */
            cGen(p3);
            currentLoc = emitSkip(0);
            emitBackup(savedLoc2);
            emitRM_Abs( "LDA" , pc, currentLoc, "jmp to end");
            emitRestore();
            if (TraceCode) emitComment( "<- if")
                break; /* if_k */

        case RepeatK:
            if (TraceCode) emitComment("-> repeat");
            p1 = tree->child[0];
            p2 = tree->child[1];
            savedLoc1 = emitSkip(0);
            emitComment( "repeat: jump after body comes back here");
            /* generate code for body */
            cGen(p1);
            /* generate code for test */
            cGen(p2);
            emitRM_Abs("JEQ",ac,savedLoc1, "repeat: jmp back to body");
            if (TraceCode) emitComment("<- repeat");
            break; /* repeat */
        case AssignK:
            if (TraceCode) emitComment ( "-> assign");
            /* generate code for rhs */
            cGen (tree->child[0]);
            /* now store value */
            loc = st_lookup(tree->attr.name);
            emitRM("ST",ac,loc,gp,"assign: store value");
            if (TraceCode) emitComment( "<- assign");
            break; /* assign_k */
 
        case ReadK:
            emitRO( "IN" ,ac, 0, 0, "read integer value");
            loc = st_lookup(tree->attr.name);
            emitRM("ST" ,ac ,loc ,gp ,"read: store value");
            break;
        case WriteK:
            /* generate code for expression to write */
            cGen(tree->child[0]);
            /* now output it */
            emitRO("OUT" ,ac ,0,0,"write ac");
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
            if (TraceCode) emitComment("-> Const");
            /* gen code to load integer constant using LDC */
            emitRM("LDC" ,ac,tree->attr.val,0, "load const");
            if (TraceCode) emitComment("< .， Const");
            break; /* ConstK */

        case IdK:
            if (TraceCode) emitComment("-> Id");
            loc = st_1ookup(tree->attr.name);
            emitRM ( "LD",ac , 1oc, gp, "load id va1ue" );
            if (TraceCode) emitComment("<- Id");
            break; /* IdK */

        case OpK:
            if (TraceCode) emitComment ("-> Op");
            p1 = tree->chi1d[0];
            p2 = tree->chi1d[1];
            /* gen code for ac = 1eft arg */
            cGen(p1);
            /* gen code to push 1eft operand */
            emitRM( "ST" ,ac, tmpOffset-- ,mp, "op: push 1eft");
            /* gen code for ac = right operand */
            cGen(p2);
            /* now 10ad 1eft operand */
            emitRM("LD" ,ac1, ++tmpOffset,mp, "op: load 1eft");
            switch (tree->attr.op) {
                case PLUS:
                    emitRO( "ADD", ac, ac1, ac, "op +");
                    break;
                case MINUS:
                    emitRO( "SUB" ,ac,ac1,ac, "op -");
                    break;
                case TIMES:
                    emitRO( "MUL" ,ac, ac1, ac, "op *");
                    break;
                case OVER:
                    ernitRO("DIV" ,ac ,ac1 ,ac ,"op /");
                    break;
                case LT:
                    ernitRO( "SUB" ,ac, ac1,ac, "op <");
                    ernitRM( "JLT" ,ac ,2,pc, "br if true");
                    ernitRM( "LDC" , ac, 0 ,ac, "fa1se case");
                    ernitRM( "LDA" ,pc, 1,pc, "unconditiona1 jmp");
                    ernitRM( "LDC" ,ac, 1,ac ,"case");
                    break;
                case EQ:
                    ernitRO( "SUB" ,ac, ac1,ac, "==");
                    ernitRM( "JEQ" , ac, 2, pc, "if true");
                    ernitRM("LDC" ,ac, 0,ac, "fa1se case");
                    ernitRM( "LDA" ,pc, 1,pc, "unconditiona1 jmp");
                    emitRM( "LDC" ,ac, 1,ac, "true case");
                    break;
                default:
                    emitComment("BUG: Unknown operator");
                    break;
            } /* case op */
            if (TraceCode) emitComment ("<- Op")
                break; /* OpK */

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
    emitComment("TINY Compilation to TM Code");
    emitComment(s);
    /* generate standard prelude */
    emitComment ("Standard prelude:");
    emitRM("LD" ,gp,0,ac, "load maxaddress from location 0");
    emitRM("LDA" ,fp,0,gp,)
	emitRM("ST",ac ,0,ac,"clear location 0");
    emitcomment ("End of standard prelude.");
    cGen(syntaxTree);
    emitComment ("End of execution.");
    emitRO("HALT" ,0, 0, 0,"");
}

