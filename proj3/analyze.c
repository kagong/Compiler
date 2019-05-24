#include "globals.h"
#include "symtab.h"
#include "analyze.h"

static int location = 0;
static void traverse( TreeNode * t ,void(* preProc) (TreeNode *),void (* postProc) (TreeNode *)){
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
        case DeclK:
            switch (t->kind.decl){
                case FunK:
                    if(strcmp(t->attr.decl.name, "main")){
                        //11,12,13
                        if(t->type != Void)
                            typeError(t->lineno,"main function should return void");
                        if(t->child[0]->type != Void)
                            typeError(t->lineno,"main function should not have any parameters");
                        if(t->sibling)
                            typeError(t->lineno,"main function should be located at last");
                    }
                    break;
                case VarK:
                    //3
                    if(t->type == Void)
                        typeError(t->lineno,"variable type should not be void");
                    break;
                case VarArrK:
                case ParaK:
                default:
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:
                case SelcK:
                    /*
                       if (st_lookup(t->attr.name) == -1)
                       st_insert(t->attr.name, t->lineno, location++) ;
                       else
                       st_insert(t->attr.name, t->lineno, 0);
                       */
                    break;
                case IterK:
                case RetK:
                case CallK:
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp){
                case IdK:
                    if (st_lookup(t->attr.name) == -1)
                        st_insert(t->attr.name, t->lineno,location++);
                    else
                        st_insert(t->attr.name, t->lineno, O);
                    break;
                case ConstK:
                case OpK:

                default:
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



static void typeError(int lineno , char * message){
    fprintf (listing, "Error in line %d: %s\n" , lineno, message);
    Error = TRUE;
}
static void checkNode( TreeNode * t){
    switch (t->nodekind){ 
        case DeclK:
            switch (t->kind.decl){
                case FunK:
                    if(strcmp(t->attr.decl.name, "main")){
                        //11,12,13
                        if(t->type != Void)
                            typeError(t->lineno,"main function should return void");
                        if(t->child[0]->type != Void)
                            typeError(t->lineno,"main function should not have any parameters");
                        if(t->sibling)
                            typeError(t->lineno,"main function should be located at last");
                    }
                    break;
                case VarK:
                    //3
                    if(t->type == Void)
                        typeError(t->lineno,"variable type should not be void");
                    break;
                case VarArrK:
                case ParaK:
                default:
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:
                case SelcK:
                    /*
                       if (st_lookup(t->attr.name) == -1)
                       st_insert(t->attr.name, t->lineno, location++) ;
                       else
                       st_insert(t->attr.name, t->lineno, 0);
                       */
                    break;
                case IterK:
                case RetK:
                case CallK:
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp){
                case IdK:
                    if (st_lookup(t->attr.name) == -1)
                        st_insert(t->attr.name, t->lineno,location++);
                    else
                        st_insert(t->attr.name, t->lineno, O);
                    break;
                case ConstK:
                case OpK:

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
