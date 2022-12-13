// str sir de caractere in memorie format din cifre spatii si litere mici. Sa se calculeze raportul 
//    dintre numarul de vocale din primul cuvant si numarul total de vocale (cat si rest) sau mesaj cu nu exista vocale

.data
    sir: .asciz "ana are mere"
    numPrim: .long 0
    numTotal: .long 0
    aux: .long 0
    format: .asciz "catul %d si restul %d\n"
    formatFail: .asciz "nu a fost gasita nicio vocala\n"
.text
.global main
main:
    movl $0, %ecx
    movl $sir, %edi
    
et_loop:
    movb (%edi, %ecx, 1), %ah 

    cmp $0, %ah
    je et_exit

    cmp $' ', %ah
    je et_primul

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
    movl numTotal, %ebx
    incl %ebx
    movl %ebx, numTotal
    incl %ecx
    jmp et_loop

et_primul:
    incl %ecx
    movl aux, %ebx
    incl %ebx
    movl %ebx, aux

    cmp $1, %ebx
    je et_numPrim

    
    jmp et_loop

et_numPrim:
    movl numTotal, %ebx
    movl %ebx, numPrim
    jmp et_loop

et_fail:
    push $formatFail
    call printf
    pop %ebx

    movl $1, %eax
    movl $0, %ebx
    int $0x80

et_exit:
    movl numTotal, %eax
    cmp $0, %eax
    je et_fail

    movl $0, %edx
    movl numPrim, %eax
    movl numTotal, %ebx

    divl %ebx

    push %edx
    push %eax
    push $format
    call printf
    pop %ebx
    pop %ebx
    pop %ebx

    movl $1, %eax
    movl $0, %ebx
    int $0x80
