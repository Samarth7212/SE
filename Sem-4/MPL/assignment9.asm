;Write x86 ALP to find the factorial of a given integer number on ;a command line without recursion.  
;Explicit stack manipulation is expected in the code.


section .data
 
	msg1: db 'Enter number to calculate factorial:',0xa
	len1: equ $-msg1

	msg2: db 'Factorial of Number is:',0xa
	len2: equ $-msg2
	count db 0

section .bss
	num resb 03
	result resb 08

section .text

	global _start
	_start:

	xor rax,rax
	xor rbx,rbx
	xor rcx,rcx
	xor rdx,rdx
	
	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,len1
	syscall

	mov rax,0
	mov rdi,0
	mov rsi,num
	mov rdx,03
	syscall
	
	
	call ATOH
up:
	inc byte[count]
	push bx
	dec bx
	cmp bx,01h
	jg up
	
	mov ax,01H
	xor rbx,rbx

	

A:
	
	pop bx
	mul bx
	dec byte[count]
	jnz A
	mov rbx,rax

	mov rax,1
	mov rdi,1
	mov rsi,msg2
	mov rdx,len2
	syscall


	call HTOA

	mov rax,60
	mov rdi,0
	syscall
	

ATOH:                                          ;; ASCII to Hex conversion
	xor rbx,rbx
	xor rcx,rcx
	xor rax,rax

	mov rcx,02
	mov rsi,num
	up1:
	rol bx,04

	mov al,[rsi]
	cmp al,39h
	jbe p1

	sub al,07h

	p1: 
	sub al,30h
	add bl,al
	inc rsi
	loop up1
ret

HTOA:
;; Hex to ASCII conversion
	mov rcx,8
	mov rdi,result
	dup1:
	rol ebx,4
	mov al,bl
	and al,0fh
	cmp al,09h
	jbe p3
	add al,07h
	jmp p4
	p3: add al,30h
	p4:mov [rdi],al
	inc rdi
	loop dup1

	mov rax,1
	mov rdi,1
	mov rsi,result
	mov rdx,08
	syscall
ret



;******output******
;[student@localhost]$ nasm -f elf64 ass9.asm
;[student@localhost]$ ld -o ass9 ass9.o
;[student@localhost]$ ./ass9
;Enter number to calculate factorial:
;04
;Factorial of Number is:
;00000018[student@localhost]$ 


