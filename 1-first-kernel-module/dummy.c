#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Martins3");
MODULE_LICENSE("GPL");

static int dummy_init(void) {
  void *write_addr;
  write_addr = (void *)0xffffffff812def00;

  pr_debug("write address: %p\n", (void *)0xffffffff812def00);
  pr_debug("write address: %px\n", (void *)0xffffffff812def00);
  return 0;
}

static void dummy_exit(void) { pr_debug("Bye\n"); }

module_init(dummy_init);
module_exit(dummy_exit);
