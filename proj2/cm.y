%{
#define YYPARSER
#include "globals.h"
#include "util.h"
#include "scan.h"
//#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo; /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

int yyerror(char * message);
static int yylex(void);

%}
%token ENDFILE ERROR
%token IF ELSE INT VOID WHILE RETURN
%token ID NUM
%token PLUS MINUS TIMES OVER GET GT LET LT EQ ASSIGN NEQ SEMI COMMA LPAREN RPAREN LCBRAKET RCBRAKET LSBRAKET RSBRAKET

%start program
%%
program                 :   declaration-list                {savedTree = $1;}
                        ;

declaration-list        :   declaration-list declaration    { }
                        |   declaration                     {}
                        ;

declaration             :   var-declaration                 {}
                        |   fun-declaration                 {}
                        ;

var-declaration         :   type-specifier ID SEMI              {}
                        |   type-specifier ID LSBRAKET NUM RSBRAKET SEMI         {}
                        ;

type-specifier          :   INT|VOID
                        ;

fun-declaration        :   type-specifier ID LPAREN params RPAREN compound-stmt  {}
                        ;

params                  :   param-list                              {}
                        |   VOID
                        ;

param-list              :   param-list COMMA param                        {}
                        |   param                                   {}
                        ;

param                   :   type-specifier ID                       {}
                        |   type-specifier ID LSBRAKET RSBRAKET                 {}
                        ;

compound-stmt           :   LCBRAKET local-declarations statement-list RCBRAKET    {}
                        ;

local-declarations      :   local-declarations var-declaration      {}
                        |   empty
                        ;

statement-list          :   statement-list statement                {}
                        |   empty
                        ;

statement               :   expression-stmt                        {}
                        |   compound-stmt                           {}
                        |   selection-stmt                          {}
                        |   iteration-stmt                          {}
                        |   return-stmt                             {}
                        ;

expression-stmt         :   expression SEMI                            {}
                        |   SEMI
                        ;

selection-stmt          :   IF LPAREN expression RPAREN statement       {}
                        |   IF LPAREN expression RPAREN statement ELSE statement    {}
                        ;

iteration-stmt         :   WHILE LPAREN expression RPAREN statement        {}
                        ;

return-stmt             :   RETURN SEMI                 {}
                        |   RETURN expression SEMI      {}
                        ;

expression              :   var ASSIGN expression      {}
                        |   simple-expression           {}
                        ;

var                     :   ID  {}
                        |   ID LSBRAKET expression RSBRAKET  {}
                        ;

simple-expression      :   additive-expression relop additive-expression   {}
                        |   additive-expression                             {}
                        ;

relop                   :   LT  {}
                        |   LET {}
                        |   GT  {}
                        |   GET {}
                        |   EQ  {}
                        |   NEQ {}
                        ;
                        
additive-expression     :   additive-expression addop term      {}
                        |   term                    {}
                        ;


addop                   :   PLUS                       {}
                        |   MINUS                       {}
                        ;

term                    :   term mulop factor          {}
                        |   factor                  {}
                        ;

mulop                   :   TIMES   {}
                        |   OVER   {}
                        ;

factor                  :   LPAREN expression RPAREN        {}
                        |   var {}
                        |   call {}
                        |   NUM {}
                        ;

call                    :   ID LPAREN args RPAREN       {}
                        ;

args                    :   arg-list    {}
                        |   empty
                        ;

arg-list                :   arg-list COMMA expression       {}
                        |   expression      {}
                        ;
empty                   :           {}
                        ;
%%
int yyerror(char * message){
//    fprintf(listing, "Syntax error at line %d: %s\n" ,lineno,message);
  //  fprintf(listing, "Current token: ");
   // printToken(yychar,tokenString);
   // Erro = TRUE;
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

TreeNode * parse(void){
    yyparse();
    return savedTree;
}


