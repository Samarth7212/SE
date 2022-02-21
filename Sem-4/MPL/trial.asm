
section .data
count: db 0
; str: db "SAMARTH",0xA
; len: equ $-str

section .bss
str: resb 5

section .text
global _start

_start:

    mov rax, 0
    mov rdi, 0
    mov rsi, str
    mov rdx, 10
    syscall

    mov rbx, str
    mov eax,[rbx]
    

    label:
        inc byte[count]
        shl eax,4
        jnz label

    mov rax, 01
    mov rdi, 01
    mov rsi, byte[count]
    mov rdx, 20
    syscall

    mov rax, 60
    mov rdi, 60
    syscall
