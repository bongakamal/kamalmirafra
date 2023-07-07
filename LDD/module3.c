#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
int a=10;
EXPORT_SYMBOL(a);
static int __init start(void)
{
	printk("init kamall.....,a");
//	printk("in init %d",a);
	return 0;
}
static void __exit mexit(void)
{
	printk("exited ,a");
}
module_init(start);
module_exit(mexit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("beta");
MODULE_DESCRIPTION("Alpha");


