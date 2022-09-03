.data
.word 2, 4, 6, 8
n: .word 9

.text
main:   add     $t0, $0, $0
        addi    $t1, $0, 1
        la      $t3, n
        lw      $t3, 0($t3)
fib:    beq     $t3, $0, finish
        add     $t2, $t1, $t0
        move      $t0, $t1
        move      $t1, $t2
        addi    $t3, $t3, -1
        j       fib
finish: addi    $v0, $0, 1
        addi    $a0, $t0, 0
        syscall # print integer ecall
        addi    $v0, $0, 10
        syscall # terminate ecall

