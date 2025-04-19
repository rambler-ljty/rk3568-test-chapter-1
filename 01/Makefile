# ===============================
# Linux内核模块的Makefile
# 用于编译helloworld.ko内核模块
# ===============================

# 指定目标架构为arm64
# ARCH变量告诉编译系统目标平台的CPU架构
export ARCH=arm64

# 指定交叉编译工具链前缀
# CROSS_COMPILE变量定义了使用的交叉编译器的前缀
# aarch64-none-linux-gnu- 用于编译ARM64架构的裸机或嵌入式Linux系统
export CROSS_COMPILE=aarch64-none-linux-gnu-

# 指定要编译的模块
# obj-m 表示将源文件编译为模块（.ko文件）
# 如果是obj-y，则会被编译进内核
obj-m += helloworld.o

# 指定内核源码的位置
# KDIR变量定义了Linux内核源码的目录路径
KDIR :=/home/topeet/Linux/linux_sdk/kernel

# 获取当前目录路径
# PWD变量保存当前工作目录的路径
# ?= 表示如果PWD未定义才赋值
PWD ?= $(shell pwd)

# 默认目标：编译模块
# make -C $(KDIR) 改变到内核源码目录
# M=$(PWD) 指定外部模块的源码目录
# modules 指定编译目标为模块
all:
	make -C $(KDIR) M=$(PWD) modules

# 清理目标：清除所有编译生成的文件
# 包括.o文件、.ko文件、.mod.c文件等
clean:
	make -C $(KDIR) M=$(PWD) clean

# ===============================
# 使用说明：
# 1. 编译模块：make
# 2. 清理文件：make clean
#
# 注意事项：
# 1. 确保KDIR路径指向正确的内核源码目录
# 2. 确保已安装正确的交叉编译工具链
# 3. 确保ARCH变量与目标平台匹配
# ===============================
