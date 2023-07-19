#include<linux/kernel.h>
#include<linux/init.h>
//#include<linux/exit.h>
#include<linux/fs.h>
#include <linux/module.h>                  //EE HEADER FOLE MUKHYAM BIGILU//
//static int __init hello_init(void);
//static void __exit hello_exit(void);


dev_t dev=MKDEV(235,0);

//init function

static int __init hello_init(void)
{
	register_chrdev_region(dev,1,"morning");
	printk(KERN_INFO "major=%d\t minor=%d",MAJOR(dev),MINOR(dev));
	printk(KERN_INFO "kernel module inserted succusfullly");
	return 0;
}
//exit function

static void __exit hello_exit(void)
{
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO"kernel module remove succusfully");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GIRI=SH");
MODULE_DESCRIPTION("STATICALLY ALLOCATED MAJOR AND MINOR NUMBER");
//MODULE_VERSION("5.4.0");

