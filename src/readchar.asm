
	.global _readChar
	.global readString

_readChar:
	mov ax,#0x00
	int #0x16
	ret

readString:
	push bx
	call #readString
	add sp,#0x2
	ret
