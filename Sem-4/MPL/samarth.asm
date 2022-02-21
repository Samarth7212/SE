section .data
var1: db 100
var2: db 10
var3: dw 10000
count: db 0

section .bss
cnt: resb 2
res: resb 4

section .text

global _start

_start:

    mov byte[cnt], 0
    mov byte[res], 0
    mov rbx, var1
    mov rcx, res
    l1:
        cmp byte[rbx], 09h
        jbe l2
        add byte[rbx], 07H
        ; inc byte[cnt]
        l2:
            add byte[rbx], 30h
        ; mov res, rax
        inc rbx
        ; inc rcx
        jnz l1
    
    

    ; cmp al, 09H    

    ; jbe l1
    ; add al, 07H
    ; l1:
    ;     add al, 30H
    ; mov byte[cnt], al

    ; mov rax, 01
    ; mov rdi, 01
    ; mov rsi, cnt
    ; mov rdx, 10
    ; syscall



    ; mov rax, 01
    ; mov rdi, 01
    ; mov rsi, var2
    ; mov rdx, 10
    ; syscall

    ; mov rax, 01
    ; mov rdi, 01
    ; mov rsi, var3
    ; mov rdi, 10
    ; syscall

    ;Exit system call
    mov rax, 60
    mov rdi, 00
    syscall