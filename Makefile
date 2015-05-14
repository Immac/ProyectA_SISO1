all: floppya.img
run: all
	bochs -f opsys.bxrc
kernel.bin: kernel.o kernel-asm.o printchar.o readchar.o screenutils.o directprint.o readsector.o
	ld86 -o $@ -d $^
kernel.o: src/kernel.c 
	bcc -ansi -c -o $@ $^
screenutils.o: src/screenutils.c
	bcc -ansi -c -o $@ $^
directprint.o: src/directprint.c
	bcc -ansi -c -o $@ $^
readsector.o: src/readsector.asm
	as86 $< -o $@
printchar.o: src/printchar.asm
	as86 $< -o $@
readchar.o: src/readchar.asm
	as86 $< -o $@
kernel-asm.o: src/kernel.asm
	as86 $< -o $@
bootload.bin: src/bootload.asm
	nasm $< -f bin -o $@
floppya.img: bootload.bin kernel.bin
	dd if=/dev/zero of=floppya.img bs=512 count=2880
	dd if=bootload.bin of=floppya.img bs=512 count=1 conv=notrunc
	dd if=kernel.bin of=floppya.img bs=512 seek=3 conv=notrunc
	dd if=message.txt of=floppya.img bs=512 count=1 seek=30 conv=notrunc
clean:
	rm -f *.o
	rm -f *.bin