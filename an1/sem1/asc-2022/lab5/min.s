.data
    x: .long 1
    y: .long 0
    z: .long 1
    format: .asciz "minimul este: %d\n"
.text
.global main

min3:
et_min3:
    push %ebp
    mov %esp, %ebp
    push %ebx

    movl 8(%ebp), %eax  
    movl 12(%ebp), %ebx 
    movl 16(%ebp), %ecx

    cmp %eax, %ebx
    jg et_cmp_eax_ecx
    jmp et_cmp_ebx_ecx

et_cmp_eax_ecx:
    cmp %eax, %ecx
    jl et_ecx
    jmp et_cont

et_cmp_ebx_ecx:
    cmp %ebx, %ecx
    jl et_ecx
    jmp et_ebx

et_ecx:
    movl %ecx, %eax
    jmp et_cont

et_ebx:
    movl %ebx, %eax
    jmp et_cont

et_cont:
    pop %ebx 
    pop %ebp
    ret 

main:
    
    push z
    push y
    push x
    call min3 
    addl $12, %esp 
    
    push %eax
    push $format
    call printf
    pop %ebx
    pop %ebx

    movl $1, %eax
    movl $0, %ebx
    int $0x80
