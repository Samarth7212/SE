%macro IO 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

 section .data
 num1: dq 0x9
 num2: dq 0x8
newLine: db "",0x0A
len: equ $-newLine
 
 section .bss
 result: resq 2
 AdditionResult: resq 2
 SubtractionResult: resq 2
 DivisionResult: resq 2
 MultiplicationResult: resq 2
 cnt: resb 1
 
 section .text
 global _start
 
 _start:
 	CALL Addition
 	CALL Subtraction
 	CALL Division
 	CALL Multiplication
 	mov rax, 60
 	mov rdi, 00
 	syscall

HexToASCII:
 		mov byte[cnt], 0x10
 		lab:
 			rol rax, 4
 			mov bl, al
 			and bl, 0x0F
 			cmp bl, 09H
 			jbe l1
 			add bl, 07H
 			l1:
 				add bl, 30H
 			mov [rsi],bl
 			inc rsi
 			dec byte[cnt]
 			jnz lab
 		ret

Addition:
	mov rax, qword[num1]
	add rax, qword[num2]
	mov rsi, AdditionResult
	CALL HexToASCII
 	IO 01, 01, AdditionResult, 16
 	IO 01, 01, newLine, len
	ret
	
Subtraction:
	mov rax, qword[num1]
	sub rax, qword[num2]
	mov rsi, SubtractionResult
 	CALL HexToASCII
 	IO 01, 01, SubtractionResult, 16
 	IO 01, 01, newLine, len
	ret

Division:
	xor rax, rax
	xor rdx, rdx
	mov rax, qword[num1]
	div qword[num2]
	mov rsi, DivisionResult
	CALL HexToASCII
	IO 01, 01, DivisionResult, 16
	IO 01, 01, newLine, len
	ret

Multiplication:
	xor rax, rax
	xor rdx, rdx
	mov rax, qword[num1]
	mul qword[num2]
	push rax
	mov rax, rdx
	mov rsi, MultiplicationResult
	CALL HexToASCII
	pop rax
	CALL HexToASCII
	IO 01,01, MultiplicationResult, 32
	IO 01, 01, newLine, len
	ret



