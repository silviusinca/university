.data
    sir: .space 51
    num: .long 0
    vocale: .asciz "aeiou"
    formatPrintf: .asciz "Numarul de vocale este %d\n"
    formatPrintf2: .asciz "string = %s\n"
    formatScanf: .asciz "%d"
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
    je et_afis

    cmp $'a', %ah
    je et_creste
    
    inc %ecx
    jmp et_loop

et_creste:
    movl num, %ebx
    incl %ebx
    movl %ebx, num

    jmp et_loop


et_afis:
    push num
    push $formatPrintf
    call printf
    pop %ebx
    pop %ebx


et_exit:
    movl $1, %eax
    movl $0, %ebx
    int $0x80
