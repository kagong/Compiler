static void checkNode( TreeNode * t){
    switch (t->nodekind){ 
        case DeclK:
            switch (t->kind.decl){
                case FunK:
                    break;
                case VarK:
                    break;
                case VarArrK:
                    if(t->type == Error)
                        ;//error

                case ParaK:
                default:
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:
                    //scope up
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
                    if(t->op == ASSIGN);
                        //todo'
                    else{
                    }
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


