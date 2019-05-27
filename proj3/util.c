#include "globals.h"
#include "util.h"
#include "cm.tab.h"

/* procedure printToken prints a token
 *  * and its lexeme to the listing file
 *   */
void printToken( TokenType token, const char* tokenString ){
    char *token_name = NULL;
    switch (token){ 
        case IF:        token_name = "IF";      break;
        case ELSE:      token_name = "ELSE";    break;
        case INT:       token_name = "INT";     break; 
        case VOID:      token_name = "VOID";    break;
        case WHILE:     token_name = "WHILE";   break;
        case RETURN:    token_name = "RETURN";  break;

        case NUM:       token_name = "NUM";     break;
        case ID:        token_name = "ID";      break;

        case PLUS:      token_name = "+";       break;
        case MINUS:     token_name = "-";       break;
        case TIMES:     token_name = "*";       break;
        case OVER:      token_name = "/";       break;
        case GET:       token_name = "<=";      break;
        case GT:        token_name = "<";       break;
        case LET:       token_name = ">=";      break;
        case LT:        token_name = ">";       break;
        case EQ:        token_name = "==";      break;
        case ASSIGN:    token_name = "=";       break;
        case NEQ:       token_name = "!=";      break;
        case SEMI:      token_name = ";";       break;
        case COMMA:     token_name = ",";       break;
        case LPAREN:    token_name = "(";       break;
        case RPAREN:    token_name = ")";       break;
        case LCBRAKET:  token_name = "{";       break;
        case RCBRAKET:  token_name = "}";       break;
        case LSBRAKET:  token_name = "[";       break;
        case RSBRAKET:  token_name = "]";       break;
        case ERROR:     token_name = "ERROR";   break;
        case ENDFILE:   token_name = "EOF"; break;
        default:        token_name = "UNKNOWN"; break;

    }
    fprintf(listing,"%s %s\n",token_name,tokenString);     

}

TreeNode * newDeclNode(DeclKind kind){
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        fprintf(listing, "Out of memory error at line %d\n" , lineno);
    else {
        for(i=0; i<MAXCHILDREN; i++) 
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = DeclK;
        t->kind.decl = kind;
        t->lineno = lineno;
        t->attr.decl.arr_size = 0;
        t->type = Notype;
    }
    return t;
}
TreeNode * newStmtNode(StmtKind kind){
    TreeNode *t = (TreeNode*)malloc(sizeof(TreeNode));
    int i;
    if (t == NULL)
        fprintf(listing, "Out of memory error at line %d\n" , lineno);
    else {
        for(i=0; i<MAXCHILDREN; i++) 
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = StmtK;
        t->kind.stmt = kind;
        t->lineno = lineno;
        t->type = Notype;
    }
    return t;
}
/* Function newExpNode creates a new expression
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind){
    TreeNode *t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if (t==NULL)
        fprintf (listing, "out of memory error at line %d\n" , lineno);
    else {
        for (i=0;i<MAXCHILDREN;i++) 
            t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = ExpK;
        t->kind.exp = kind;
        t->lineno = lineno;
        t->type = Notype;

    }
    return t;
}

/* F‘unction copyString allocates and makes a new
 * copy of an  existing string
 */
char * copyString(char * s){
    int n;
    char *t;
    if (s==NULL) 
        return NULL;
    n = strlen(s)+1;
    t = malloc (n) ;
    if (t==NULL)
        fprintf (listing, "Out of memory error at line %d\n" , lineno);
    else strcpy(t,s);
    return t;
}

/* Variable indentno is used by printTree t.
 * store current number of spaces to indent
 */

static int indentno = 0;
/* macros to increase/decrease indentation */

#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents byprinting spaceS*/
static void printSpaces(void){
    int i;
    for (i=0; i < indentno ; i++)
        fprintf(listing," ");
}

/* procedure printTree prints a syntax tree to the
 * listing file using indentation to indicate subtrees  
 */
void printType(TreeNode * tree){
    INDENT;
    printSpaces();
    switch(tree->type){
        case Integer:
            fprintf(listing,"Type: Int\n");
            break;
        case Void://error
            fprintf(listing,"Type: Void\n");
            break;
        case Array_Nocheck:
        case Array:
            fprintf(listing,"Type: array %d \n",tree->attr.decl.arr_size);
            break;
        default:
            break;
    }
    UNINDENT;
}
//void printIDType(TreeNode * tree){
//    printSpaces();
//    switch(tree->type){
//        case Integer:
//            fprintf(listing,"Type: int\n");
//            break;
//        case Void://error
//            fprintf(listing,"error\n");
//            break;
//        case Array:
//            fprintf(listing,"Type: array %d \n",tree->attr.decl.arr_size);
//            break;
//        default:
//            fprintf(listing,"error\n");
//            break;
//    }
//}
void printTree( TreeNode * tree ){
    int i;
    INDENT;
    while(tree != NULL) {
        printSpaces();
        if (tree->nodekind == DeclK){
            switch(tree -> kind.decl){
                case FunK:
                    fprintf(listing,"Function: %s\n",tree->attr.decl.name);
                    printType(tree);
                    break;
                case VarK:
                case VarArrK:
                    fprintf(listing,"ID: %s\n",tree->attr.decl.name);
                    printType(tree);
                    break;
                case ParaK:
                    switch(tree->type){
//                        case Void:    
//                            fprintf(listing,"Parameter: %s\n","VOID");
   //                         break;
                        default:
                            fprintf(listing,"Parameter: %s\n",tree->attr.decl.name );
                            printType(tree);
                    }

            }
        }
        else if (tree->nodekind==StmtK){ 
            switch (tree->kind.stmt){
                case FompndK:
                case CompndK:
                    fprintf(listing,"Compound statement\n");
                    break;
                case SelcK:
                    fprintf(listing,"If\n");
                    break;
                case IterK:
                    fprintf(listing,"While\n");
                    break;
                case RetK:
                    fprintf(listing,"Return\n");
                    break;
                case CallK:
                    fprintf(listing,"Call procedure: %s\n",tree->attr.decl.name);
                    break;
                default:
                    fprintf (listing, "Unknown ExpNode kind\n");
                    break;
            }
        }
        else if (tree->nodekind==ExpK){
            switch (tree->kind.exp) {
                case OpK:
                    fprintf(listing,"Op: ");
                    printToken(tree->attr.op, "\0") ;
                    break;
                case ConstK:
                    fprintf(listing, "const: %d\n",tree->attr.val);
                    break;
                case IdK:
                    fprintf(listing, "Id: %s\n",tree->attr.decl.name);
                    if(tree->child[0] != NULL){//array
                        INDENT;
                        printSpaces();
                        UNINDENT;
                        fprintf(listing, "Index Expression\n");
                    }
                    break;
                default:
                    fprintf(listing, "unknown ExpNode kind\n") ;
                    break;
            }
        }

        else fprintf (listing, "Unknown node kind\n") ;
        for (i= 0; i<MAXCHILDREN; i++)
            printTree(tree->child[i]);
        tree = tree->sibling;
    }

    UNINDENT;
}
