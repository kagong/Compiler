#include "analyze.h"
#include "symtab.h"
#include "globals.h"
#define WORD 4
static int location = 0;
static int global_location = 0;
static int func_loc = 0;
static int scope = 0;
//int scope_flag = FALSE;
extern ScopeList total_sym;

static void scopeError(int lineno , char * message){
    fprintf (listing, "Scope Error in line %d: %s\n" , lineno, message);
    Error = TRUE;
}

static void typeError(int lineno , char * message){
    fprintf (listing, "Type Error in line %d: %s\n" , lineno, message);
    Error = TRUE;
}
//static char *fun_name;
static void traverse( TreeNode * t ,void(* preProc) (TreeNode *),void (* postProc) (TreeNode *)){
    if (t != NULL && Error == FALSE){
		int _scope = scope;
		preProc(t);
        int i; 
        for (i=0; i < MAXCHILDREN; i++)
            traverse(t->child[i],preProc,postProc);
        if(((t->nodekind == StmtK) &&( (t->kind.stmt == CompndK)||(t->kind.stmt == FompndK)))){
			total_sym->valid = FALSE;
			ScopeList _sym = total_sym;
			while(scope!=_sym->level) _sym = _sym->next;
			_sym->valid = FALSE;
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
    TreeNode *temp;
    if(Error == TRUE)
        return ;
	switch (t->nodekind){ 
        case DeclK:
            //printf("%s\n",t->attr.decl.name);
			switch (t->kind.decl){
                case FunK:
					if(st_lookup(t->attr.decl.name,TRUE)==-1){
						//insert fuction
						st_insert(t->attr.decl.name,t->lineno,func_loc++,Func,FALSE,-1,t->type,TRUE,TRUE,t);
						location = 0;
						scope++;
						if(t->child[0]==NULL) location = -4;
						insert_scope(scope);
					}
					else{
						//duplicate
					}
		    		break;
                case VarK:
		    		if(st_lookup(t->attr.decl.name,TRUE)==-1){
						if(scope!=0) {
							if(t->type == Integer){
								location -= WORD;
								st_insert(t->attr.decl.name,t->lineno,location,Var,FALSE,-1,Integer,FALSE,TRUE,t);
							}
							else typeError(t->lineno,"variable should be integer");
						}
						else{
							if(t->type == Integer){
								global_location += WORD;
								st_insert(t->attr.decl.name,t->lineno,global_location,Var,FALSE,-1,Integer,TRUE,TRUE,t);
							}
							else typeError(t->lineno,"variable should be integer");
						}
		    		}
					else{
						//duplicate
					}
                    break;
                case VarArrK:
					if(st_lookup(t->attr.decl.name,TRUE)==-1){
							if(scope==0){
								global_location += 4*(t->attr.decl.arr_size);
								st_insert(t->attr.decl.name,t->lineno,global_location,Var,TRUE,t->attr.decl.arr_size,t->type,TRUE,TRUE,t);
							}
							else{
								location -= 4*(t->attr.decl.arr_size);
								st_insert(t->attr.decl.name,t->lineno,location,Var,TRUE,t->attr.decl.arr_size,t->type,FALSE,TRUE,t);
							}
					}
					else{
						//duplicate
					}
					break;
                case ParaK:
					if(st_lookup(t->attr.decl.name,FALSE)==-1){
						int k=1;
						TreeNode * ttmp = t;
						while(ttmp->sibling != NULL){
							k++;
							ttmp = ttmp->sibling;
						}
						location = k*WORD;
						if(t->type == Array){
							st_insert(t->attr.decl.name,t->lineno,location,Par,TRUE,t->attr.decl.arr_size,t->type,FALSE,FALSE,t);	
						}
						else if(t->type == Integer){
							st_insert(t->attr.decl.name,t->lineno,location,Par,FALSE,t->attr.decl.arr_size,t->type,FALSE,FALSE,t);	
						}
						if(t->sibling == NULL) {
							location = -4;
						}
					}
					break;
                default:
					break;
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:
					scope++;
					insert_scope(scope);
					break;//FompndK pass
                case CallK:
					if(st_lookup(t->attr.decl.name,FALSE)!=-1) 
                        st_insert(t->attr.decl.name,t->lineno,location,Func,FALSE,-1,t->type,TRUE,FALSE,t);
					else {/*error*/}
					break;
                default:
                    break;
            }
            break;
        case ExpK:
            //printf("%s\n",t->attr.decl.name);
			switch (t->kind.exp){
                case IdK:
                    if (st_lookup(t->attr.decl.name,FALSE) == -1)
                        scopeError(t->lineno , "Unknown ID"); 
					else{
                        temp == st_getnode(t->attr.decl.name);
                        if(temp == NULL)
                            scopeError(t->lineno , "Unknown error"); 
                        // name을통해 
                        if(t->type == Array_Nocheck){
                            if(temp -> kind.decl != VarArrK)
                                typeError(t->lineno , "this is not array"); 
                        }
                        if(temp -> kind.decl == FunK)
                            typeError(t->lineno , "this is function not a var error!"); 
    					st_insert(t->attr.decl.name, t->lineno, location,Var,TRUE,t->attr.decl.arr_size,t->type,FALSE,FALSE,t);
                        
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}



void buildSymtab(TreeNode * syntaxTree){
    total_sym = NULL;
	insert_scope(scope);
	global_sym = total_sym;
	traverse(syntaxTree,insertNode,nullProc);
    if ( Error == FALSE && TraceAnalyze){ 
        fprintf(listing, "\nSymbol table:\n\n");
        printSymTab(listing);
    }
}
static void checkNode( TreeNode * t){//postorder traverse
    TreeNode * temp = NULL;
    short flag;
    if(Error == TRUE)
        return ;
    switch (t->nodekind){ 
        case DeclK:
            switch (t->kind.decl){
                case FunK://10
                    temp = NULL;
                    flag = 0;
                    temp = t->child[1]->child[1];//stmts
                    //ret value must be Integer 
                    while(temp != NULL){
                        if(temp -> nodekind == StmtK && temp -> kind.stmt == RetK){
                            flag = 1;
                            if(t -> type == Void){
                                typeError(t->lineno , "Return type error!");
                                typeError(temp->lineno , "\t this postion is return type error!");
                            }

                        }
                        temp = temp -> sibling;
                    }
                    if (t ->type == Integer && flag == 0)
                        typeError(t->lineno , "Return type error!");
                    break;
                case VarK:
                    if(t->type != Integer)
                        typeError(t->lineno , "Declare type error!");
                    break;
                case VarArrK:
                    if(t->type != Integer)
                        typeError(t->lineno , "Array Declare type error!");
                    t->type = Array;

                    break;
                case ParaK:
                    if(t->type == Err || t ->type == Void )
                        typeError(t->lineno , "Parameter type error!");
                    break;
                default:
                    break;
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:

                    break;
                case SelcK:
                    if(t->child[0]->type != Integer)
                                typeError(t->lineno , "expression type error!");
                    break;
                case IterK:
                    if(t->child[0]->type != Integer)
                                typeError(t->lineno , "expression type error!");
                    break;
                case RetK://10
                    if(t->child[0] == NULL ||(t->child[0]!=NULL && t->child[0]->type != Integer))
                                typeError(t->lineno , "Return type error!");
                    t->type = Integer;
                    break;
                case CallK:
                    break;
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp){
                case IdK:
                    if(t->type == Array_Nocheck && t->child[0]->type != Integer)
                            typeError(t->lineno , "ID type error!");
                    t -> type = Integer;
                    break;
                case ConstK:
                    break;
                case OpK:
                    if(!(t->child[0]->type == Integer && t -> child[1]->type == Integer))
                                typeError(t->lineno , "Expression type error!");
                    t->type = Integer;
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
