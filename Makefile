all: k-only syscall-test
include syscall-test.mk
run: all
	bochs -f opsys.bxrc
k-only: krnl
include kernel.mk
clean:
	rm -f *.o
	rm -f *.bin
