#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#define plus4(x) x += 4
#define minus4(x) x -= 4
static int location = 0;
static int global_loc = 0;
static int func_loc = 0;
static int scope = 0;
static ScopeList global_sym;

//int scope_flag = FALSE;

//static char *fun_name;
static void traverse( TreeNode * t ,void(* preProc) (TreeNode *),void (* postProc) (TreeNode *)){
    if (t != NULL){ 
		int _scope = scope;
        preProc(t);
        int i; 
        for (i=0; i < MAXCHILDREN; i++)
            traverse(t->child[i],preProc,postProc);
        if((t->nodekind == StmtK) && (t->kind.stmt == CompndK)){
			//scope--;
			total_sym->valid = FALSE;
		}
		scope = _scope;
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
					if(st_lookup(t->attr.decl.name)==-1){
						//insert fuction
						st_insert(t->attr.decl.name,t->lineno,func_loc++,Func,FALSE,-1,TRUE);
						location = 0;
						scope++;
						insert_scope();
					}
					else{
						//duplicate
					}
		    		break;
                case VarK:
		    		if(st_lookup(t->attr.decl.name)==-1){
						if(scope!=0) {
							if(t->type == Integer){
								minus4(location);
								st_insert(t->attr.decl.name,t->lineno,location,Var,FALSE,-1,FALSE);
							}
							else typeError(t->lineno,"variable should be integer");
						}
						else{
							if(t->type == Integer){
								plus4(global_location);
								st_insert(t->attr.decl.name,t->lineno,global_location,Var,FALSE,-1,TRUE);
							}
							else typeError(t->lineno,"variable should be integer");
						}
		    		}
					else{
						//duplicate
					}
                    break;
                case VarArrK:
					if(st_lookup(t->attr.decl.name)==-1){
						if(t->type == Array){
							if(scope==0){
								global_location += 4*(t->attr.decl.arr_size);
								st_insert(t->attr.decl.name,t->lineno,global_location,Var,TRUE,t->attr.decl.arr_size,TRUE);
							}
							else{
								location -= 4*(t->attr.decl.arr_size);
								st_insert(t->attr.decl.name,t->lineno,location,Var,TRUE,t->attr.decl.arr_size,FALSE);
							}
						}
						else typeError(t->lineno,"array error - should be modify");
					}
					else{
						//duplicate
					}
					break;
                case ParaK:
					//st_lookup();
					if(/*no node*/){
						if(t->type == Array){
							location += 4*(t->attr.decl.arr_size);
							st_insert(t->attr.decl.name,t->lineno,global_location,Var,TRUE,t->attr.decl.arr_size,FALSE);	
						}
						if(t->sibling == NULL) {
							location = -4;
						}
					}
					break;
                default:
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:
					scope++;
					insert_scope();
					break;//FompndK pass
                case CallK:
					st_insert(t->attr.decl.name,t->lineno,location,Func,FALSE,-1,TRUE);
					break;
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp){
                case IdK:
                    if (st_lookup(t->attr.name) == -1)
                    	return ;//error
					//else
                        //if(t->child[0]!=NULL) st_insert(t->attr.name, t->lineno, location,Var,TRUE,t->attr.decl.arr_size,FALSE);
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
    insert_scope();
	global_sym = total_sym;
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
                    break;
                case VarK:
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
