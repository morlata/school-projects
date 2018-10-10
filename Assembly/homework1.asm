#Taylor Morlan
#HW1
.globl main
.text
main:
	addi $s0, $zero, 12
	addi $s1, $zero, 7
	la $s2, D

	jal sumF
	j exit
sumF:
	addi $t0, $zero, 10 #register for comparison operations
	addi $t1, $zero, 4 #register for iterating through array 32 bits at a time
while:	
	blt $s0,$t0,exitFunc
	mul $t2,$s0,$t1 #calculating offset for memory
	add $t2,$t2,$s2 #getting the starting address
	add $t3, $s0, $s1 #adding a+b
	sw $t3, ($t2) #storing result at D[a]
	addi $s0, $s0, -1
	j while
exitFunc:
	jr $ra
exit:	#exiting program
	addi $v0, $zero, 10 # Sets $v0 to "10" to select exit syscall
	syscall # Exit
.data
D: .space 2048