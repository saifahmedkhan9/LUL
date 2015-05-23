#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("beingcooper");
MODULE_DESCRIPTION("A Simple Kernel Module");
int a=3, b=4, c=5;  // default values
module_param(a, int, 0);  // command line input for a, b & c
module_param(b, int, 0);
module_param(c, int, 0);

static int __init hello_init(void)
{
    
    if( (c*c) == (a*a) + (b*b))
    printk(KERN_INFO "Traingle with sides %d, %d and %d is a Right Angle Traingle\n",a,b,c);
    else
    printk(KERN_INFO "Traingle with sides %d, %d and %d is NOT Right Angle Traingle\n",a,b,c);
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
