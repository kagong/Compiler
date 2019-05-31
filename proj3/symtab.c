#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */

const char* type_string[4] = {"","Void","Int","Array"};
const char* vpf_string[3] = {"Var","Func","Par"};
void insert_scope(int scope){
    ScopeList tmp = (ScopeList)malloc(sizeof(struct ScopeListRec));
    for(int i=0;i<SIZE;i++) tmp->bucket[i]=NULL;
    tmp->level = scope;
    tmp->valid = TRUE;
    tmp->next = total_sym;
    total_sym = tmp;
}
void st_insert ( char * name, int lineno, int loc, isvpf vpf,int isarr, int arrsize,Type type,int isglobal,int isdec, TreeNode *node)
{
    ScopeList temp,sym;
    if(isglobal == TRUE) sym = global_sym;
    else sym = total_sym; 
    temp = sym;
    int h = hash(name);
    BucketList l;
    if(isdec){
        l = (temp->bucket)[h];
        while((l != NULL) && (strcmp(name, l->name) != 0)) l = l->next;
    }
    else{
        while(temp!=NULL){
            if(temp->valid == FALSE){
                temp = temp->next;
                continue;
            }
            l = (temp->bucket)[h];
            while ((l != NULL) && (strcmp(name, l->name) != 0) )
                l = l->next;
            if(l != NULL) break;
            temp = temp ->next;
        }
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
        l->next = (sym->bucket)[h] ;
        l->node = node;
        (sym->bucket)[h] = l; 
    }
    else{//only insert lineno
        LineList t = l->lines;
        while (t->next != NULL) 
            t = t->next;
        if(t->lineno != lineno){
            t->next = (LineList) malloc(sizeof(struct LineListRec));
            t->next->lineno = lineno;
            t->next->next = NULL;
        }
    }

}
int st_lookup_func(char * name){
	int h = hash(name);
	ScopeList tmp = global_sym;
	BucketList l;
	l = (tmp->bucket)[h];
	while((l != NULL) && (strcmp(name, l->name) != 0)) l = l->next;
	return l == NULL ? -1 : 1;
}
int st_lookup ( char * name, int isdec ){
    int h = hash(name);
    ScopeList tmp = total_sym;
    BucketList l; 
    if(isdec){
        l = (tmp->bucket)[h];
        while((l != NULL) && (strcmp(name, l->name) != 0)) l = l->next;
        return l == NULL ? -1 : 1;
    }
    else{
        while(tmp != NULL){
            if(tmp->valid == FALSE){
                tmp = tmp->next;
                continue;
            }
            l = (tmp->bucket)[h];
            while ((l != NULL) && (strcmp(name, l->name) != 0)){
                l = l->next; 
            }
            if(l != NULL)
                break;
            tmp = tmp ->next;
        }
    }
    if (tmp == NULL) return -1;
    else return l->memloc;
}
TreeNode* st_getnode ( char * name){
    int h = hash(name);
    ScopeList tmp = total_sym;
    BucketList l; 
    while(tmp != NULL){
        if(tmp->valid == FALSE){
            tmp = tmp->next;
            continue;
        }
        l = (tmp->bucket)[h];
        while ((l != NULL) && (strcmp(name, l->name) != 0)){
            l = l->next; 
        }
        if(l != NULL)
            break;
        tmp = tmp ->next;
    }
    if (tmp == NULL) return NULL;
    else return l->node;
}

//get_treenode()
void printSymTab(FILE * listing){
    int i;
    ScopeList tmp = total_sym;
    int sc;
    while(tmp!=NULL){
        sc = tmp->level;
        fprintf(listing, "\n\nName\tScope\tLoc\tV/P/F\tArray?\tArrSize\tType\tLine Numbers\n") ;
        fprintf(listing, "----------------------------------------------------------------------\n") ;

        for (i=0;i<SIZE;++i){ 
            if (tmp->bucket[i] !=NULL){ 
                BucketList l = tmp->bucket[i];
                while (l != NULL){ 
                    LineList t = l->lines;
                    fprintf (listing, "%-8s ", l->name);
                    fprintf(listing,"%-6d ", sc);
                    fprintf(listing, "%-7d ",l->memloc) ;
                    fprintf(listing,"%-7s ",vpf_string[l->vpf]);
                    fprintf(listing,"%-8s ",(l->isarr) ? "Array" : "No");
                    if(l->isarr) fprintf(listing,"%-6d ",l->arrsize);
                    else fprintf(listing,"%-6s ","-");
                    fprintf(listing,"%-5s ",(l->isarr) ? "array" : type_string[l->type]);

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

