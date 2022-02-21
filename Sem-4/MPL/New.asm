%macro IO 4  ; simple macro ,
mov rax,%1   ;  param 1 ->  system call number                             
mov rdi,%2    ;  param 2 ->  file descriptor                              
mov rsi,%3     ;  param 3 ->  message                       
mov rdx,%4      ;  param 4 ->  length                         
syscall                                   
%endmacro
section .data
    m1 db "enter string",10    ;10 ->line feed 
    l1 equ $-m1                         
    m2 db "Entered",10    
    l2 equ $-m2                         
    m3 db "Length is ",10            
    l3 equ $-m3 
    m4 db "Write an X86/64 ALP to accept a string and to display its length" ,10  
    l4 equ $-m4
    m5 db "Exiting now" ,10    
    l5 equ $-m5
    m6 db "rahul ghosh 3236" ,10    
    l6 equ $-m6
    m7 db 10    
section .bss
    string resb 50                      ;string array of size 50
    strl equ $-string 
    count resb 1
    _output resb 20
section .text
    global _start

_start:
    IO 1,1,m6,l6    ; display
    IO 1,1,m4,l4    ; display
    IO 1,1,m1,l1    ; display
 input:
    IO 0,0,string,strl
    mov [count],rax ;count now points to rax 
 output:
    IO 1,1,m2,l2    ; display
    IO 1,1,string,strl
    IO 1,1,m3,l3    ; display 
    mov rax,[count] ; value of count passed into rax   
    call hex_to_dec
    IO 1,1,_output,16
    IO 1,1,m7,1
 exit:
    IO 1,1,m5,l5     
    mov rax, 60     ; system call for exit
    mov rdi, 0      ; exit code 0
    syscall

hex_to_dec:
        mov rsi,_output+15  ; max size of display , for convinience set to 16 and rsipoints to output[16]
        mov rcx,2           ; loop count , or number of digits displayed , 2 digits (unlikely we will enter string > 99)(prints preceding zeros otherwise)
    letter2:	
        xor rdx,rdx         ; setting rdx to null without setting a null byte (a tip i saw on reddit) needed to clean dl for use 
        mov rbx,10          ; conversion base
        div rbx             ; dividing by conversion base
        cmp dl,09h          ; comparing 09h with dl , since the division remainder ends up in dx and since its one digits its in dl
        jbe add30           ; if value under in 0-9 , we directly add 30h to get ascii 0-9
    add30:	
        add dl,30h          ; adding 30h
        mov [rsi],dl        ; moving the ascii we generated to rsi
        dec rsi             ; rsi now points to the next place in display or output[n-1]
        dec rcx             ; loop 
        jnz letter2
ret