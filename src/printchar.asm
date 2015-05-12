
	.global _printChar
_printChar:
	push bp
	mov bp,sp
	mov al,[bp + 4]
	mov ah,#0x0e
	int #0x10
	pop bp
	ret

