[org 0x7c00]

mov ah, 0x0e

; initialize stack
mov bp, 0x8000   ; stack base
mov sp, bp       ; stack pointer starts at base

; push two bytes into the stack
mov al, 'A'
push ax           ; stack now contains 'A'

mov al, 'B'
push ax           ; stack now contains 'B', then 'A'

; print second pushed element (top of stack: 'B')
pop bx            ; bx = 'B'
mov al, bl
int 0x10

; print first pushed element (next in stack: 'A')
pop bx            ; bx = 'A'
mov al, bl
int 0x10

jmp $

; padding
times 510 - ($ - $$) db 0
dw 0xaa55
