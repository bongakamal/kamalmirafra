#include<linux/gfp.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/err.h>
#include "header.h"
#include <linux/slab.h>
#define SIZE 100
dev_t dev;
char *a,*b;
int l=100;
static struct class *class;
static struct cdev cdev;
static int myopen(struct inode *inode,struct file *file);
static ssize_t myread(struct file *file,char __user *ub,size_t len,loff_t *off);

static ssize_t mywrite(struct file *file,const char *ub,size_t len,loff_t *off);
static long myioctl (struct file *, unsigned int cmd, unsigned long l);

static loff_t myseek(struct file *file,loff_t len,int a);
static int myclose(struct inode *inode,struct file *file);
static struct file_operations fops = {
	.owner=THIS_MODULE,
	.open=myopen,
	.read=myread,
	.write=mywrite,
	.release=myclose,
	.llseek=myseek,
	.unlocked_ioctl=myioctl,
};

static int myopen(struct inode *inode,struct file *file)
{
	printk("OPEN......\n");
	return 0;
}
static long myioctl (struct file *file, unsigned int cmd, unsigned long l)
{
	//int i;
	unsigned long v;
	//a=kmalloc(SIZE,GFP_KERNEL);
	//	copy_from_user((char*)&v,(char*)&l,4);
#if 1
	printk("1::kamal\n");
/*	switch(cmd)
	{
		case PLAY:
			for(i=0;i<SIZE;i++)
				a[i]='*';
			a[i]='\0';
			printk("2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::2::kamal\n");
			copy_to_user((char*)l,a,strlen(a)-1);
			printk("2::kamal\n");
			printk("%s\n",a);
			printk("%s\n",(char*)l);
			printk("%d\n",strlen(a));
			break;
		case PAUSE:*/
			copy_from_user((char*)&v,(char*)l,sizeof(v));
			printk("kkv::%c\n",(char)v);
			printk("kklc::%c\n",*(char*)l);
			printk("kkld::%ld\n",*(unsigned long*)l);
			printk("kldp::%p\n",(unsigned long*)l);
/*			break;
		case NXT:
			copy_from_user((char*)&v,(char*)l,sizeof(v));
			break;
		case PRE:
				kfree(a);
			//SIZE=20;
			b=kmalloc(SIZE,GFP_KERNEL);
			for(i=0;i<SIZE;i++)
				b[i]='*';
				b[i]='\0';
			copy_to_user((char*)l,a,strlen(b)-1);
			
			break;
	}*/
#endif
	#if 0 
printk("l::%lx",l);
	printk("v::%x",v);
	printk("long::%lx",(l>>40));
	  printk("long::%lx",((l>>32)&0xff));
	  printk("long::%lx",((l>>24)&0xff));
	  printk("long::%lx",(l>>16)&0xff);
	  printk("long::%lx",((l>>8)&0xff));
	  printk("long::%lx",(l&(0xff)));*/
	printk("v::%c\n",*((char*)&l));
	printk("v::%c\n",*((char*)((char*)&l+1)));
	printk("v::%c\n",*((char*)((char*)&l+2)));
	printk("v::%c\n",*((char*)((char*)&l+3)));
	printk("char::%d",v);
	printk("char::%c",(char)v);
#endif 
	return 0;
}
static ssize_t myread(struct file *file,char __user *ub,size_t len,loff_t *off)
{
	printk("READ......\n");
	return 0;
}
static ssize_t mywrite(struct file *file,const char *ub,size_t len,loff_t *off)
{
	printk("WRITE......\n");
	return 0;
}
static loff_t myseek(struct file *file,loff_t len,int a)
{
	printk("SEEK......\n");
	return 0;

}
static int myclose(struct inode *inode,struct file *file)
{
	printk("CLOSE......\n");
	return 0;
}
static int __init module_enter(void)
{
	printk("module entered..\n");
	alloc_chrdev_region(&dev,0,1,"ioctl1");
	cdev_init(&cdev,&fops);
	cdev_add(&cdev,dev,1);
	class=class_create(THIS_MODULE,"PRACTISE");
	device_create(class,NULL,dev,NULL,"ioctl1");
	return 0;
}
static void __exit module_exiti(void)
{
	device_destroy(class,dev);
	class_destroy(class);
	cdev_del(&cdev);
	unregister_chrdev_region(dev,1);
}
module_init(module_enter);
module_exit(module_exiti);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("KAMAL");
MODULE_DESCRIPTION("IOCTL_TASK_1");
