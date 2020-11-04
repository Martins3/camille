#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Martins3");
MODULE_LICENSE("GPL");

void print_address(void) {
  void *write_addr;
  write_addr = (void *)0xffffffff812def00;

  pr_debug("write address: %p\n", (void *)0xffffffff812def00);
  pr_debug("write address: %px\n", (void *)0xffffffff812def00);
}

static int a1=10;
module_param(a1,int,0660);

static int a2=10;
module_param(a2,int,0660);

static int a3=10;
module_param(a3,int,0660);

static int a4=10;
module_param(a4,int,0660);

static int a5=10;
module_param(a5,int,0660);

static int a6=10;
module_param(a6,int,0660);

static int a7=10;
module_param(a7,int,0660);

static int a8=10;
module_param(a8,int,0660);

int square(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
  return a1 - a2 * a3 + a4 + a5 + a6 + a7 + a8;
}

static int dummy_init(void) {
  int a;
  a1 ++;
  a2 --;
  a = square(a1, a2, a3, a4, a5, a6, a7, a8);
  print_address();
  pr_debug("%d\n", a);
  return 0;
}

static void dummy_exit(void) { pr_debug("Bye\n"); }

module_init(dummy_init);
module_exit(dummy_exit);
