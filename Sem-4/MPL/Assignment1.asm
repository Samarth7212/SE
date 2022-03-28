;Assignment-1
;Read 5 numbers and display it

section .data
str1: db "Enter Five Names " ,0xA  
len1: equ $-str1

str2: db "OUTPUT - "  ,0xA
len2: equ $-str2
cnt : db 0  

section .bss
name : resb 20  ;reserving the memory of 20bytes


%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

section .text

global _start

_start:

	print str1, len1
	mov rbx,name   
	mov byte[cnt],0x5

	read_L:
		mov rax ,0
		mov rdi ,0
		mov rsi ,rbx
		mov rdx ,17
		syscall
		add rbx ,17 ;moving the pointer 17 memory location ahead for storing the next data
		dec byte[cnt]
		jnz read_L     

	print str2, len2

	mov rbx,name
	mov byte[cnt],0x5

	print_L:
		print rbx, 17
		add rbx , 17
		dec byte[cnt]
		jnz print_L
		
	mov rax,60
	mov rdi,00
	syscall














