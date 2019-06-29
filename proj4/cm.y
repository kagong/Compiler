%{
#define YYPARSER
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define MAX_STACK 256
#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo; /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static Type savedType;

int yyerror(char * message);
static int yylex(void);

static TokenType StackOp[MAX_STACK];
static char* StackID[MAX_STACK];
static Type StackType[MAX_STACK];
static int StackLine[MAX_STACK];
static int top = -1,top_id = -1,top_type = -1;

static int temp;
static void push_op(TokenType);
static int pop_op();
static void push_ID(char*);
static char* pop_ID();
static void push_type(Type);
static Type pop_type();

#define SAVEID do{\
    push_ID(copyString(prev));\
}while(0)\
%}
%token ENDFILE ERROR
%token IF INT VOID ELSE WHILE RETURN
%token ID NUM
%token PLUS MINUS TIMES OVER 
%token GET GT LET LT EQ NEQ 
%token ASSIGN
%token SEMI COMMA 
%token LPAREN RPAREN LCBRAKET RCBRAKET LSBRAKET RSBRAKET

%nonassoc RPAREN
%nonassoc ELSE

%start program
%%
program                 :   declaration-list                {savedTree = $1;}
                        ;

declaration-list        :   declaration-list declaration    
                            {
                                YYSTYPE t = $1;
                                if (t != NULL){ 
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = $2;
                                    $$ = $1; 
                                }
                                else $$ = $2;
                            }
                        |   declaration                     {$$ = $1;}
                        ;

declaration             :   var-declaration                 {$$ = $1;}
                        |   fun-declaration                 {$$ = $1;}
                        ;

var-declaration         :   type-specifier ID { SAVEID; } SEMI              
                            {
                                $$ = newDeclNode(VarK);
                                $$ -> attr.decl.name = pop_ID();
                                $$ -> type = pop_type();
                            }
                        |   type-specifier ID { SAVEID; } LSBRAKET NUM {temp = atoi(tokenString);} RSBRAKET SEMI         
                            {
                                $$ = newDeclNode(VarArrK);
                                $$ -> attr.decl.name =pop_ID();
                                $$ -> type = pop_type();
                                $$ -> attr.decl.arr_size = temp;
                            }
                        ;

type-specifier          :   INT         {push_type(Integer);}
                        |   VOID        {push_type(Void);}
                        ;

fun-declaration         :   type-specifier ID {SAVEID;} LPAREN params RPAREN compound-stmt
                            {
                                $$ = newDeclNode(FunK);
                                $$ -> attr.decl.name = pop_ID();
                                $$ -> type = pop_type();
                                $$ -> child[0] = $5;
                                $$ -> child[1] = $7;
                                $$ -> child[1] -> kind.stmt = FompndK;
                            }
                        ;

params                  :   param-list                      {$$ = $1;}
                        |   VOID                            {$$ = NULL;}
                        ;

