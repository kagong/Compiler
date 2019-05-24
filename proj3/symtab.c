#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function */
#define SHIFT 4

/* procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert ( char * name, int lineno, int loc )
{
    int h = hash(name);
    BucketList l = hashTable[h] ;
    while ((l != NULL) && (strcmp(name, l->name) != 0) )
        l = l->next;
    if (l == NULL){
        l = (BucketList) malloc(sizeof(struct BucketListRec));
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
int st_lookup ( char * name ){
    int h = hash(name);
    BucketList l = hashTable[h];
    while ((l != NULL) && (strcmp(name, l->name) != 0))
        l = l->next;
    if (l == NULL) return -1;
    else return l->memloc;
}
void printsymTab(FILE * listing){
    int i;
    fprintf(listing, "Variable Name Location Line Numbers\n") ;
    fprintf(listing, "------------- -------'-----\n") ;
    for (i=0;i<SIZE;++i){ 
        if (hashTable[i] !=NULL){ 
            BucketList l = hashTable[i];
            while (l != NULL){ 
                LineList t = l->lines;
                fprintf (listing, "%-14s ", l->name);
                fprintf(listing, "%-8d ",l->memloc) ;
                while (t != NULL){ 
                    fprintf(listing, "%4d ", t->lineno);
                    t = t->next;
                }

                fprintf (listing, " \n");
                l = l->next;
            }
        }
    }

}

