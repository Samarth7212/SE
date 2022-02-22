section .bss
len: resb 2
num: resb 20

section .data
msg1: dq "Enter the string", 0xA
len1: equ $-msg1

%macro IO 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .text

global _start
_start:
	IO 01, 01, msg1, len1
	IO 00, 00, num, 20
	mov byte[len], 00
	
	cmp al, 09H
	jbe l1
	add al, 07H
	l1:
		add al, 30H
	mov byte[len], al
	dec byte[len]
	IO 01, 01, len, 2
	
	mov rax, 60
	mov rdi, 00
	syscall
