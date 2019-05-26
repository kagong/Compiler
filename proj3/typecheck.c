static int checkNode( TreeNode * t){//inorder traverse
    switch (t->nodekind){ 
        case DeclK:
            switch (t->kind.decl){
                case FunK:
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
                case RetK:
                    if(t->child[0]!=NULL && t->child[0]->type != Integer)
                        return -1;//error
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


