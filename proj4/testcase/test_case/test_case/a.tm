.data
newline: .asciiz "\n"
output_str: .asciiz "Output : "
input_str: .asciiz "Input : "

.text
.align 4
.globl main
main :
	addi $sp, $sp, -4
	sw $fp, 0($sp)
	add $fp, $sp, $zero
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	addi $sp, $sp, -4
	addi $sp, $sp, -4
	addi $sp, $sp, -4
	addi $sp, $sp, -4
	li $t0, 1
	sw $t0, -8($fp)
	li $t0, 2
	sw $t0, -12($fp)
	li $t0, 3
	sw $t0, -16($fp)
	li $t0, 4
	sw $t0, -20($fp)

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk a
	lw $t0,-8($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk a
	lw $t0,-8($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	lw $t1,0($sp)
	sub $t0,$t1,$t0
	addiu $sp, $sp, 4
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk d
	lw $t0,-20($fp)
#this idk a
#<-idk d
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	lw $t1,0($sp)
	div $t0,$t1,$t0
	addiu $sp, $sp, 4
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk d
	lw $t0,-20($fp)
#this idk a
#<-idk d
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	lw $t1,0($sp)
	mul $t0,$t1,$t0
	addiu $sp, $sp, 4
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall
#->idk a
	lw $t0,-8($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk c
	lw $t0,-16($fp)
#this idk a
#<-idk c
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk d
	lw $t0,-20($fp)
#this idk a
#<-idk d
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 5
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 6
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 7
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 8
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 9
	lw $t1,0($sp)
	mul $t0,$t1,$t0
	addiu $sp, $sp, 4
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -8($fp)

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk a
	lw $t0,-8($fp)
#this idk a
#<-idk a
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall
#->idk c
	lw $t0,-16($fp)
#this idk a
#<-idk c
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk d
	lw $t0,-20($fp)
#this idk a
#<-idk d
	lw $t1,0($sp)
	mul $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	lw $t1,0($sp)
	sub $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -12($fp)

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall
#->idk d
	lw $t0,-20($fp)
#this idk a
#<-idk d
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk c
	lw $t0,-16($fp)
#this idk a
#<-idk c
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	sub $t0,$t1,$t0
	addiu $sp, $sp, 4
	lw $t1,0($sp)
	div $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -16($fp)

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk c
	lw $t0,-16($fp)
#this idk a
#<-idk c
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall
#->idk a
	lw $t0,-8($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk b
	lw $t0,-12($fp)
#this idk a
#<-idk b
	lw $t1,0($sp)
	div $t0,$t1,$t0
	addiu $sp, $sp, 4
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk c
	lw $t0,-16($fp)
#this idk a
#<-idk c
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk c
	lw $t0,-16($fp)
#this idk a
#<-idk c
	lw $t1,0($sp)
	mul $t0,$t1,$t0
	addiu $sp, $sp, 4
	lw $t1,0($sp)
	sub $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -20($fp)

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk d
	lw $t0,-20($fp)
#this idk a
#<-idk d
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall
L1:
	add $sp, $fp, $zero
	addiu $sp, $sp, 4
	lw $ra, -4($fp)
	lw $fp, 0($fp)
	j $ra
