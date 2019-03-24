%option noyywrap

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
    /* lexeme of identifier or reserved word */
#define MAXTOKENLEN 40
char tokenString[MAXTOKENLEN+1];
%}


digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+


%%
"if"        {return IF;}
"else"      {return ELSE;}
"int"       {return INT;}
"void"      {return VOID;}
"while"     {return WHILE;}
"return"    {return RETURN;}

"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return TIMES;}
"/"         {return OVER;}
"<="        {return GET;}
"<"         {return GT;}
">="        {return LET;}
">"         {return LT;}
"=="        {return EQ;}
"="         {return ASSIGN;}
"!="        {return NEQ;}
";"         {return SEMI;}
","         {return COMMA;}
"("         {return LPAREN;}
")"         {return RPAREN;}
"{"         {return LCBRAKET;}
"}"         {return RCBRAKET;}
"["         {return LSBRAKET;}
"]"         {return RSBRAKET;}
"/*"        {register int c;
                for(;;){
                    while((c = input())!= '*' && c != EOF);
                    if(c =='*'){
                        while((c =input())=='*');
                        if(c == '/')
                            break;
                    }
                    if(c == EOF){
                        return ERROR;
                    }
                }
            }

{identifier}    {return ID;}
{number}        {return NUM;}
{newline}       {lineno++;}
{whitespace}    {}

<<EOF>>         {return ENDFILE;}

    
%%

TokenType getToken(void){
    static int firstTime = TRUE;
    TokenType currentToken;
    if(firstTime){
        firstTime = FALSE;
        lineno++;
        yyin = source;
        yyout = listing;
    }

    currentToken = yylex();
    strncpy(tokenString,yytext,MAXTOKENLEN);
    if(TraceScan){
        fprintf(listing,"\t%d: ",lineno);
        printToken(currentToken,tokenString);
    }
    return currentToken;
}
