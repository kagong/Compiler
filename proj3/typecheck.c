static void checkNode( TreeNode * t){
    switch (t->nodekind){ 
        case DeclK:
            switch (t->kind.decl){
                case FunK:
                    //funtion symbol table name change ex) funtion1 -> main
                    break;
                case VarK:
                    if(t->type == Void)
                        ;//error
                    break;
                case VarArrK:
                    if(t->type == Error)
                        ;//error

                case ParaK:
                    if(t->type == Void)
                        ;//error
                default:
            }
            break;
        case StmtK:
            switch (t->kind.stmt){ 
                case CompndK:
                    //scope up
                case SelcK:
                    if(t->child[0]->type != Integer)
                        ;//error
                case IterK:
                    if(t->child[0]->type != Integer)
                        ;//error
                case RetK:
                    //function name == main : error
                    if(t->child[0]!=NULL && t->child[0]->type != Integer)
                        ;//error
                case CallK:
                    //lookup symtab
                    //check arg's type
                default:
                    break;
            }
            break;
        case ExpK:
            switch (t->kind.exp){
                case IdK:
                    if(t->child[0] != NULL)//nocheck array라는 타입을 만드는게 좋을듯?
                    {
                        if(t->child[0]->type != Integer)
                            ;//error
                    }
                    //array를 integer로 변경? nocheck array에서 integer로
                    //변경시키고 isarray라는 변수 만드는게 좋ㅎ을듯
                    t->type = Integer;
                    break;
                case ConstK:
                    break;
                case OpK:
                    if(!(t->child[0]->type == Integer && t -> child[1]->type == Integer))
                        ;//error
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


