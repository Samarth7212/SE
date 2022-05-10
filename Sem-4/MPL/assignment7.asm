%macro IO 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data
	space db " "

	before_msg db	10,"Before Transfer: "
	before_len	equ	$-before_msg

	after__transfer db	10,"After Transfer: "
	after__transfer_len	equ	$-after__transfer
	
	source_block_msg db	10,"Source Block: "
	source_block_len equ	$-source_block_msg

	destination_block_msg db	10,"Destination Block: "
	destination_len	equ	$-destination_block_msg

	source_block db	5h,4h,3h,2h,1h
	destination_block times	5 db 0
	
section .bss
	Result resB 2

section .text
	global _start

_start:
	IO 01, 01, before_msg, before_len

	IO 01, 01,  source_block_msg, source_block_len
	mov	rsi,source_block
	call disp_block

	IO 01, 01, destination_block_msg, destination_len
	mov	rsi,destination_block
	call disp_block
	
	call Block_Transfer

	IO 01, 01, after__transfer, after__transfer_len 

	IO 01, 01,  source_block_msg, source_block_len
	mov	rsi,source_block
	call disp_block

	IO 01, 01, destination_block_msg, destination_len
	mov	rsi,destination_block
	call disp_block

    MOV	RAX,60
    MOV	RDI,0
    syscall


HexToASCII:
	MOV	RSI,Result+1
	MOV	RCX,2
	MOV	RBX,16

    next_digit:
	    XOR	RDX,RDX
	    DIV	RBX
	    cmp	DL,9	
	    jbe	add30
	    add	DL,07H

    add30:
	    add DL,30H
	    mov	[RSI],DL

	    dec RSI
	    dec	RCX
	    jnz	next_digit

	    IO 01, 01, Result, 2
    ret

Block_Transfer:
	mov	rsi,source_block
	mov	rdi,destination_block
	mov	rcx,5

    back:	
        mov	al,[rsi] 
	    mov	[rdi],al

	    inc	rsi
	    inc	rdi

	    dec	rcx
	    jnz	back
    ret
disp_block:
	mov	rbp,5
    next_num:
	    mov	al,[rsi]
	    push rsi

	    call HexToASCII
	    IO 01, 01, space, 1
	
	    pop	rsi
	    inc	rsi
	
	    dec	rbp
	    jnz	next_num
    ret
