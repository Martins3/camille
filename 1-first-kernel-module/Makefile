KDIR = /lib/modules/`uname -r`/build

# https://stackoverflow.com/questions/28936199/why-is-pr-debug-of-the-linux-kernel-not-giving-any-output
# -DDEBUG is essential, demsg will give nothing otherwise.
#
obj-m        = dummy.o

CFLAGS_dummy.o := -DDEBUG -o0

kbuild:
	make -C $(KDIR) M=`pwd`

clean:
	make -C $(KDIR) M=`pwd` clean
