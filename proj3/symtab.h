#ifndef _SYMTAB_H_
#define _SYMTAB_H_
#include "globals.h"
/* the hash function */
#define SIZE 211
#define SHIFT 4
static int hash ( char * key ){
    int temp = 0;
    int i = 0;
    while (key[i] != '\0' )
    { temp = ((temp <<SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

typedef enum {Var, Func, Par} isvpf;

/* the list of line numbers of the source
 * code in which a variable is referenced
 */
typedef struct LineListRec{
    int lineno;
    struct LineListRec * next;
} * LineList;

/* The record in the bucket lists for
 * each variable, including name,
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */

typedef struct BucketListRec{
    char * name;
    LineList lines;
    int memloc; /* memory location for variable */
	isvpf vpf;
	int isarr;
	int arrsize;
	Type type;
	struct BucketListRec * next;
} * BucketList;

typedef struct ScopeListRec{
	int level;
	int valid;
	BucketList bucket[SIZE];
	struct ScopeListRec * next;
} * ScopeList;

ScopeList total_sym ;
ScopeList global_sym;

void insert_scope(int scope);
void st_insert ( char * name, int lineno, int loc, isvpf vpf,int isarr, int arrsize,Type type,int isglobal);
int st_lookup (char* name);
/* procedure printSymTab prints a formatted
* listing of the symbol table contents
* to the listing file
*/
void printSymTab(FILE * listing);
#endif
