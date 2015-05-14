syscall-test: floppya.img syscall-test.bin
	dd if=syscall-test.bin of=floppya.img bs=512 count=1 seek=11 conv=notrunc
syscall-test.bin: syscall-test.o os-api.o
	ld86 -o $@ -d $^
syscall-test.o: src/syscall-test/syscalltest.c
	bcc -ansi -c -o $@ $<
os-api.o: src/os-api.asm
	as86 -o $@ $<
