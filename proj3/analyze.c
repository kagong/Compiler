#include "globals.h"
#include "symtab.h"
#include "analyze.h"

static int location = 0;
static void traverse( TreeNode * t ,void(* prePorc) (TreeNode *),void (* postProc) (TreeNode *)){
    if (t != NULL){ 
        preProc(t);
        int i; 
        for (i=0; i < MAXCHILDREN; i++)
            traverse(t->child[i],preProc,postProc);
        postProc(t);
        traverse(t->sibling,preProc,postProc);
    }
}
static void nullProc(TreeNode * t){
    if (t==NULL) return;
    else return;
}
static void insertNode( TreeNode * t){
    switch (t->nodekind){ 
        case StmtK:
            switch (t->kind.s다nt){ 
                case AssignK:
                case ReadK:
                    if (st_lookup(t->attr.n없nè) == -1)
                        st_insert(t->áttr.n려ne ， t->lineno, location++) ;
                    else
                        st_insert(t->attr.name, t->lineno, O);
                    break;
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp)
            { case IdK:
                if (st_lookup(t->attr.name) == -1)
                    st_insert(t->attr.name, t->lineno,location++);
                else
                    st_insert(t->attr.name, t->lineno, O);
                break;
                default;
                break;
            }
            break;
        default:
            break;
    }
}



void buildSymtab(TreeNode * syntaxTree){
    traverse(syntaxTree,insertNode,nullProc);
    if (TraceAnalyze){ 
        fprintf(listing, "\nSymbol table:\n\n");
        printSymTab(listing);
    }
}



static void typeError(TreeNode * t , char * message){
    fprintf (listing, "말pe error at line ~od: %s\n" , t->lineno,message);
    Error = TRUE;
}
static void checkNode(TreeNode * t){ 
    switch (t->nodekind){ 
        case ExpK:
            switch (t->ki~d.exp){ 
                case OpK:
                    if ((t->chi1d[O]->type != Integer) ||(t->chi1d[l] ->type !.= Integer))
                        typeError(t,"Op applied to non-integer");
                    if ((t->attr.op == EQ) 11 (t->attr.op == LT))
                        t->type = Boolean;
                    else
                        t->type = Integer;
                    break;
                case ConstK:
                case IdK:
                    t->type = Integer;
                    break;
                default:
                    break;
            }
            break;
        case StmtK:
            switch (t->kind.s다nt){ 
                case IfK:
                    if (t->child[O]->type == Integer)
                        typeError(t->chi1d[O] , "if test is not Boole없~" ) ;
                    break;
                case AssignK:
                    if (t->child[O]->type != Integer)
                        typeError (t->chi1d [0] ,"assignment of non-integer valùiE!:~'");
                    break;
                case WriteK:
                    if (t->child[O]->type != Integer)
                        typeError (t->chi1d [0] , "write of non-integer value");
                    break;
                case RepeatK:
                    if (t->child[l]->type == Integer)
                        typeError(t->chi1d[l] , "repeat test not Boolean");
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void typeCheck(TreeNode * syntaxTree){
    traverse(syntaxTree,nullProc,checkNode);
}
