;Assignment-1
;Read 5 numbers and display it

%macro print 2
    mov rax, 1
    mov rdi, 1
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

section .data
cnt: db 0
block: dq 0
str1: db "Start entering values : ",0xA
len1: equ $-str1
str2: db "The values you entered : ",0xA
len2: equ $-str2

section .bss
str: resb 20

section .text

global _start

_start:
    print str1, len1

    mov rbx, block ;rbx is pointer to block
    mov byte[cnt],05H

    read_L:  
        mov rax, 0
        mov rdi, 0
        mov rsi, rbx
        mov rdx, 10 
        syscall
        add rbx, 10  
        dec byte[cnt]
        jnz read_L
    
    print str2, len2

    mov rbx, block 
    mov byte[cnt],05H

    print_L:
        mov rax, 1
        mov rdi, 1
        mov rsi, rbx
        mov rdx, 17
        syscall
        add rbx, 17
        dec byte[cnt]
        jnz print_L

    mov rax, 60
    mov rdi, 00
    syscall
















