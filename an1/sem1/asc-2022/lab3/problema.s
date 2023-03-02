.data
    v: .long 15, 27, 13, 8, 31, 16
    n: .long 6
    max: .space 4
    format: .asciz "Maximul este %d \n"

.text
.global main
main:
    movl v, %eax
    movl %eax, max 
    // retinem primul numar ca fiind max
    movl $v, %edi
    mov $0, %ecx

et_loop:
    cmp n, %ecx 
    je et_afis
    movl (%edi, %ecx, 4), %ebx 
    
    cmp max, %ebx
    jg et_max

    incl %ecx
    jmp et_loop  


et_max:
    movl %ebx, max
    incl %ecx
    jmp et_loop


et_afis:
    push max
    push $format
    call printf
    pop %ebx
    pop %ebx


et_exit:
    movl $1, %eax
    movl $0, %ebx
    int $0x80
