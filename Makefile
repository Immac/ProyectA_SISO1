all: floppya.img
run: all
	bochs -f opsys.bxrc
kernel.bin: kernel.o directprint.o kernel-asm.o 
	ld86 -o $@ -d $^
directprint.o: src/directprint.c
	bcc -ansi -c -o $@ $^
kernel.o: src/kernel.c 
	bcc -ansi -c -o $@ $^
kernel-asm.o: src/kernel.asm
	as86 $< -o $@
bootload.bin: src/bootload.asm
	nasm $< -f bin -o $@
floppya.img: bootload.bin kernel.bin
	dd if=/dev/zero of=floppya.img bs=512 count=2880
	dd if=bootload.bin of=floppya.img bs=512 count=1 conv=notrunc
	dd if=kernel.bin of=floppya.img bs=512 seek=3 conv=notrunc
clean:
	rm -f *.o
	rm -f *.bin