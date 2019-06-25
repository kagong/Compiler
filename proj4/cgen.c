#include "globals.h"
#include "cgen.h"

#define WORD 4
int end_label = 0;
static int allocate_label(){
    static int label=0;
    return ++label;
}
static void genExp( TreeNode * tree);
static void cGen( TreeNode * tree);
static void genDec(TreeNode * tree){
    TreeNode *p1, *p2, *p3;
    int savedLoc1, savedLoc2, currentLoc;
    int loc;
    unsigned int count = 0;
    int len;
    TreeNode *temp = NULL;
    switch(tree->kind.decl){//stack 에 알규먼트 저장해주세여
        case FunK:
            temp = p1;
            while(temp == NULL){
                ++count;
                temp = temp -> sibling;
            }
            fprintf(code,"%s :\n",tree->attr.decl.name);
            fprintf(code,"\tsubiu $sp, $sp, %d\n",WORD);//control link
            fprintf(code,"\tsw $fp, %d($sp)\n",0);
            fprintf(code,"\tadd $fp, $sp, $zero\n");
            fprintf(code,"\tsubiu $sp, $sp, %d\n",WORD);//return address
            fprintf(code,"\tsw $ra, %d($sp)\n",-WORD);
            cGen(p2);

            end_label= allocate_label();
            fprintf(code,"L%d:\n",end_label);
            fprintf(code,"\tadd $sp, $fp, $zero\n");
            fprintf(code,"\taddiu $sp, $sp, %d\n",(count+1)*WORD);
            fprintf(code,"\tlw $ra, %d($fp)\n",-WORD);
            fprintf(code,"\tlw $fp, %d($fp)\n",0);
            fprintf(code,"\tjr $ra\n");

            break;
        case VarK:
            if(tree -> isglobal != 1)
                fprintf(code,"\tsubiu $sp, $sp, %d\n",WORD);
            //   fprintf(code,"\tsw $zero, %d($fp)\n",tree->loc);
            break;
        case VarArrK:
            len = tree -> attr.decl.arr_size;
            if(tree -> isglobal != 1)
                fprintf(code,"\tsubiu $sp, $sp, %d\n",WORD*len);
            // for(inti i=0;i<len;i++)
            //   fprintf(code,"\tsw $zero, %d($fp)\n",tree->loc+i*WORD);
            break;
        case ParaK:
            break;
    }
}
static void genStmt(TreeNode * tree){
    TreeNode *p1 = tree -> child[0] , *p2 = tree -> child[1] , *p3 = tree ->child [2];
    TreeNode *temp = NULL;
    int label_num1, label_num2;
    switch(tree->kind.stmt){
        case FompndK:
        case CompndK:
            cGen(p1);
            cGen(p2);
            break;
        case SelcK:
            cGen(p1);
            label_num1 = allocate_label();
            fprintf(code,"\tbeqz $t0, L%d\n",label_num1);
            cGen(p2);
            if(p3 != NULL){
                label_num2 = allocate_label();
                fprintf(code,"\tb L%d\n",label_num2);
                fprintf(code,"L%d:\n",label_num1);
                cGen(p3);
                fprintf(code,"L%d:\n",label_num2);
            }
            else
                fprintf(code,"L%d:\n",label_num1);

            break;
        case IterK:
            label_num1 = allocate_label();
            label_num2 = allocate_label();
            fprintf(code,"L%d:\n",label_num1);
            cGen(p1);
            fprintf(code,"\tbeqz $t0, L%d\n",label_num2);
            cGen(p2);
            fprintf(code,"\tb L%d\n",label_num1);
            fprintf(code,"L%d:\n",label_num2);
            break;
        case RetK:
            cGen(p1);
            fprintf(code,"\taddi $a0, $t0, 0\n");
            fprintf(code,"\tb L%d\n",end_label);
            break;
        case CallK:

			if (!strcmp(tree->attr.decl.name, "input"))
            {
              fprintf(code, "\n# input\n");
              fprintf(code, "li $v0, 4\n");
              fprintf(code, "la $a0, input_str\n");
              fprintf(code, "syscall\n");
              fprintf(code, "li $v0, 5\n");
              fprintf(code, "syscall\n");
              fprintf(code, "move $t0, $v0\n");
            
            }            
			else if (!strcmp(tree->attr.decl.name, "output"))
            {
                fprintf(code, "\n# output\n");
                fprintf(code, "move $t0, $v0\n");
                fprintf(code, "li $v0, 4\n");
                fprintf(code, "la $a0, output_str\n");
                fprintf(code, "syscall\n");
                fprintf(code, "move $v0, $t0\n");
                temp = p1;
                while(temp != NULL){
                    genExp(temp);
                    fprintf(code, "move $a0, $t0\n"); // the argument
                    fprintf(code, "li $v0, 1\n");
                    fprintf(code, "syscall\n");
                }
                
                // print newline
                fprintf(code, "li $v0, 4\n");
                fprintf(code, "la $a0, newline\n");
                fprintf(code, "syscall\n");

            }
            else{
                temp = tree -> child[0];
                while(temp != NULL){
                    genExp(temp);
                    fprintf(code,"\tsubiu $sp, $sp, %d\n",WORD);//return address
                    fprintf(code,"\tsw $t0, %d($sp)\n",0);
                    temp = temp -> sibling;
                }
                fprintf(code,"\tjal %s\n",tree->attr.decl.name);
                fprintf(code,"\tadd $t0 ,$a0, $zero\n");
            }
            break;
        default:
            break;
    }
} /* genStmt */

