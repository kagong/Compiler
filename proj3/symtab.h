#ifndef _SYMTAB_H_
#define _SYMTAB_H_
/* procedure st_insert inserts 1ine numbers and
* IlIi태~ry 10cations into the symbo1 tab1e
* 10c = memory 10cation is inserted on1y the
* first time, otherwise ignored
*/
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
