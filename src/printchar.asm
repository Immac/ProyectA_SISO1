
	.global _printChar
	.global printString
	.extern _printString

_printChar:
	push bp
	mov bp,sp
	mov al,[bp + 4]
	mov ah,#0x0e
	int #0x10
	pop bp
	ret

printString:
	push bx
	call #_printString
	add sp, #0x2
	ret
