.data
newline: .asciiz "\n"
output_str: .asciiz "Output : "
input_str: .asciiz "Input : "

.text
.align 4
.globl main
	li $sp, 0x7fffffff
	li $fp, 0x7fffffff
	li $gp, 0x10000000
main :
	subiu $sp, $sp, 4
	sw $fp, 0($sp)
	add $fp, $sp, $zero
	subiu $sp, $sp, 4
	sw $ra, -4($sp)
	subiu $sp, $sp, 4
	li $t0, 1
	sw $t0, -8($$gp)

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
	li $v0, 4
	la $a0, newline
	syscall
L1:
	add $sp, $fp, $zero
	addiu $sp, $sp, 4
	lw $ra, -4($fp)
	lw $fp, 0($fp)
	jr $ra
