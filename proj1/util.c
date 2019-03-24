#include "globals.h"
#include "util.h"

/* procedure printToken prints a token
 *  * and its lexeme to the listing file
 *   */
void printToken( TokenType token, const char* tokenString ){
    switch (token){ 
        case IF:
        case ELSE:
        case INT:
        case VOID:
        case WHILE:
        case RETURN:    fprintf(listing,"reserved word: %s\n" , tokenString);   break;

        case NUM:       fprintf(listing,"NUM, val= %s\n",tokenString);          break;
        case ID:        fprintf(listing,"ID, name= %s\n",tokenString);          break;

        case PLUS:      fprintf(listing,"+\n");                                 break;
        case MINUS:     fprintf(listing,"-\n");                                 break;
        case TIMES:     fprintf(listing,"*\n");                                 break;
        case OVER:      fprintf(listing," /\n");                                break;
        case GET:       fprintf(listing,"<=\n");                                break;
        case GT:        fprintf(listing,"<\n");                                 break;
        case LET:       fprintf(listing,">=\n");                                break;
        case LT:        fprintf(listing,">\n");                                 break;
        case EQ:        fprintf(listing,"==\n");                                break;
        case ASSIGN:    fprintf(listing,"=\n");                                 break;
        case NEQ:       fprintf(listing,"!=\n");                                break;
        case SEMI:      fprintf(listing,";\n");                                 break;
        case COMMA:     fprintf(listing,",\n");                                 break;
        case LPAREN:    fprintf(listing,"(\n");                                 break;
        case RPAREN:    fprintf(listing,")\n");                                 break;
        case LCBRAKET:  fprintf(listing,"{\n");                                 break;
        case RCBRAKET:  fprintf(listing,"}\n");                                 break;
        case LSBRAKET:  fprintf(listing,"[\n");                                 break;
        case RSBRAKET:  fprintf(listing,"]\n");                                 break;

        case ERROR:     fprintf(listing,"ERROR: %s\n",tokenString);             break;
        case ENDFILE:   fprintf(listing,"EOF\n");                               break;
        default:        fprintf(listing,"Unknown token:: %d\n",token);
    }
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
        t->type = Void;

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
void printTree( TreeNode * tree ){
    int i;
    INDENT;
    while(tree != NULL) {
        printSpaces();
        if (tree->nodekind==StmtK){ 
            switch (tree->kind.stmt){
                case IfK:
                    fprintf(listing,"If\n");
                    break;
                case RepeatK:
                    fprintf (listing, "Repeat\n") ;
                    break;
                case AssignK:
                    fprintf (listing, "Assign to: %s\n",tree->attr.name);
                    break;
                case ReadK:
                    fprintf(listing, "Read: %s\n",tree->attr.name) ;
                    break;
                case WriteK:
                    fprintf (listing, "write\n");
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
                    fprintf(listing, "Id: %s\n",tree->attr.name);
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
