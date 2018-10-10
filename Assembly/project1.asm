#Taylor Morlan

.globl main

.text

main:

	and $s0, $s0, $zero #clearing 3 registers
	and $s1, $s1, $zero
	and $s2, $s2, $zero
	addi $s0, $zero, '.'  #ascii value for .
	addi $s1, $zero, 'Z'  #ascii value for Z
	addi $s2, $zero, 'z' #ascii value for z

	#printing out first message
	addi $v0, $zero, 4	#print 1st message
	la $a0, message1	#loading address of message
	syscall				#syscall
	
	#reading in user string
	addi $v0, $zero, 8	#enter word syscall
	la $a0, input		#where to store input
	and $a1, $zero, $a1
	addi $a1, $zero, 256 #length of input
	syscall				#syscall
	jal findZ

	#printing out second message
	addi $v0, $zero, 4	#print 2nd message
	la $a0, message2	#loading address of message
	syscall				#syscall
	addi $v0, $zero, 1
	move $a0, $s6		#encapsulatedd psuedo instruction
	syscall

	j exit
findZ:
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	and $s6, $s6, $zero #clearing register to store number of Z's
	and $s7, $s7, $zero #using register to track progression through word
	addi $t1, $zero, 4 #register to compare for finding end of word
	la $s3, input #loading address of string with a psuedo instruction
	lw $s4, 0($s3) #loading the first 4 ascii values
loop:
	andi $s5, $s4, 0xff
	beq $s5, $s2, zFound #if z is found
	beq $s5, $s1, zFound #if Z is found
	beq $s5, $s0, exitFunc #if . is found
	srl $s4, $s4, 8
	addi $s7, $s7, 1
	beq $s7, $t1, loadNext  
	j loop
zFound:
	addi $s6, $s6, 1
	srl $s4, $s4, 8
	addi $s7, $s7, 1
	beq $s7, $t1, loadNext
	j loop
exitFunc:
	lw $ra , 0($sp)
	addi $sp, $sp, 4
	jr $ra
loadNext:
	addi, $s3, $s3, 4
	lw $s4, 0($s3)
	add $s7, $zero, $zero 
	j loop 

exit:	#exiting program
	addi $v0, $zero, 10 # Sets $v0 to "10" to select exit syscall
	syscall # Exit

.data

input:		.space 256
message1:	.asciiz "Please enter a string ending with '.': "
message2:	.asciiz "\nThe number of 'Z' and 'z' found is: "
