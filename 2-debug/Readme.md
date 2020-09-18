## debug kernel

1. objdump : /proc/modules
```c
sudo cat /proc/modules
objdump -dS --adjust-vma=0xffffffffc1011000 oops.ko 
```
2. oops : demsg
3. addr2line -e oops.o 0x5
4. minicom : ???

5. netconsole


