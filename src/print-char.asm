.global _printChar
_printChar:
    mov al,[bp+2]
    mov ah,#0x0e
    int #0x10
    ret