.data
    sir: .space 100
    num: .long 0
    formatPrintf: .asciz "Numarul de vocale este %d\n"
    formatPrintf2: .asciz "string = %s\n"
    formatScanf: .asciz "%s"
.text
.global main
main:
    push $sir
    push $formatScanf
    call scanf
    pop %ebx
    pop %ebx

    movl $sir, %edi
    movl $0, %ecx

et_loop:
    movb (%edi, %ecx, 1), %ah
    
    cmp $0, %ah
    je et_exit

    cmp $'a', %ah
    je et_creste
    cmp $'e', %ah
    je et_creste
    cmp $'i', %ah
    je et_creste
    cmp $'o', %ah
    je et_creste
    cmp $'u', %ah
    je et_creste
    
    incl %ecx
    
    jmp et_loop

et_creste:
    movl num, %ebx
    incl %ebx
    movl %ebx, num
    incl %ecx
    jmp et_loop

et_exit:
    push num
    push $formatPrintf
    call printf
    pop %ebx
    pop %ebx

    movl $1, %eax
    movl $0, %ebx
    int $0x80
