#include "globals.h"

#define NO_PARSE TRUE

#define NO_ANALYZE FALSE

#define NO_CODE TRUE

#include "util.h"

#if NO_PARSE
    #include "scan.h"
#else
    #include "parse.h"
    #if !NO_ANALYZE
        #include "analyze.h"
        #if !NO_PARSE
            #include "cgen.h"
        #endif
    #endif
#endif

int lineno = 0;
FILE *source;
FILE *listing;
FILE *code;

/* allocate and set tracing flags */
int EchoSource = TRUE;
int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = TRUE;
int TraceCode = TRUE;

int Error = FALSE;

int main( int argc, char * argv[]){
    TreeNode * syntaxTree;
    char pgm[20]; /* source code file name */
    if (argc != 2){ 
        fprintf(stderr, "usage: %s <filename>\n",argv[0]);
        exit(1) ;
    }
    strcpy(pgm,argv[1]);
    if (strchr (pgm,'.') == NULL)
        strcat(pgm, ".c");

    source = fopen(pgm, "r");
    if (source==NULL){ 
        fprintf(stderr, "File %s not found\n" ,pgm);
        exit(1);
    }

    listing = stdout; /* send listing to screen */
    fprintf (listing, "\nC- COMPlLATION: %s\n" ,pgm);
#if NO_PARSE
    while (getToken() != ENDFILE) ;
#else
    syntaxTree = parse();
    if (TraceParse) {
        fprintf (listing, " \nSyntax tree: \n");
        printTree(syntaxTree);
    }

    #if !NO_ANALYZE
    if(!Error){
        fprintf(listing, "\nBuilding Symbol Table ... \ n");
        buildSymtab(syntaxTree);
        fprintf(listing," \nChecking Types ... \n");
        typeCheck(syntaxTree);
        fprintf (listing, " \n Type Checking Finished\n");
    }
        #if !NO_CODE
        if (!Error){ 
            char * codefile;
            int fnlen = strcspn(pgm, "." ) ;
            codefile = (char *) calloc(fnlen+4, sizeof(char));
            strncpy(codefile,pgm, fnlen);
            strcat (codefile, ".tm") ;
            code = fopen(codefile, "w");
            if {code == NULL}{ 
                printf ("Unable to open %s\n" ,codefile);
                exit(l);
            }
    
            codeGen(syntaxTree,codefile);
            fclose(code);
        }
        #endif
    #endif
#endif
    return 0;
}
