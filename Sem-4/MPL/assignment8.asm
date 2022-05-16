%macro IO 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

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
	
	IO 01, 01, msg1, len1
	IO 00, 00, num, 8
	call ASCIItoHex
up:
	inc byte[count]
	push bx
	dec bx
	cmp bx,01h
	jg up
	
	mov ax,01H
	xor rbx,rbx

continue:
	pop bx
	mul bx
	dec byte[count]
	jnz continue
	mov rbx,rax

	IO 01, 01, msg2, len2
	call HexToASCII

	mov rax,60
	mov rdi,0
	syscall
	

ASCIItoHex:
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

HexToASCII:
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
	p3: 
		add al,30h
	p4:
		mov [rdi],al
		inc rdi
		loop dup1
	IO 01, 01, result, 08
ret
