export ARCH=arm64
export CROSS_COMPILE=aarch64-none-linux-gnu-
obj-m += mathmodule.o
obj-m += hello.o
KDIR :=/home/topeet/Linux/linux_sdk/kernel
PWD ?= $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
