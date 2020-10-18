KDIR = /lib/modules/`uname -r`/build
EXTRA_CFLAGS = -Wall -g -DDEBUG
obj-m        = rcu.o

kbuild:
	make -C $(KDIR) M=`pwd`

clean:
	make -C $(KDIR) M=`pwd` clean