param-list              :   param-list COMMA param          
                            {
                                YYSTYPE t = $1;
                                while (t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $3;
                                $$ = $1;
                            }
                        |   param                           {$$ = $1;}
                        ;

param                   :   type-specifier ID                       
                            {
                                SAVEID;
                                $$ = newDeclNode(ParaK);
                                $$ -> attr.decl.name = pop_ID();
                                $$ -> type = pop_type();

                            }
                        |   type-specifier ID { SAVEID; } LSBRAKET RSBRAKET                 
                            {
                                $$ = newDeclNode(ParaK);
                                $$ -> attr.decl.name = pop_ID();
                                $$ -> type = Array;
                                if(pop_type() == Void)
                                    $$ -> type = Err;
                                $$ -> attr.decl.arr_size = 0;
                            }
                        ;

compound-stmt           :   LCBRAKET local-declarations statement-list RCBRAKET    
                            {
                                $$ = newStmtNode(CompndK);
                                $$ -> child[0] = $2;//enable to be null
                                $$ -> child[1] = $3;//enable to be null
                            }
                        ;

local-declarations      :   local-declarations var-declaration      
                            {
                                if($1 != NULL){
                                    YYSTYPE t = $1;
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = $2;
                                    $$ = $1;
                                }
                                else $$ = $2;
                            }
                        |   empty                           {$$ = $1;}
                        ;

statement-list          :   statement-list statement                
                            {
                                if($1 != NULL){
                                    YYSTYPE t = $1;
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = $2;
                                    $$ = $1;
                                }
                                else $$ = $2;
                            }
                        |   empty                           {$$ = $1;}
                        ;

statement               :   expression-stmt                 {$$ = $1;}
                        |   compound-stmt                   {$$ = $1;}
                        |   selection-stmt                  {$$ = $1;}
                        |   iteration-stmt                  {$$ = $1;}
                        |   return-stmt                     {$$ = $1;}
                        ;

expression-stmt         :   expression SEMI                 {$$ = $1;}
                        |   SEMI                            {$$ = NULL;}
                        ;

selection-stmt          :   IF LPAREN expression RPAREN statement       
                            {
                                $$ = newStmtNode(SelcK);
                                $$ -> child[0] = $3;
                                $$ -> child[1] = $5;
                            }
                        |   IF LPAREN expression RPAREN statement ELSE statement    
                            {
                                $$ = newStmtNode(SelcK);
                                $$ -> child[0] = $3;
                                $$ -> child[1] = $5;
                                $$ -> child[2] = $7;
                            }
                        ;

iteration-stmt          :   WHILE LPAREN expression RPAREN statement        
                            {
                                $$ = newStmtNode(IterK);
                                $$ -> child[0] = $3;
                                $$ -> child[1] = $5;
                            }
                        ;

return-stmt             :   RETURN SEMI                 
                            {
                                $$ = newStmtNode(RetK);
                            }
                        |   RETURN expression SEMI
                            {
                                $$ = newStmtNode(RetK);
                                $$ -> child[0] = $2;
                            }

                        ;

expression              :   var ASSIGN expression      
                            {
                                $$ = newExpNode(OpK);
                                $$ -> attr.op = ASSIGN;
                                $$ -> child[0] = $1;
                                $$ -> child[1] = $3;
                            }
                        |   simple-expression               {$$ = $1;}
                        ;

var                     :   ID  
                            {
                                SAVEID;
                                $$ = newExpNode(IdK);
                                $$ -> attr.decl.name = pop_ID();
                            }
                        |   ID { SAVEID; } LSBRAKET expression RSBRAKET  
                            {
                                $$ = newExpNode(IdK);
                                $$ -> attr.decl.name = pop_ID();
                                $$ -> child[0] = $4;
                                $$ -> type = Array_Nocheck;
                            }
                        ;

simple-expression       :   additive-expression relop additive-expression   
                            {
                                $$ = newExpNode(OpK);
                                $$ -> child[0] = $1;
                                $$ -> child[1] = $3;
                                $$ -> attr.op = pop_op();
                            }
                        |   additive-expression             {$$ = $1;}
                        ;

relop                   :   LT                              {push_op(LT);}
                        |   LET                             {push_op(LET);}
                        |   GT                              {push_op(GT);}
                        |   GET                             {push_op(GET);}
                        |   EQ                              {push_op(EQ);}
                        |   NEQ                             {push_op(NEQ);}
                        ;
                        
additive-expression     :   additive-expression addop term      
                            {
                                $$ = newExpNode(OpK);
                                $$ -> attr.op = pop_op();
                                $$ -> child[0] = $1;
                                $$ -> child[1] = $3;
                            }
                        |   term                            {$$ = $1;}
                        ;


addop                   :   PLUS                            {push_op(PLUS);}
                        |   MINUS                           {push_op(MINUS);}
                        ;

term                    :   term mulop factor               
                            {
                                $$ = newExpNode(OpK);
                                $$ -> attr.op = pop_op();
                                $$ -> child[0] = $1;
                                $$ -> child[1] = $3;
                            }
                        |   factor                          {$$ = $1;}
                        ;

mulop                   :   TIMES                           {push_op(TIMES);}
                        |   OVER                            {push_op(OVER);}
                        ;

factor                  :   LPAREN expression RPAREN        {$$ = $2;}
                        |   var                             {$$ = $1;}
                        |   call                            {$$ = $1;}
                        |   NUM                             
                            {
                                $$ = newExpNode(ConstK);
                                $$->attr.val = atoi(tokenString);
                                $$ -> type = Integer;
                            }
                        ;

call                    :   ID {SAVEID;} LPAREN args RPAREN       
                            {
                                $$ = newStmtNode(CallK);
                                $$ -> attr.decl.name = pop_ID();
                                $$ -> child[0] = $4;
                            }
                        ;
//look up이 필요함 함수의 반환값 필요.
args                    :   arg-list                        {$$ = $1;}
                        |   empty                           {$$ = $1;}
                        ;

arg-list                :   arg-list COMMA expression       
                            {
                                if($1 != NULL){
                                    YYSTYPE t = $1;
                                    while (t->sibling != NULL)
                                        t = t->sibling;
                                    t->sibling = $3;
                                    $$ = $1;
                                }
                                else $$ = $3;

                            }
                        |   expression                      {$$ = $1;}
                        ;
empty                   :                                   {$$ = NULL;}
                        ;
%%
static void push_op(TokenType op){
    if(top >= MAX_STACK)
        return;
    StackOp[++top] = op;
}
static TokenType pop_op(){
    if(top >= 0)
        return StackOp[top--];
    return -1;
}
static void push_ID(char* id){
    if(top_id >= MAX_STACK)
        return;
    StackID[++top_id] = id;
}
static char* pop_ID(){
    if(top_id >= 0)
        return StackID[top_id--];
    return NULL;
}
static void push_type(Type t){
    if(top_type >= MAX_STACK)
        return;
    StackType[++top_type] = t;
}
static Type pop_type(){
    if(top_type >= 0)
        return StackType[top_type--];
    return 0;
}


int yyerror(char * message){
    fprintf(listing, "Syntax error at line %d: %s\n" ,lineno,message);
    fprintf(listing, "Current token: ");
    printToken(yychar,tokenString);
    Error = TRUE;
    return 0;
}


/* yylex calls getToken to make Yacc/Bison output
* cαnpatible with earlier versions of
* the TINY scanner
*/
static int yylex(void){
    int token = getToken();
    return token;
}
TreeNode* parse(void){
    yyparse();
    return savedTree;
}


