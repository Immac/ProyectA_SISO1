
.extern main
	entry Start

Start:
	call main
loop1:
	jmp loop1
