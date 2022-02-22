
%macro IO 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
arr: dq 0x11,0xffffffffffffff13,0x19,0xffffffffffffff18,0x28
pos: dq "Positive", 0xA
len1: equ $-pos
neg: dq "Negative", 0xA
len2: equ $-neg

out1: dq "Positive nums: ", 0xA
lo1: equ $-out1
out2: dq "Negative nums: ", 0xA
lo2: equ $-out2

section .bss
cnt: resb 2
cntp: resb 2
cntn: resb 2

section .text
global _start

_start:	
	
	mov rbx, arr
	mov byte[cnt], 0x5
	mov byte[cntp], 0
	mov byte[cntn], 0
	
	lab:
		mov rax, qword[rbx]
		mov rsi, arr
		BT rax, 63
		jc z2
		jnc nonz
		nonz: 
			inc byte[cntp]
			IO 01, 01, pos, len1
			jmp z
		z2: 
			inc byte[cntn]
			IO 01, 01, neg, len2
		z:
			add rbx, 8
		dec byte[cnt]
		jnz lab
	IO 01, 01, out1, lo1
	
	mov al, byte[cntp]
	cmp al, 30H
	jbe l1
	add al, 07H
	l1: add al, 30H
	mov byte[cntp], al
	IO 01, 01, cntp, 2
	
	IO 01, 01, out2, lo2
	
	mov al, byte[cntn]
	cmp al, 30H
	jbe l3
	add al, 07H
	l3: add al, 30H
	mov byte[cntn], al
	IO 01, 01, cntn, 2
	
	mov rax, 60
	mov rdi, 00
	syscall
	
	
	
	
	
	
	
	
