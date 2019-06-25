############### Data segment ###############
.data
newline: .asciiz "\n"
input_prompt: .asciiz "Enter value for IN instruction : "
output_prompt: .asciiz "OUT instruction prints : "
############### Code segment ###############
.text
addi $t1, $zero, 1
sll $t1, $t1, 31

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
#DeclareK INT
addi $sp, $sp, -4
#DeclareK INT
addi $sp, $sp, -4
#DeclareK INT
addi $sp, $sp, -4
#CompoundK Statements
#ExpK lefthand
#IdK a
addi $sp, $sp, -4
addi $v0, $fp, -8
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
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#ExpK lefthand
#IdK b
addi $sp, $sp, -4
addi $v0, $fp, -12
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
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#ExpK lefthand
#IdK c
addi $sp, $sp, -4
addi $v0, $fp, -16
sw $v0, 0($sp)
#ExpK righthand
#ConstK 3
addi $sp, $sp, -4
li $v0, 3
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
#IdK d
addi $sp, $sp, -4
addi $v0, $fp, -20
sw $v0, 0($sp)
#ExpK righthand
#ConstK 4
addi $sp, $sp, -4
li $v0, 4
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
#IdK a
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK b
lw $v0, -12($fp)
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
#IdK a
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK b
lw $v0, -12($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK -
sub $v0, $v0, $v1
addi $sp, $sp, -4
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
#IdK d
lw $v0, -20($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK b
lw $v0, -12($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK /
div $v0, $v0, $v1
addi $sp, $sp, -4
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
#IdK d
lw $v0, -20($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK b
lw $v0, -12($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK *
mul $v0, $v0, $v1
addi $sp, $sp, -4
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
#IdK a
addi $sp, $sp, -4
addi $v0, $fp, -8
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#ExpK lefthand
#ExpK lefthand
#ExpK lefthand
#IdK a
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK b
lw $v0, -12($fp)
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
#ExpK righthand
#ExpK lefthand
#ExpK lefthand
#ExpK lefthand
#IdK c
lw $v0, -16($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK d
lw $v0, -20($fp)
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
#ExpK righthand
#ConstK 5
addi $sp, $sp, -4
li $v0, 5
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK +
add $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 6
addi $sp, $sp, -4
li $v0, 6
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
#ExpK +
add $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ConstK 7
addi $sp, $sp, -4
li $v0, 7
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK +
add $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#ConstK 8
addi $sp, $sp, -4
li $v0, 8
sw $v0, 0($sp)
#ExpK righthand
#ConstK 9
addi $sp, $sp, -4
li $v0, 9
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK *
mul $v0, $v0, $v1
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
#IdK a
lw $v0, -8($fp)
addi $sp, $sp, -4
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
#IdK b
addi $sp, $sp, -4
addi $v0, $fp, -12
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#ExpK lefthand
#IdK c
lw $v0, -16($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK d
lw $v0, -20($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK *
mul $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK b
lw $v0, -12($fp)
addi $sp, $sp, -4
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
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#IdK b
lw $v0, -12($fp)
addi $sp, $sp, -4
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
#IdK c
addi $sp, $sp, -4
addi $v0, $fp, -16
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK d
lw $v0, -20($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK c
lw $v0, -16($fp)
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
#ExpK /
div $v0, $v0, $v1
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
#IdK c
lw $v0, -16($fp)
addi $sp, $sp, -4
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
#IdK d
addi $sp, $sp, -4
addi $v0, $fp, -20
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#ExpK lefthand
#IdK a
lw $v0, -8($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK b
lw $v0, -12($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK /
div $v0, $v0, $v1
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#ExpK lefthand
#IdK c
lw $v0, -16($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK righthand
#IdK c
lw $v0, -16($fp)
addi $sp, $sp, -4
sw $v0, 0($sp)
#ExpK operation
lw $v1, 0($sp)
lw $v0, 4($sp)
addi $sp, $sp, 8
#ExpK *
mul $v0, $v0, $v1
addi $sp, $sp, -4
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
#ExpK =
sw $v1, 0($v0)
addi $sp, $sp, -4
sw $v1, 0($sp)
#IdK d
lw $v0, -20($fp)
addi $sp, $sp, -4
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
#FuncK Void Return
lw $ra, -4($fp)
addi $sp, $fp, 0
lw $fp, 0($sp)
addi $sp, $sp, -4
jr $ra
