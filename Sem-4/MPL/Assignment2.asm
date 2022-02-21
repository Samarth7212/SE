section .data
msg1: db "Enter a string",0xA
len1: equ $-msg1
msg2: db "Length of entered string is "
len2: equ $-msg2

section .bss
num: resb 20
len: resb 2

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
    IO 01,01,msg1,len1
    IO 00,00,num,20

    mov byte[len], 0

    ;Hex to ascii
    cmp al, 09H
    jbe l1
    add al, 07H
    l1:
        add al, 30H
    mov byte[len], al;Move length to len variable to print it
    
    IO 01,01,msg2,len2
    IO 01,01,len,6

    mov rax, 60
    mov rdi, 00
    syscall


    ; mov rax, 01
    ; mov rdi, 01
    ; mov rsi, msg1
    ; mov rdx, len1
    ; syscall

    ; mov rax, 00
    ; mov rdi, 00
    ; mov rsi, num
    ; mov rdx, 20
    ; syscall