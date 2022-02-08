section .bss
var: resb 1

section .text

global _start

_start:
    mov rax, 00
    mov rdi, 00
    mov rsi, var
    mov rdx, 10
    syscall
    mov rax, 1
    mov rdi, 1
    mov rsi, var
    mov rdx, 10
    syscall
    ; syscall
    mov rax, 60
    mov rdi, 00
    syscall
