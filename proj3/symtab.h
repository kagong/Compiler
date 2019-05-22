#ifndef _SYMTAB_H_
#define _SYMTAB_H_
/* procedure st_insert inserts 1ine numbers and
* IlIi태~ry 10cations into the symbo1 tab1e
* 10c = memory 10cation is inserted on1y the
* first time, otherwise ignored
*/

/* the hash function */
static int hash ( char * key ){
    int temp = 0;
    int i = 0;
    while (key[i] != '\0' )
    { temp = ((temp <<SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}


/* the list of line numbers of the source
 * code in which a variable is referenced
 */
typedef struct LineListRec{
    int lineno;
    struct LineListRec * next;
}*LineList;

/* The record in the bucket lists for
 * each variable, including name,
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */

typedef struct BucketListRec{
    char * name;
    LineList lines;
    int malloc /* memory location for variable */
    struct BucketListRec * next;
} * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

void st_insert(char* name, int lineno, int loc );
/* Function st 1001ζup returns the mem야Y
* 10cation of a variab1e or -1 ifnot found
*/
int st_lookup (char* name);
/* procedure printSymTab prints a formatted
* 1isting of the symbo1 tab1e contents
* to the 1isting fi1e
*/
void printSymTab(FILE * listing);
#endif
