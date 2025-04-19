#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

extern int num;
extern int add(int a, int b);


static int __init hello_init(void)
{
	static int sum;
	printk("num = %d\n",num);
	sum = add(3,4);
	printk("sum = %d\n",sum);
	return 0;
}


static void __exit hello_exit(void)
{
	printk("Goodbye hello module\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL V2");
MODULE_AUTHOR("topeet");
