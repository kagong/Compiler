############### Data segment ###############
.data
newline: .asciiz "\n"
input_prompt: .asciiz "Enter value for IN instruction : "
output_prompt: .asciiz "OUT instruction prints : "
############### Code segment ###############
.text
addi $t1, $zero, 1
sll $t1, $t1, 31

minloc:
#FuncK Return Address Save
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
#FuncK Parameter
#ParamK a
#ParamK low
#ParamK high
#FuncK Statements
#CompoundK Declarations
#DeclareK INT
addi $sp, $sp, -4
#DeclareK INT
addi $sp, $sp, -4
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK k
addi $sp, $sp, -4
addi $v0, $fp, -16
sw $v0, 0($sp)
#ExpK righthand
#IdK low
lw $v0, 8($fp)
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
#ExpK lefthand
#IdK x
addi $sp, $sp, -4
addi $v0, $fp, -12
sw $v0, 0($sp)
#ExpK righthand
#ArrK a[]
#IdK low
lw $v0, 8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, 12
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
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK low
lw $v0, 8($fp)
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
label0:
#WhileK condition
#ExpK lefthand
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK high
lw $v0, 4($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK <
slt $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label1
#WhileK statement
#CompoundK Declarations
#CompoundK Statements
#IfK condition
#ExpK lefthand
#ArrK a[]
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, 12
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK righthand
#IdK x
lw $v0, -12($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK <
slt $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label2
#IfK then
#CompoundK Declarations
#CompoundK Statements
#ExpK lefthand
#IdK x
addi $sp, $sp, -4
addi $v0, $fp, -12
sw $v0, 0($sp)
#ExpK righthand
#ArrK a[]
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, 12
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
#ExpK lefthand
#IdK k
addi $sp, $sp, -4
addi $v0, $fp, -16
sw $v0, 0($sp)
#ExpK righthand
#IdK i
lw $v0, -8($fp)
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
label2:
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK i
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
beq $zero, $zero, label0
label1:
#ReturnK computation
#IdK k
lw $v0, -16($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ReturnK return seq
lw $t0, 0($sp)
addi $sp, $fp, 0
lw $fp, 0($sp)
lw $ra, -4($sp)
addi $sp, $sp, 16
jr $ra
#FuncK Void Return
lw $ra, -4($fp)
addi $sp, $fp, 0
lw $fp, 0($sp)
addi $sp, $sp, -16
jr $ra

sort:
#FuncK Return Address Save
addi $fp, $sp, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
#FuncK Parameter
#ParamK a
#ParamK low
#ParamK high
#FuncK Statements
#CompoundK Declarations
#DeclareK INT
addi $sp, $sp, -4
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#IdK low
lw $v0, 8($fp)
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
label3:
#WhileK condition
#ExpK lefthand
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK high
lw $v0, 4($fp)
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
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK <
slt $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label4
#WhileK statement
#CompoundK Declarations
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK k
addi $sp, $sp, -4
addi $v0, $fp, -12
sw $v0, 0($sp)
#ExpK righthand
#CallK Argument Computation
#IdK a
addi $sp, $sp, -4
addi $v0, $fp, 12
sw $v0, 0($sp)
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#IdK high
lw $v0, 4($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#CallK Call Sequence
addi $sp, $sp, -4
sw $fp, 0($sp)
jal minloc
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
#IdK t
addi $sp, $sp, -4
addi $v0, $fp, -16
sw $v0, 0($sp)
#ExpK righthand
#ArrK a[]
#IdK k
lw $v0, -12($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, 12
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
#ExpK lefthand
#ArrK a[]
#IdK k
lw $v0, -12($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, 12
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK righthand
#ArrK a[]
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, 12
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
#ExpK lefthand
#ArrK a[]
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, 12
lw $v0, 0($v0)
sw $v0, 0($sp)
#ExpK righthand
#IdK t
lw $v0, -16($fp)
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
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK i
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
beq $zero, $zero, label3
label4:
#FuncK Void Return
lw $ra, -4($fp)
addi $sp, $fp, 0
lw $fp, 0($sp)
addi $sp, $sp, -16
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
#DeclareK INTARR
addi $sp, $sp, -40
#CompoundK Statements
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
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
label5:
#WhileK condition
#ExpK lefthand
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 10
addi $sp, $sp, -4
li $v0, 10
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK <
slt $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label6
#WhileK statement
#CompoundK Declarations
#CompoundK Statements
#ExpK lefthand
#ArrK x[]
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, -48
lw $v0, 0($v0)
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
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK i
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
beq $zero, $zero, label5
label6:
#CallK Argument Computation
#IdK x
addi $sp, $sp, -4
addi $v0, $fp, -48
sw $v0, 0($sp)
#ConstK 0
addi $sp, $sp, -4
li $v0, 0
sw $v0, 0($sp)
#ConstK 10
addi $sp, $sp, -4
li $v0, 10
sw $v0, 0($sp)
#CallK Call Sequence
addi $sp, $sp, -4
sw $fp, 0($sp)
jal sort
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
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
label7:
#WhileK condition
#ExpK lefthand
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 10
addi $sp, $sp, -4
li $v0, 10
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK <
slt $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
addi $sp, $sp, 4
beq $v0, $zero, label8
#WhileK statement
#CompoundK Declarations
#CompoundK Statements
#ArrK x[]
#IdK i
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
lw $v0, 0($sp)
li $v1, 4
mul $v0, $v0, $v1
add, $v0, $v0, $fp
addi, $v0, $v0, -48
lw $v0, 0($v0)
sw $v0, 0($sp)
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
#ExpK lefthand
#IdK i
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK i
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
beq $zero, $zero, label7
label8:
#FuncK Void Return
lw $ra, -4($fp)
addi $sp, $fp, 0
lw $fp, 0($sp)
addi $sp, $sp, -4
jr $ra
