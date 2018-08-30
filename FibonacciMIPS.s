################### Code segment ####################
.text
.globl main
main:
    
    li $v0,5                       # Reading an integer value
    syscall

    move $a0,$v0
    
jal FIB                            # Calling the fibonacci function
    
    
    move $a0,$v0                   # Display fibonacci
    li $v0,1
    syscall


    li          $v0,10             # exit
	syscall


#Function Fibonacci################
FIB:    bne $a0,1,salto         # if (n != 1)
            li $v0,0
            jr $ra
        salto:

        bne $a0,2,salto2        # if (n != 2)
            li $v0,1
         jr $ra
        salto2:
    
        addiu $a0,$a0,-2        # remove excetion (n = 1 and n = 2)
        li $t0,0
        li $t1,1
    
    volta:                      # loop, for fibonacci greater than 2
        add $v0,$t0,$t1
        move $t0,$t1
        move $t1,$v0

        addiu $a0,$a0,-1
        bne $a0,0,volta
    
        jr $ra
#####################################

#By: Francisco Pereira do Nascimento
