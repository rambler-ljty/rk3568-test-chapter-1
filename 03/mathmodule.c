#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

int num = 10;
EXPORT_SYMBOL(num);

int add(int a,int b)
{
	return a+b;
}

EXPORT_SYMBOL(add);


static int __init math_init(void)
{
	printk("math_module init\n");
	return 0;
}


static void __exit math_exit(void)
{
	printk("math_module exit\n");
}

module_init(math_init);
module_exit(math_exit);
MODULE_LICENSE("GPL V2");
MODULE_AUTHOR("topeet");
