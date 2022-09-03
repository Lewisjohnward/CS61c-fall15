#Adder
.text
main:
    add $t0, $0, $s0
    add $t1, $0, $s1
    add $t2, $t1, $t0
    add $t3, $t2, $t1
    add $t4, $t3, $t2
    add $t5, $t4, $t3
    add $t6, $t5, $t4
    add $t7, $t6, $t5
    add $a0, $0, $t7
    addi $v0, $0, 1 #print int
    syscall
    addi $v0, $0, 10 #exit
    syscall
