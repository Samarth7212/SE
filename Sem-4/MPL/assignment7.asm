section .data
arr1 db 11h,22h,33h,44h,55h
space db ' '
newLine db 10
msg1: db 'Before: ',0xa
len1: equ $-msg1
msg2: db 'After: ',0xa
len2: equ $-msg2

section .bss
adress resb 20
data resb 5
dig_count resb 2
count resb 2
arr2 resb 10

%macro print 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text
global _start

_start:
;Block transfer using string operation
    mov esi,arr1
    mov edi,arr2
    xor rcx,rcx
    mov cx,05

    cld ;clear direction flag for autoincrement of si and di
    rep movsb
    
    ;logic to print adress and data
    ;before block transfer
    print msg1,len1
    
    mov byte[count],05
    mov rsi,arr1
    ;call procedure print adress to print the 64- bit adress which is in rbx
    
    up1:
        mov rbx ,rsi
    push rsi
    call printadd
    print space,01
    pop rsi
    
    ;call procedure print data to print 8-bit data which is in register dl
    mov dl,[rsi]
    push rsi
    call printdata 
    print newLine,01
    
    pop rsi
    inc rsi
    dec byte[count]
    jnz up1
    ;After block transfer
    
    print msg2,len2
    mov byte[count],05
    mov rsi,arr2
    ;call procedure print adress to print the 64- bit adress which is in rbx
    
    up3: 
        mov rbx ,rsi
    push rsi
    call printadd
    print space,01
    pop rsi
    ;call procedure print data to print 8-bit data which is in register dl
    mov dl,[rsi]
    push rsi
    call printdata
    print newLine,01
    pop rsi
    inc rsi
    dec byte[count]
    jnz up3
    mov rax,60
    mov rdi,00
    syscall
    
printadd:
    mov byte[dig_count],16
    mov rsi,adress
    up:
    rol rbx,04
    mov al,bl
    and al,0Fh
    cmp al,09
    jbe l1
    add al,07h
    l1:
        add al,30h
    mov [rsi], al ;mov leng to str_len variable for printing
    inc rsi
    dec byte[dig_count]
    jnz up

    mov rax,01
    mov rdi,01
    mov rsi,adress
    mov rdx,16
    syscall
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
            mov [rsi], al ;mov leng to str_len variable for printing
            inc rsi
            dec byte[dig_count]
            jnz up2
        mov rax,01
        mov rdi,01
        mov rsi,data
        mov rdx,02
        syscall
    ret