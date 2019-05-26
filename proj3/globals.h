#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef YYPARSER
    #include "cm.tab.h"
    #define ENDFILE 0
#endif

#ifndef FALSE
    #define FALSE 0
#endif

#ifndef TRUE
    #define TRUE 1
#endif

 /* MAXRESERVED = the number of reserved words */
#define MAXRESERVED 8

typedef int TokenType;

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */

extern int lineno; /* source line number for listing */

/*************************************************/
/*********** Syntax tree for parsing ***********/
/*************************************************/

typedef enum {DeclK,StmtK,ExpK} NodeKind;
typedef enum {FunK,VarK,VarArrK,ParaK} DeclKind;
typedef enum {CompndK,SelcK, IterK, RetK, CallK} StmtKind;
typedef enum {OpK,ConstK, IdK} ExpKind;

/* Exp양pe is used for type cheking */
typedef enum {Notype, Void, Integer, Array, Array_Nocheck, Error} Type;

#define MAXCHILDREN 4

typedef struct treeNode{ 
    struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;
    int lineno;
    
    NodeKind nodekind;
    union { 
        DeclKind decl;
        StmtKind stmt; 
        ExpKind exp;
    }kind;
    union {
        struct {
            char *name;
            int arr_size;
        }decl;
        TokenType op;
        int val;
    }attr;
    Type type;
} TreeNode;

/*************************************************/
/*********** Flags for tracing ***********/
/*************************************************/


/* EchoSource = TRUE causes the source program t。
 * be echoed to the listing file with line numbers
 * during parsing
 */
extern int EchoSource;

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
extern int TraceScan;

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized fonn
 * (using indents for children)
 */
extern int TraceParse;

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
extern int TraceAnalyze;

/* TraceCode = TRUE causes comments to bewritten
 * to the TM code file as code is generated
 */
extern int TraceCode;

/* Error = TRUE prevents further passes if an error occurs */
extern int Error;
#endif
