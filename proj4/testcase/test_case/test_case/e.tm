.data
newline: .asciiz "\n"
output_str: .asciiz "Output : "
input_str: .asciiz "Input : "

.text
.align 4
.globl main
minloc :
	addi $sp, $sp, -4
	sw $fp, 0($sp)
	add $fp, $sp, $zero
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	addi $sp, $sp, -4
	addi $sp, $sp, -4
	addi $sp, $sp, -4
#->idk low
	lw $t0,8($fp)
#this idk a
#<-idk low
	sw $t0, -16($fp)
#->idk a
#->idk low
	lw $t0,8($fp)
#this idk a
#<-idk low
	li $t2, 4
	mul $t2,$t2,$t0
	lw $t1, 12($fp)
	la $t1, 0($t1)
#this idk a[i]
	add $t1,$t1,$t2
	lw $t0,0($t1)
#<-idk a
	sw $t0, -12($fp)
#->idk low
	lw $t0,8($fp)
#this idk a
#<-idk low
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -8($fp)
L2:
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk high
	lw $t0,4($fp)
#this idk a
#<-idk high
	lw $t1,0($sp)
	slt $t0,$t1,$t0
	addiu $sp, $sp, 4
	beqz $t0, L3
#->idk a
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	li $t2, 4
	mul $t2,$t2,$t0
	lw $t1, 12($fp)
	la $t1, 0($t1)
#this idk a[i]
	add $t1,$t1,$t2
	lw $t0,0($t1)
#<-idk a
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk x
	lw $t0,-12($fp)
#this idk a
#<-idk x
	lw $t1,0($sp)
	slt $t0,$t1,$t0
	addiu $sp, $sp, 4
	beqz $t0, L4
#->idk a
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	li $t2, 4
	mul $t2,$t2,$t0
	lw $t1, 12($fp)
	la $t1, 0($t1)
#this idk a[i]
	add $t1,$t1,$t2
	lw $t0,0($t1)
#<-idk a
	sw $t0, -12($fp)
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	sw $t0, -16($fp)
L4:
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -8($fp)
	b L2
L3:
#->idk k
	lw $t0,-16($fp)
#this idk a
#<-idk k
	addi $a0, $t0, 0
	b L1
#return
L1:
	add $sp, $fp, $zero
	addiu $sp, $sp, 16
	lw $ra, -4($fp)
	lw $fp, 0($fp)
	j $ra
sort :
	addi $sp, $sp, -4
	sw $fp, 0($sp)
	add $fp, $sp, $zero
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	addi $sp, $sp, -4
	addi $sp, $sp, -4
#->idk low
	lw $t0,8($fp)
#this idk a
#<-idk low
	sw $t0, -8($fp)
L6:
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
#->idk high
	lw $t0,4($fp)
#this idk a
#<-idk high
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	sub $t0,$t1,$t0
	addiu $sp, $sp, 4
	lw $t1,0($sp)
	slt $t0,$t1,$t0
	addiu $sp, $sp, 4
	beqz $t0, L7
	addi $sp, $sp, -4
#->idk a
	lw $t0,12($fp)
#this idk a
#<-idk a
	addi $sp, $sp, -4
	sw $t0, 0($sp)
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0, 0($sp)
#->idk high
	lw $t0,4($fp)
#this idk a
#<-idk high
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	jal minloc
	add $t0 ,$a0, $zero
	sw $t0, -12($fp)
#->idk a
#->idk k
	lw $t0,-12($fp)
#this idk a
#<-idk k
	li $t2, 4
	mul $t2,$t2,$t0
	lw $t1, 12($fp)
	la $t1, 0($t1)
#this idk a[i]
	add $t1,$t1,$t2
	lw $t0,0($t1)
#<-idk a
	sw $t0, -16($fp)
#->idk a
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	li $t2, 4
	mul $t2,$t2,$t0
	lw $t1, 12($fp)
	la $t1, 0($t1)
#this idk a[i]
	add $t1,$t1,$t2
	lw $t0,0($t1)
#<-idk a
	add $t3, $t0, $zero
#->idk k
	lw $t0,-12($fp)
#this idk a
#<-idk k
	li $t2, 4
	mul $t2,$t2,$t0
#this not arrat
	lw $t1, 12($fp)
	add $t1,$t1,$t2
	sw $t3, 0($t1)
#->idk t
	lw $t0,-16($fp)
#this idk a
#<-idk t
	add $t3, $t0, $zero
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	li $t2, 4
	mul $t2,$t2,$t0
#this not arrat
	lw $t1, 12($fp)
	add $t1,$t1,$t2
	sw $t3, 0($t1)
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -8($fp)
	b L6
L7:
L5:
	add $sp, $fp, $zero
	addiu $sp, $sp, 16
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
	addi $sp, $sp, -40
	li $t0, 0
	sw $t0, -8($fp)
L9:
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 10
	lw $t1,0($sp)
	slt $t0,$t1,$t0
	addiu $sp, $sp, 4
	beqz $t0, L10

	# input
	li $v0, 4
	la $a0, input_str
	syscall
	li $v0, 5
	syscall
	move $t0, $v0
	add $t3, $t0, $zero
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	li $t2, 4
	mul $t2,$t2,$t0
#this arrat
	addi $t1, $fp, -48
	add $t1,$t1,$t2
	sw $t3, 0($t1)
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -8($fp)
	b L9
L10:
#->idk x
	la $t0,-48($fp)
#this idk a
#<-idk x
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	li $t0, 0
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	li $t0, 10
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	jal sort
	add $t0 ,$a0, $zero
	li $t0, 0
	sw $t0, -8($fp)
L11:
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 10
	lw $t1,0($sp)
	slt $t0,$t1,$t0
	addiu $sp, $sp, 4
	beqz $t0, L12

	# output
	move $t0, $v0
	li $v0, 4
	la $a0, output_str
	syscall
	move $v0, $t0
#->idk x
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	li $t2, 4
	mul $t2,$t2,$t0
	la $t1, -48($fp)
#this idk a[i]
	add $t1,$t1,$t2
	lw $t0,0($t1)
#<-idk x
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la $a0, newline
	syscall
#->idk i
	lw $t0,-8($fp)
#this idk a
#<-idk i
	addi $sp, $sp, -4
	sw $t0,0($sp)
	li $t0, 1
	lw $t1,0($sp)
	add $t0,$t1,$t0
	addiu $sp, $sp, 4
	sw $t0, -8($fp)
	b L11
L12:
L8:
	add $sp, $fp, $zero
	addiu $sp, $sp, 4
	lw $ra, -4($fp)
	lw $fp, 0($fp)
	j $ra
