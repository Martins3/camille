KDIR = /lib/modules/`uname -r`/build
CC=clang

# https://stackoverflow.com/questions/28936199/why-is-pr-debug-of-the-linux-kernel-not-giving-any-output
# -DDEBUG is essential, demsg will give nothing otherwise.
#
obj-m        = dummy.o

kbuild:
	make -C $(KDIR) M=`pwd`

clean:
	make -C $(KDIR) M=`pwd` clean
