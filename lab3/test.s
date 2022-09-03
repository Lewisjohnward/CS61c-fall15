.data
str: .asciiz "Shake and bake"

.global main

.text
main: 
    la $a0, str #Load address of str
    addi $v0, $0, 4 #Print string
    syscall
    addi $v0, $0, 10 #exit
    syscall
        
