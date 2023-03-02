.data
    x: .long 5
    y: .long 3

.text
.global main
main:
    movl x, %eax
    ; movl y, %ebx
    ; mul %ebx 
    mull y

et_exit:
    movl $1, %eax
    movl $0, %ebx
    int $0x80
