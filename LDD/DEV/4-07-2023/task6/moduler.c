#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/err.h>
dev_t dev=0;
char kb[5096];
static struct cdev mycdev;
static struct class *cdev_class;
static int my_open( struct inode *inode,struct file *file);
static ssize_t my_read(struct file *file,char __user *buffer,size_t len,loff_t *off);
static ssize_t my_write(struct file *file,const char *buffer,size_t len,loff_t *off);
static loff_t my_seek(struct file *file,loff_t len,int a);
static int my_close( struct inode *inode,struct file *file);
static struct file_operations fpos=
{
	.owner		= THIS_MODULE,
	.read		= my_read,
	.write		= my_write,
	.open		= my_open,
	.release	= my_close,
	.llseek		= my_seek,
};


static int my_open( struct inode *inode,struct file *file)
{
	printk("file opened...\n");
	return 0;
}


static ssize_t my_read(struct file *file, char __user *buffer, size_t len, loff_t *off)
{
	copy_to_user(buffer,kb,len);
	printk("read done\n");
	return 0;
}


static ssize_t my_write(struct file *file,const char __user *buffer,size_t len,loff_t *off)
{
	if(len>4096)
		return -1;
	copy_from_user(kb,buffer,len);
	printk("write done\n");
	return 0;
}


loff_t my_seek(struct file *file,loff_t len,int a)
{
	file->f_pos=len;
	printk("lseek done\n");
	return len;
}


static int my_close( struct inode *inode,struct file *file)
{
	printk("file closed...\n");
	return 0;
}


static int __init string_module_entering(void )
{
	printk("TASK1 MODULE INSERTD..\n");
	alloc_chrdev_region(&dev,0,1,"TASK1");
	printk("MAJOR%d\tMINOR%d\n",MAJOR(dev),MINOR(dev));
	cdev_init(&mycdev,&fpos);
	cdev_add(&mycdev,dev,1);
	cdev_class=class_create(THIS_MODULE,"my_module");
	device_create(cdev_class,NULL,dev,NULL,"TASK1");
	return 0;
}
static void __exit string_module_exiting(void)
{
	device_destroy(cdev_class,dev);
	class_destroy(cdev_class);
	cdev_del(&mycdev);
	unregister_chrdev_region(dev,1);

	printk("TASK1 REMOVED .....\n");
}


module_init(string_module_entering);
module_exit(string_module_exiting);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("KAMAL");
MODULE_DESCRIPTION("daily_task");
