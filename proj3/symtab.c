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
static int hash ( char * key )
{int temp = 0;
    int i = 0;
    while (key[i] 1= ’ \0 ' )
    { temp = ((temp <<SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;


    /* the list of line numbers of the source
     * code in which a var.iable is referenced
     */
    typedef struct LineListRec
    { int lineno;
        struct LineListRec * next;
    } * LineList;

    /* The record in the bucket lists for
     * each variable, including name,
     * assigned ffii없IOry location, and
     * the list of line numbers in which
     * it appears in the source code
     */

    typedef struct BucketListRec
    { char * name;
        LineList lines;
        INY 컴파일러 리스팅 583
            int m얹lloc /* ffii않lOry location for var.iable */
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
        BucketList 1 = hashTable [h] ;
        while ((1 != NULL) && (strcmp(name, l->name) != 이 )
                1 = l->rtext;
                if (1 == NULL 1* γariable not yet in table *1
                    {1 = (BucketList) malloc(sizeof(struct BucketListRec));
                    l->n없ne = n라ne;
                    l->lines = (LineList) malloc(sizeof(struct LineListRec));
                    l->lines->lineno = lineno;
                    l->memloc = loc;
                    l->lines->next = NULL;
                    l->next = hashTable [h] ;
                    hashTable [h] = 1; }
                    else 1* found in table, so just add line number *1
                    {LineList t = l->lines;
                    while (t->next != NULL) t = t->next;
                    t->next = (LineList) malloc(sizeof(struct LineListRec));
                    t->next->lineno = linenò;
                    t->next->next = NULL;

                    } 
                    int st_lookup ( char * n없le )
                    {int h = hash(name);
                    BucketList 1 = hashTable[h];
                    while ((1 != NULL) && (strcmp(name, l->name) != 0))
                        1 = l->next;
                    if (1 == NULL) return -1;
                    else return l->memloc;


                    void printsymTab(FILE * listing)
                    {int i;
                        fprintf(listing, "Variable Name Location Line Numbers\n") ;
                        fprintf(listing, ,,"------------- -------'-----\n") ;
                        for (i=Ð;i<SIZE;++i)
                        { if (hashTable[i] !=NULL)
                            { BucketList 1 = hashTable[i];
                                while (1 != NULL)
                                { LineList t = l->lines;
                                    fprintf (listing, "%-14s ", l->name);
                                    fprintf(listing, "%-8d "， l->m<없tloc) ;
                                    while (t 1= NULL)
                                    { fprintf(listing, "%4d ", t->lineno);
                                        t ~ t~>next;

                                        fprintf (listing, " \n");
                                        1 = l->next;

                                    }

