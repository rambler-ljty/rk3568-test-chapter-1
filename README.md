# rk3568-test-chapter-1

01  内核模块test

-- insmod  rmmod  lsmod

02 传参 test

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


