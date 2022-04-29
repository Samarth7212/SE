
%MACRO IO 4
MOV RAX, %1
MOV RDI, %2
MOV RSI, %3
MOV RDX, %4
SYSCALL
%ENDMACRO

section .data
isProtectedMode: dq "Protected Mode",0x0A
len1: equ $-isProtectedMode

limit: dq "Limit is "
lenLimit: equ $-limit

ba: dq "Base address is "
baLimit: equ $-ba

isRealMode: dq "Real Mode", 0x0A
len2: equ $-isRealMode

newLine: db "",0x0A
len: equ $-newLine

section .bss
GDTR: resq 1
GDT: resq 1
RESULT: resb 1
cnt: resb 1

section .text
global _start

_start:
	SMSW RAX
	BT RAX, 0
	JC l1
	JNC l2
	l1:
		IO 01, 01, isProtectedMode, len1
		JMP l3
	l2:
		IO 01, 01, isRealMode, len2
	l3:
		;GDTR
		SGDT [GDT]
		MOV AX, word[GDT]
		CALL HexToASCII
		IO 01, 01, limit, lenLimit
		IO 01, 01, RESULT, 4
		IO 01, 01, newLine, len
		IO 01, 01, ba, baLimit
		IO 01, 01, RESULT+4, 8
	MOV RAX, 60
	MOV RDI, 00
	SYSCALL

HexToASCII:
	MOV byte[cnt], 0x04
	MOV RSI, RESULT
	continue:
		rol ax, 2
		mov bl, al
		and bl, 0x0F
		cmp bl, 09H
		jbe lll
		add bl, 07H
		lll:
			add bl, 30H
		mov [RSI], bl
		inc RSI
		dec byte[cnt]
		jnz continue
	RET















