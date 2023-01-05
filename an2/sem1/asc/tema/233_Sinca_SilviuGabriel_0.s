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
    formatPrintf: .asciz "Numarul este: %d\n"

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
    je et_exit

    movl (%edi, %ecx, 4), %ebx 

    incl %ecx
    cmp $0, %ebx
    je et_citire_noduri

    jmp et_citire_nod_legatura_actual

et_citire_nod_legatura_actual:
    pushl %ecx

    

    movl $0, index
    movl index, %ecx

et_for_citire:


    popl %ecx

    jmp et_citire_noduri


et_afis:
    push N
    push $formatPrintf
    call printf
    pop %ebx
    pop %ebx    


et_afis_matr:
	movl $0, lineIndex
	for_lines:
		movl lineIndex, %ecx
		cmp %ecx, n
		je et_exit
		
		movl $0, columnIndex
		for_columns:
			movl columnIndex, %ecx
			cmp %ecx, n
			je cont
			
			// afisez matrix[lineIndex][columnIndex]
			// lineIndex * n + columnIndex
			movl lineIndex, %eax
			movl $0, %edx
			mull n
			addl columnIndex, %eax
			// %eax = lineIndex * n + columnIndex
			
			lea matrix, %edi
			movl (%edi, %eax, 4), %ebx
			
			pushl %ebx
			pushl $formatPrintf
			call printf
			popl %ebx
			popl %ebx
			
			pushl $0
			call fflush
			popl %ebx
			
			incl columnIndex
			jmp for_columns
		
	cont:
		movl $4, %eax
		movl $1, %ebx
		movl $newLine, %ecx
		movl $2, %edx
		int $0x80
		
		incl lineIndex
		jmp for_lines
		

et_exit:
    movl $1, %eax
    movl $0, %ebx
    int $0x80
