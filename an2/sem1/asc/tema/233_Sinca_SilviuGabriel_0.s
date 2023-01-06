.data
    op: .space 4
    N: .space 4
    M: .space 4
    numLegaturi: .space 400
    elemCurent: .space 4
    index: .space 4

    matrice: .space 40000
    indexLinie: .space 4
    indexColoana: .space 4

    formatScanf: .asciz "%d"
    formatPrintf: .asciz "%d "
    formatPrintf2: .asciz "%d: %d\n"
    linieNoua: .asciz "\n"


.text
.global main

main:
    push $op
    push $formatScanf
    call scanf
    pop %ebx
    pop %ebx

    push $N
    push $formatScanf
    call scanf
    pop %ebx
    pop %ebx

    movl $0, %ecx
    movl $numLegaturi, %edi

et_citire_numere_legaturi:
	cmp N, %ecx
	je et_cont_citire

	pushl %ecx
	
	pushl $elemCurent
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx

	popl %ecx

	movl elemCurent, %eax
	movl %eax, (%edi, %ecx, 4)
	
	incl %ecx
	jmp et_citire_numere_legaturi 

et_cont_citire:
    movl $0, %ecx
    movl $numLegaturi, %edi

et_citire_noduri:
    cmp N, %ecx
    je et_afis

    movl (%edi, %ecx, 4), %ebx 

    incl %ecx
    cmp $0, %ebx
    je et_citire_noduri
    movl $0, index
    jmp et_for_citire_noduri

et_for_citire_noduri:
    cmp index, %ebx
    je et_citire_noduri

    pushl %ecx
    pushl %ebx

	pushl $elemCurent
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx

    popl %ebx
    popl %ecx

    movl %ecx, %edx

    decl %edx
	movl %edx, %eax
	movl $0, %edx
	mull N
	addl elemCurent, %eax

    lea matrice, %esi
	movl $1, (%esi, %eax, 4)

	incl index
	jmp et_for_citire_noduri


et_afis:
	movl $0, indexLinie
	linie:
		movl indexLinie, %ecx
		cmp %ecx, N
		je et_exit
		
		movl $0, indexColoana
		coloana:
			movl indexColoana, %ecx
			cmp %ecx, N
			je et_cont
			
			movl indexLinie, %eax
			movl $0, %edx
			mull N
			addl indexColoana, %eax
			
			lea matrice, %edi
			movl (%edi, %eax, 4), %ebx

            pushl %ecx
			pushl %ebx
			pushl $formatPrintf
			call printf
			popl %ebx
			popl %ebx
            popl %ecx

			incl indexColoana
			jmp coloana
		
	et_cont:

        pushl $linieNoua
        call printf
        popl %ebx
		
		incl indexLinie
		jmp linie

    
et_exit:

    movl $1, %eax
    movl $0, %ebx
    int $0x80
