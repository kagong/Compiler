#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
static int hash ( char * key ){
    int temp = 0;
    int i = 0;
    while (key[i] != '\0' )
    { temp = ((temp <<SHIFT) + key[i]) % SIZE;
        ++i;
    }
    return temp;
}

void insert_scope(){
		ScopeList tmp = (ScopeList)malloc(sizeof(struct ScopeListRec));
		for(int i=0;i<SIZE;i++) tmp->bucket[i]=NULL;
		tmp->level = scope;
		tmp->valid = TRUE;
		tmp->next = total_sym;
		total_sym = tmp;
}
void st_insert ( char * name, int lineno, int loc, isvpf vpf,int isarr, int arrsize,type_rec type,int isglobal)
{
		if(isglobal == TRUE) ScopeList temp = global_sym;
		else ScopeList temp = total_sym; 
		int h = hash(name);

		while(temp!=NULL && temp->valid == TRUE){
				BucketList l = (temp->bucket)[h];
				while ((l != NULL) && (strcmp(name, l->name) != 0) )
						l = l->next;
				if(l != NULL) break;
		}
		if (l == NULL){//new node
				l = (BucketList) malloc(sizeof(struct BucketListRec));
				l->name = name;
				l->lines = (LineList) malloc(sizeof(struct LineListRec));
				l->lines->lineno = lineno;
				l->lines->next = NULL;
				l->memloc = loc;
				l->vpf = vpf;
				l->isarr = isarr;
				l->arrsize = arrsize;
				l->type = type;
				l->next = bucket[h] ;
				bucket[h] = l; 
		}
		else{//only insert lineno
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
		ScopeList tmp = total_sym;
		while(tmp != NULL && tmp->valid == TRUE){
				BucketList l = (tmp->bucket)[h];
				while ((l != NULL) && (strcmp(name, l->name) != 0))
						l = l->next;
				if(l != NULL)
						break;
		}
		tmp = tmp ->next;
}
if (tmp == NULL) return -1;
else return l->memloc;
}

//get_treenode()
void printsymTab(FILE * listing){
		int i;
		fprintf(listing, "Name\tScope\tLoc\tV/P/F\tArray?\tArrSize\tType\tLine Numbers\n") ;
		fprintf(listing, "----------------------------------------------------------------------\n") ;
		ScopeList tmp = total_sym;
		int sc;
		while(tmp!=NULL){
				sc = tmp->level;
				for (i=0;i<SIZE;++i){ 
						if (tmp->bucket[i] !=NULL){ 
								BucketList l = tmp->bucket[i];
								while (l != NULL){ 
										LineList t = l->lines;
										fprintf (listing, "%-8s ", l->name);
										fprintf(listing,"%-8d ", sc);
										fprintf(listing, "%-8d ",l->memloc) ;
										fprintf(listing,"%-8s ",vpf_string[l->vpf]);
										fprintf(listing,"%-8s ",(l->isarr) ? "Array" : "No");
										if(l->isarr) fprintf(listing,"%-8d ",l->arrsize);
										else fprintf(listing,"%-8s ","-");
										fprintf(listing,"%-8s ",type_string[l->type]);
										
										while (t != NULL){ 
												fprintf(listing, "%4d ", t->lineno);
												t = t->next;
										}

										fprintf (listing, " \n");
										l = l->next;
								}
						}
				}
				tmp = tmp->next;
		}

}

