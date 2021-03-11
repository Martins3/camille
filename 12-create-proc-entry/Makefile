UNAME := $(shell uname -m)

KDIR = /lib/modules/`uname -r`/build

# https://stackoverflow.com/questions/28936199/why-is-pr-debug-of-the-linux-kernel-not-giving-any-output
# -DDEBUG is essential, demsg will give nothing otherwise.
#
obj-m        = mm.o

CFLAGS_mm.o := -DDEBUG -o0

kbuild:
	make -C $(KDIR) M=`pwd`

clean:
	make -C $(KDIR) M=`pwd` clean
