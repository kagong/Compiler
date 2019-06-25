############### Data segment ###############
.data
newline: .asciiz "\n"
input_prompt: .asciiz "Enter value for IN instruction : "
output_prompt: .asciiz "OUT instruction prints : "
############### Code segment ###############
.text
addi $t1, $zero, 1
sll $t1, $t1, 31
#DeclareK INTARR

fibonacci:
#FuncK Return Address Save
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
#FuncK Parameter
#ParamK a
#FuncK Statements
#CompoundK Declarations
#CompoundK Statements
#IfK condition
#ExpK lefthand
#IdK a
lw $v0, 4($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 0
addi $sp, $sp, -4
li $v0, 0
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK <=
sle $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label0
#IfK then
#ReturnK computation
#ConstK 0
addi $sp, $sp, -4
li $v0, 0
sw $v0, 0($sp)
#ReturnK return seq
lw $t0, 0($sp)
addi $sp, $fp, 0
lw $fp, 0($sp)
lw $ra, -4($sp)
addi $sp, $sp, 8
jr $ra
beq $zero, $zero, label1
label0:
#IfK else
#IfK condition
#ExpK lefthand
#IdK a
lw $v0, 4($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 2
addi $sp, $sp, -4
li $v0, 2
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK <=
sle $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label2
#IfK then
#ReturnK computation
#ConstK 1
addi $sp, $sp, -4
li $v0, 1
sw $v0, 0($sp)
#ReturnK return seq
lw $t0, 0($sp)
addi $sp, $fp, 0
lw $fp, 0($sp)
lw $ra, -4($sp)
addi $sp, $sp, 8
jr $ra
label2:
label1:
#CompoundK Declarations
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK k
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#IdK a
lw $v0, 4($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#CompoundK Declarations
#DeclareK INTARR
addi $sp, $sp, -40
#CompoundK Statements
#ExpK lefthand
#ArrK y[]
#ConstK 5
addi $sp, $sp, -4
li $v0, 5
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, -48
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK righthand
#ConstK 0
addi $sp, $sp, -4
li $v0, 0
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#IfK condition
#ExpK lefthand
#ArrK save[]
#IdK k
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $t1
addi, $v0, $v0, 4004
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK righthand
#ArrK y[]
#ConstK 5
addi $sp, $sp, -4
li $v0, 5
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, -48
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK !=
sne $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label3
#IfK then
#ReturnK computation
#ArrK save[]
#IdK k
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $t1
addi, $v0, $v0, 4004
lw $v0, 0($v0)
sw $v0, 0($sp)
#ReturnK return seq
lw $t0, 0($sp)
addi $sp, $fp, 0
lw $fp, 0($sp)
lw $ra, -4($sp)
addi $sp, $sp, 8
jr $ra
label3:
#CompoundK Declarations
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK h
addi $sp, $sp, -4
addi $v0, $fp, -52
sw $v0, 0($sp)
#ExpK righthand
#CallK Argument Computation
#ExpK lefthand
#IdK k
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 1
addi $sp, $sp, -4
li $v0, 1
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK -
sub $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#CallK Call Sequence
addi $sp, $sp, -4
sw $fp, 0($sp)
jal fibonacci
addi $sp, $sp, -4
sw $t0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#CompoundK Declarations
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK g
addi $sp, $sp, -4
addi $v0, $fp, -56
sw $v0, 0($sp)
#ExpK righthand
#CallK Argument Computation
#ExpK lefthand
#IdK k
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 2
addi $sp, $sp, -4
li $v0, 2
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK -
sub $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#CallK Call Sequence
addi $sp, $sp, -4
sw $fp, 0($sp)
jal fibonacci
addi $sp, $sp, -4
sw $t0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#ExpK lefthand
#ArrK save[]
#IdK a
lw $v0, 4($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $t1
addi, $v0, $v0, 4004
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK h
lw $v0, -52($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK g
lw $v0, -56($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK +
add $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#CompoundK Declarations
#DeclareK INTARR
addi $sp, $sp, -1600
#CompoundK Statements
#ExpK lefthand
#ArrK aaa[]
#ConstK 333
addi $sp, $sp, -4
li $v0, 333
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, -1656
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK righthand
#ArrK save[]
#IdK a
lw $v0, 4($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $t1
addi, $v0, $v0, 4004
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#ReturnK computation
#ArrK aaa[]
#ConstK 333
addi $sp, $sp, -4
li $v0, 333
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, -1656
lw $v0, 0($v0)
sw $v0, 0($sp)
#ReturnK return seq
lw $t0, 0($sp)
addi $sp, $fp, 0
lw $fp, 0($sp)
lw $ra, -4($sp)
addi $sp, $sp, 8
jr $ra
#FuncK Void Return
lw $ra, -4($fp)
addi $sp, $fp, 0
lw $fp, 0($sp)
addi $sp, $sp, -8
jr $ra

main:
#FuncK Return Address Save
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
#FuncK Parameter
#FuncK Statements
#CompoundK Declarations
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK ret
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#input prompt
li $v0, 4
la $a0, input_prompt
syscall
#read int
li $v0, 5
syscall
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#CallK Argument Computation
#IdK ret
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#CallK Call Sequence
addi $sp, $sp, -4
sw $fp, 0($sp)
jal fibonacci
addi $sp, $sp, -4
sw $t0, 0($sp)
#output prompt
li $v0, 4
la $a0, output_prompt
syscall

#print int
lw $a0, 0($sp)
addi $sp, $sp, 4
li $v0, 1
syscall
li $v0, 4
la $a0, newline
syscall
#FuncK Void Return
lw $ra, -4($fp)
addi $sp, $fp, 0
lw $fp, 0($sp)
addi $sp, $sp, -4
jr $ra
