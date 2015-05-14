
	.global _readSector
	.extern _printChar
_readSector:
	push bp 
	mov bp, sp 
	sub sp, #8
	mov bx, [bp + 4] ;bx = buffer*
	mov ax, [bp + 6] ;ax = sector
	mov dx,ax ;dx = sector
	mov cl, #36
	div cl
	mov [bp - 2],al ;[bp-2] = track
	mov ax,dx ;ax = sector
	mov cl, #18
	div cl
	add ah, #1
	mov [bp - 4],ah ; [bp - 4] = relative sector
	xor ah,ah
	mov cl, #2
	div cl
	mov [bp - 6],ah ;[bp - 6] = head
	mov ah,#0x2
	mov al,#0x1
	mov ch,[bp - 2]
	mov cl,[bp - 4]
	mov dh,[bp - 6]
	mov dl,#0 ; 0 is the floppy disk
	int #0x13
	add sp, #8
	pop bp
	ret
