/*
 * Linux内核模块示例 - Hello World
 * 这是一个最基本的Linux内核模块示例，展示了模块的加载和卸载功能
 */

/* 包含必要的头文件 */
#include<linux/module.h>   // 提供模块相关的功能，如MODULE_LICENSE等宏
#include<linux/kernel.h>   // 提供内核相关的功能，如printk等函数

/**
 * 模块初始化函数
 * 当模块被加载时（使用insmod命令）会调用此函数
 * __init 修饰符表示该函数仅在初始化时使用，初始化完成后该函数占用的内存将被释放
 */
static int __init helloworld_init(void)
{
	/* 
	 * 打印初始化信息
	 * KERN_EMERG 是最高级别的消息优先级
	 * 实际开发中应使用 KERN_INFO 或其他更合适的级别
	 */
	printk(KERN_EMERG"helloworld_init\r\n");
	return 0;  // 返回0表示初始化成功
}

/**
 * 模块清理函数
 * 当模块被卸载时（使用rmmod命令）会调用此函数
 * __exit 修饰符表示该函数仅在模块卸载时使用
 */
static void __exit helloworld_exit(void)
{
	/* 打印退出信息 */
	printk(KERN_EMERG"helloworld_exit\r\n");
}

/* 注册模块的初始化和清理函数 */
module_init(helloworld_init);  // 注册初始化函数
module_exit(helloworld_exit);  // 注册清理函数

/* 模块信息 */
MODULE_LICENSE("GPL V2");      // 声明模块的许可证
MODULE_AUTHOR("topeet");       // 声明模块的作者

/*
 * 使用说明：
 * 1. 编译模块：make
 * 2. 加载模块：sudo insmod helloworld.ko
 * 3. 查看消息：dmesg
 * 4. 卸载模块：sudo rmmod helloworld
 *
 */
