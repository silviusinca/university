.data
.text
.global main
main:
    mov x, %eax
    cmp y, %eax
    jge label
    mov $5, %ecx 
    jmp et_exit

label:
    mov $6, %ecx

et_exit:
    movl $1, %eax
    movl $0, %ebx
    int $0x80