/* procedure genExp generates codeat an expression node */
static void genExp( TreeNode * tree){
    int loc;
    TreeNode *p1 = tree->child[0], *p2 = tree->child[1];
    switch (tree->kind.exp){
        case ConstK:
            fprintf(code,"\tli $t0, %d\n",tree->attr.val);
            break;
        case IdK:
			if(p1){
				cGen(p1);
				fprintf(code,"\tli $t2, 4\n");
				fprintf(code,"\tmul $t2,$t2,$t0\n");
				fprintf(code,"\tla $t1, %d(%s)\n",tree->loc, tree->isglobal ? "$gp" : "$fp");
				fprintf(code,"\tadd $t1,$t1,$t2\n");
				fprintf(code,"\tlw $t0,%d($t1)\n",0);	
			}
			else{
				fprintf(code,"\tlw $t0,%d($fp)\n",tree->loc);
			}
			break;
        case OpK:
			if(tree->attr.op == ASSIGN){
				cGen(p2);
				if(p1->child[0]){
                    //a[i] = 3
					fprintf(code,"\tadd $t3, $t0, $zero\n");//t3 = 3
					cGen(p1->child[0]);
					fprintf(code,"\tli $t2, 4\n");          //t2 = word size
					fprintf(code,"\tmul $t2,$t2,$t0\n");    //t2 = i
					fprintf(code,"\taddi $t1, %s, %d\n", p1->isglobal== 1 ? "$gp" : "$fp",p1->loc);    //t1 = a
					fprintf(code,"\tadd $t1,$t1,$t2\n");        //t1 = a + i
					fprintf(code,"\tsw $t3, %d($t1)\n",0);
				}
				else fprintf(code,"\tsw %d($fp),$t0\n",tree->child[0]->loc);
			}
			else{
				cGen(p1);
				fprintf(code,"\tsubiu $sp, $sp, %d\n",WORD);
				fprintf(code,"\tsw $t0,%d($sp)\n",0);
				cGen(p2);
				fprintf(code,"\tlw $t1,%d($sp)\n",0);
				switch(tree->attr.op){
					case PLUS :
						fprintf(code,"\tadd $t0,$t1,$t0\n");
						break;
					case MINUS :
						fprintf(code,"\tsub $t0,$t1,$t0\n");
						break;
					case TIMES :
						fprintf(code,"\tmul $t0,$t1,$t0\n");
						break;
					case OVER :
						fprintf(code,"\tdiv $t0,$t1,$t0\n");
						break;
					case LT :
						fprintf(code,"\tslt $t0,$t1,$t0\n");
						break;
					case LET :
						fprintf(code,"\tsle $t0,$t1,$t0\n");
						break;
					case GT :
						fprintf(code,"\tsgt $t0,$t1,$t0\n");
						break;
					case GET :
						fprintf(code,"\tsge $t0,$t1,$t0\n");
						break;
					case EQ :
						fprintf(code,"\tseq $t0,$t1,$t0\n");
						break;
					case NEQ :
						fprintf(code,"\tsne $t0,$t1,$t0\n");
						break;
					default :
						break;
				}
				fprintf(code,"\taddiu $sp, $sp, %d\n",WORD);
				break;
			}
        default:
            break;
    }
} /* genExp */

/* procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen( TreeNode * tree){
    if (tree != NULL){ 
        switch (tree->nodekind){
            case DeclK:
                genDec(tree);
                break;
            case StmtK:
                genStmt(tree);
                break;
            case ExpK:
                genExp(tree);
                break;
            default:
                break;
        }
        cGen(tree->sibling);
    }
}

/***********************************************/
/* the primary function of the code generator */
/***********************************************/
/* procedure codeGen generates code to a code
 * file by traversal of .the syntax tree. The
 * second parameter (codéfile) is the file name
 * of the code file, and is used to print the
 * file name as a comment in the code file
 */
void codeGen(TreeNode * syntaxTree, char * codefile){
    char* s = malloc(strlen(codefile)+7);
    strcpy(s, "File: ");
    strcat(s,codefile);

    //datas for print 
    fprintf(code, ".data\n");
    fprintf(code, "newline: .asciiz \"\\n\"\n");
    fprintf(code, "output_str: .asciiz \"Output : \"\n");
    fprintf(code, "input_str: .asciiz \"Input : \"\n");

	fprintf(code, "\n.text\n");
	fprintf(code, ".align 4\n");
	fprintf(code, ".globl main\n");
	//initialize
	fprintf(code, "li $sp, 0x7fffffff");
	fprintf(code, "li $fp, 0x7fffffff");
	fprintf(code, "li $gp, 0x10000000");
	
	cGen(syntaxTree);
}

