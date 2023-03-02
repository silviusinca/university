.data
    x: .long 30
    y: .long 7
.text
.global main
main:
    movl $0, %edx
    movl x, %eax
    divl y

et_exit:
    movl $1, %eax
    movl $0, %ebx
    int $0x80
