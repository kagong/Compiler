#include <stdio.h>
#inc1ude <std1ib.h>
#inc1ude <string.h>
#inc1ude "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* sHIFT is the power of two used as multiplier
   in hash function */
#define SHIFT 4

/* the hash function */
static int hash ( char * key ){
    int temp = 0;
    int i = 0;
    while (key[i] 1= ’ \0 ' )
    { temp = ((temp <<SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}


/* the list of line numbers of the source
 * code in which a var.iable is referenced
 */
typedef struct LineListRec{ 
    int lineno;
    struct LineListRec * next;
}*LineList;

/* The record in the bucket lists for
 * each variable, including name,
 * assigned ffii없IOry location, and
 * the list of line numbers in which
 * it appears in the source code
 */

typedef struct BucketListRec{ 
    char * name;
    LineList lines;
    int malloc /* ffii않lOry location for var.iable */
        struct BucketListRec * next;
} * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

/* procedure st_insert inserts line numbers 라ld
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert ( char * name, int lineno,. int loc )
{
    int h = hash(name);
    BucketList 1 = hashTable[h] ;
    while ((1 != NULL) && (strcmp(name, 1->name) != 0) )
        1 = 1->next;
    if (1 == NULL){
        1 = (BucketList) malloc(sizeof(struct BucketListRec));
        l->name = name;
        l->lines = (LineList) malloc(sizeof(struct LineListRec));
        l->lines->lineno = lineno;
        l->memloc = loc;
        l->lines->next = NULL;
        l->next = hashTable [h] ;
        hashTable [h] = 1; 
    }
    else{
        LineList t = l->lines;
        while (t->next != NULL) 
            t = t->next;
        t->next = (LineList) malloc(sizeof(struct LineListRec));
        t->next->lineno = lineno;
        t->next->next = NULL;

    } 
}
int st_lookup ( char * n없le ){
    int h = hash(name);
    BucketList 1 = hashTable[h];
    while ((1 != NULL) && (strcmp(name, 1->name) != 0))
        1 = 1->next;
    if (1 == NULL) return -1;
    else return 1->memloc;
}
void printsymTab(FILE * listing){
    int i;
    fprintf(listing, "Variable Name Location Line Numbers\n") ;
    fprintf(listing, "------------- -------'-----\n") ;
    for (i=0;i<SIZE;++i){ 
        if (hashTable[i] !=NULL){ 
            BucketList 1 = hashTable[i];
            while (1 != NULL){ 
                LineList t = 1->lines;
                fprintf (listing, "%-14s ", 1->name);
                fprintf(listing, "%-8d "， 1->memloc) ;
                while (t != NULL){ 
                    fprintf(listing, "%4d ", t->lineno);
                    t = t->next;
                }

                fprintf (listing, " \n");
                1 = 1->next;
            }
        }
    }

}

