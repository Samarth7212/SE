%macro IO 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
arr: dq 0x1933,0x1019,0x2323,0x7999,0x1567

section .bss
cnt: resb 8
max: resq 1
number: resb 8

section .text
global _start

_start:
    mov rbx, arr
    mov byte[cnt], 0x5  ;Initialize length of array
    mov qword[max], 0x0 ;Initialize max as 0 
    lab:
        mov rax, qword[rbx]     ;Move data to RAX
        mov rsi, arr            ;RSI points to arr
        cmp rax, qword[max]     ;Compare and update values
        ja l1
        jmp l2
        l1:
            mov qword[max], rax
        l2:
            add rbx, 8
            dec byte[cnt]
            jnz lab
    
    HexToASCII:
        mov rax, qword[max]
        mov byte[cnt], 0x10
        mov rsi, number
        continue1:
            rol rax, 4
            mov bl, al
            and bl, 0x0f
            cmp bl, 0x09
            jbe continue2
            add bl, 07h
            continue2:
                add bl, 30h
                mov [rsi], bl
                inc rsi
                dec byte[cnt]
                jnz continue1

    IO 01, 01, number, 16
    mov rax, 60
    mov rdi, 00
    syscall
