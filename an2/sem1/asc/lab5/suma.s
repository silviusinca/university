// Procedura care calculeaza suma a doua numere

.data
    x: .long 5
    y: .long 6
.text
.global main

suma:
    push %ebp
    mov %esp, %ebp
    push %ebx 

    movl 8(%ebp), %eax  ; x
    movl 12(%ebp), %ebx ; y

    addl %ebx, %eax

    pop %ebx 
    pop %ebp
    ret 
    
main:
    
    push y
    push x
    call suma 
    addl $8, %esp ;in loc de 2 pop-uri
    
    // afisare %eax

    movl $1, %eax
    movl $0, %ebx
    int $0x80