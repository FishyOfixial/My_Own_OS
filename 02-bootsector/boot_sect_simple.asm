; boot_sect_simple.asm

; Un loop infinito

loop:
	jmp loop

; Rellenar con ceros hasta el byte 510
times 510 - ($ - $$) db 0

; Firma magica para indiciar que es un boot sector valido
dw 0xAA55
