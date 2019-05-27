char *fun_name = "global";
unsigned order,scope = 0;
#define STORE do{\
    _order = order;\
    _scope = scope;\
    _name = fun_name;\
}while(0)

#define LOAD do{\
    order = _order;\
    scope = _scope;\
    fun_name = _name;\
}while(0)
static int location = 0;
static void traverse( TreeNode * t ,void(* preProc) (TreeNode *),void (* postProc) (TreeNode *)){
    if (t != NULL){ 
    STORE;
        preProc(t);
        int i; 
        for (i=0; i < MAXCHILDREN; i++)
            traverse(t->child[i],preProc,postProc);
        postProc(t);
    LOAD;
        traverse(t->sibling,preProc,postProc);
    }
}
//preorder check -> post order check
static int checkNode_preorder( TreeNode * t){//preorder traverse
    char *_name=NULL;
    unsigned _count=0,_scope=0
    switch (t->nodekind){ 
        case DeclK:
            switch (t->kind.decl){
                case FunK:
                    fun_name = t->attr.name;
                    break;
                case VarK:
                    break;
                case VarArrK:
                    break;
                case ParaK:
                    break;
                default:
                    break;
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:
                    scope++;
                    order = 0;
                    break;
                case SelcK:
                    break;
                case IterK:
                    break;
                case RetK:
                    break;
                case CallK://8,9
                    TreeNode *temp = NULL;
                    temp = st_lookup(fun_name,count,scope);
                    if(temp == NULL)
                        return -1;
                    else if(temp->nodekind == DeclK && temp ->kind.decl == FunK)){
                        TreeNode * params = temp -> child[0],*args = t->child[0];
                        while(params !=NULL){
                            if(args == NULL || (params->type != args -> type))
                                return -1;
                        }
                        if(args != NULL)
                            return -1;
                        
                    }
                    else
                        return -1;
                    break;
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp){
                case IdK://1,7:
                    TreeNode *temp = NULL; 
                    temp = st_lookup(fun_name,count,scope);
                    if(temp == NULL)
                        return -1;
                    else if(t->type == Array_Nocheck){
                        if(temp -> kind.decl != VarArrK)
                            return -1;
                    }
                    else{
                        if(!(temp->nodekind == DeclK && temp -> kind.decl == Vark))
                            return -1;
                    }

                    break;
                case ConstK:
                    break;
                case OpK:
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}


static int checkNode( TreeNode * t){//postorder traverse
    switch (t->nodekind){ 
        case DeclK:
            switch (t->kind.decl){
                case FunK://10
                    TreeNode * temp = NULL;
                    short flag = 0;
                    temp = t->child[0]->child[1];//statement
                    while(temp != NULL){
                        if(temp -> nodekind == StmtK && temp -> kind.stmt == RetK){
                            flag = 1;
                            break; 
                        }
                        temp = temp -> sibling;
                    }
                    if(t -> type == Void && flag == 1)
                        return -1;
                    else if (t - >type == Integer && flag == 0)
                        return -1;
                    break;
                case VarK:
                    if(t->type != Integer)
                        return -1;//error
                    break;
                case VarArrK:
                    if(t->type != Integer)
                        return -1;//error
                    t->type = Array;

                    break;
                case ParaK:
                    
                    if(t->type == Error || t ->type == Void )
                        return -1;
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
                        return -1;//error
                    break;
                case IterK:
                    if(t->child[0]->type != Integer)
                        return -1;//error
                    break;
                case RetK://10
                    if(t->child[0] == NULL ||(t->child[0]!=NULL && t->child[0]->type != Integer))
                        return -1;//error
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
                    if(t->type == Array_NoCheck && t->child[0]->type != Integer)
                            return -1;//error
                    t -> type = Integer;
                    break;
                case ConstK:
                    break;
                case OpK:
                    if(!(t->child[0]->type == Integer && t -> child[1]->type == Integer))
                        return -1;//error
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


