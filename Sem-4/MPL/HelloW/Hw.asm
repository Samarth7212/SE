section .data 
str: db "HelloWorld" ,0xA
len: equ $-str  
str1: db "Welcome to PICT", 0xA
len1: equ $-str1      


section .text 

global _start

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, str
	mov rdx, len
	syscall
	mov rax, 1
	mov rdi, 1
	mov rsi, str1
	mov rdx, len1
	syscall
	mov rax, 60
	mov rdi, 00
	syscall