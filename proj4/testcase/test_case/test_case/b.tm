.data
newline: .asciiz "\n"
output_str: .asciiz "Output : "
input_str: .asciiz "Input : "

.text
.align 4
.globl main
fibonacci :
	addi $sp, $sp, -4
	sw $fp, 0($sp)
	add $fp, $sp, $zero
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	addi $sp, $sp, -4
#->idk a
	lw $t0,4($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 0
	lw $t1,0($sp)
	sle $t0,$t1,$t0
	addiu $sp, $sp, 4
	beqz $t0, L2
	li $t0, 0
	sw $t0, -8($fp)
	b L3
L2:
#->idk a
	lw $t0,4($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 2
	lw $t1,0($sp)
	sle $t0,$t1,$t0
	addiu $sp, $sp, 4
	beqz $t0, L4
	li $t0, 1
	sw $t0, -8($fp)
	b L5
L4:
#->idk a
	lw $t0,4($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	sub $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	jal fibonacci
	add $t0 ,$a0, $zero
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk a
	lw $t0,4($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 2
	lw $t1,0($sp)
	sub $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	jal fibonacci
	add $t0 ,$a0, $zero
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -8($fp)
L5:
L3:
#->idk ret
	lw $t0,-8($fp)
#this idk a
#<-idk ret
	addi $a0, $t0, 0
	b L1
#return
L1:
	add $sp, $fp, $zero
	addiu $sp, $sp, 8
	lw $ra, -4($fp)
	lw $fp, 0($fp)
	j $ra
main :
	addi $sp, $sp, -4
	sw $fp, 0($sp)
	add $fp, $sp, $zero
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	addi $sp, $sp, -4

	# input
	li $v0, 4
	la $a0, input_str
	syscall
	li $v0, 5
	syscall
	move $t0, $v0
	sw $t0, -8($fp)

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall
L6:
	add $sp, $fp, $zero
	addiu $sp, $sp, 4
	lw $ra, -4($fp)
	lw $fp, 0($fp)
	j $ra
