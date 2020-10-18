KDIR = /lib/modules/`uname -r`/build

# https://stackoverflow.com/questions/28936199/why-is-pr-debug-of-the-linux-kernel-not-giving-any-output
# -DDEBUG is essential, demsg will give nothing otherwise.
EXTRA_CFLAGS = -Wall -g -DDEBUG

obj-m        = dummy.o

kbuild:
	make -C $(KDIR) M=`pwd`

clean:
	make -C $(KDIR) M=`pwd` clean
