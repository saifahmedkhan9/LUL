#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
static int sum=0;
static int myint = 20;

#define DRIVER_AUTHOR "Saif Ahmed khan"
#define DRIVER_DESC   "A sample driver"

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);    // Who wrote this module?
MODULE_DESCRIPTION(DRIVER_DESC); // What does this module do?

module_param(myint,int,0);

static int __init hello_init(void)
{
	int i;
	printk(KERN_INFO "Series of %d natural numbers :",myint);
	for(i=1;i<=myint;i++)
	{
		sum=sum+i;	
		printk(KERN_INFO " %d ",i);	
	}	
	printk(KERN_INFO "Sum is:%d\n\n\n",sum);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye world\n");

}

module_init(hello_init);
module_exit(hello_exit);
