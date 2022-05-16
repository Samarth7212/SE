
%macro IO 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
arr1 db 11h,22h,33h,44h,55h
space db ' '
newLine db 0x0A
msg1: db 'Before: ',0x0A
len1: equ $-msg1
msg2: db 'After: ',0x0A
len2: equ $-msg2

section .bss
address resb 20
data resb 5
dig_count resb 2
count resb 2
arr2 resb 10

section .text
global _start

_start:
    mov rsi,arr1
    mov rdi,arr2
    xor rcx,rcx
    mov cx,05

    cld 
    rep movsb

    IO 01, 01, msg1, len1

    mov byte[count],05
    mov rsi,arr1
    
    up1:
        mov rbx ,rsi
        push rsi
        call printadd
        IO 01, 01, space, 01
        pop rsi

        mov rdx,[rsi]
        push rsi
        call printdata 
        IO 01, 01, newLine, 01

        pop rsi
        inc rsi
        dec byte[count]
        jnz up1
    
    IO 01, 01, msg2, len2
    mov byte[count],05
    mov rsi,arr2
    
    up3: 
        mov rbx ,rsi
        push rsi
        call printadd
        IO 01, 01, space, 01
        pop rsi
        mov rdx,[rsi]
        push rsi
        call printdata
        IO 01, 01, newLine, 01
        pop rsi
        inc rsi
        dec byte[count]
        jnz up3
    mov rax,60
    mov rdi,00
    syscall
    
printadd:
    mov byte[dig_count],16
    mov rsi,address
    up:
        rol rbx,04
        mov al,bl
        and al,0Fh
        cmp al,09
        jbe l1
        add al,07h
        l1:
            add al,30h
        mov [rsi], al
        inc rsi
        dec byte[dig_count]
        jnz up

    IO 01, 01, address,16
    ret

printdata:
    mov byte[dig_count],02
    mov rsi,data
    up2:
        rol dl,04
        mov al,dl
        and al,0Fh
        cmp al,09
        jbe l2
        add al,07h
        l2:
            add al,30h
        mov [rsi], al
        inc rsi
        dec byte[dig_count]
        jnz up2
    IO 01, 01, data, 02     
    ret