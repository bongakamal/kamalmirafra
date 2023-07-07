#include <linux/init.h>
#include <linux/module.h>
#include<linux/kernel.h>
extern void fun(void);
void kamal(void);
void kamal(void)
{
	printk("add function called");
	printk("fun is callin...");
//	fun();
}

static int __init driver_start(void)
{
	printk(KERN_INFO "Driver has started by KAMAL\n");
	printk("add is callin...");
	fun();
	kamal();

	return 0;
}

static void __exit driver_exit(void)
{
	printk(KERN_INFO "Exiting the Driver which has started by KAMAL\n");
}

module_init(driver_start);
module_exit(driver_exit);

MODULE_LICENSE("4440");
MODULE_AUTHOR("Kamal Reddy");
MODULE_DESCRIPTION("A SMAPLE");


