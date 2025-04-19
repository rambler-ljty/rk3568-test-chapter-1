/* 包含必要的头文件 */
#include<linux/init.h>     // 提供初始化和退出的宏定义
#include<linux/module.h>   // 提供模块相关的功能

/* 定义模块的各种参数 */
static int number;         // 定义一个整型参数
static char *name;         // 定义一个字符串指针参数
static int para[8];        // 定义一个最大长度为8的整型数组参数
static char str1[10];      // 定义一个最大长度为10的字符串参数
static int n_para;         // 用于记录para数组实际传入的参数个数

/* 注册模块参数 */
// S_IRUGO表示参数只读权限（所有用户都可读）
module_param(number, int, S_IRUGO);                    // 注册整型参数number
module_param(name, charp, S_IRUGO);                    // 注册字符串指针参数name
module_param_array(para, int, &n_para, S_IRUGO);       // 注册整型数组参数para，n_para将获取实际传入的参数个数
module_param_string(str, str1, sizeof(str1), S_IRUGO); // 注册字符串参数str，使用str1接收，最大长度为sizeof(str1)

/* 模块初始化函数 */
static int __init parameter_init(void)
{
	static int i;  // 循环计数器

	// 打印整型参数
	printk(KERN_EMERG"%d\n", number);
	// 打印字符串参数
	printk(KERN_EMERG"%s\n", name);

	// 循环打印数组参数
	for(i=0; i<n_para; i++)
	{
		printk(KERN_EMERG"para[%d]:%d\n", i, para[i]);    
	}

	// 打印字符串参数
	printk(KERN_EMERG"%s\n", str1);
	return 0;  // 返回0表示初始化成功
}

/* 模块清理函数 */
static void __exit parameter_exit(void)
{
	// 模块卸载时打印信息
	printk(KERN_EMERG"parameter_exit\n");
}

/* 注册模块的初始化和清理函数 */
module_init(parameter_init);  // 注册初始化函数
module_exit(parameter_exit);  // 注册清理函数

/* 模块许可证和作者信息 */
MODULE_LICENSE("GPL V2");     // 声明模块使用GPL V2许可证
MODULE_AUTHOR("topeet");      // 声明模块作者

/*
 * 使用示例：
 * 加载模块：insmod parameter.ko number=100 name="test" para=1,2,3 str="hello"
 * 卸载模块：rmmod parameter
 * 查看输出：dmesg
 *
 * 参数说明：
 * number  - 任意整数值
 * name    - 任意字符串
 * para    - 最多8个整数，用逗号分隔
 * str     - 最大长度为10的字符串
 */

##
