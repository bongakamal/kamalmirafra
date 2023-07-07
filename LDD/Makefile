#obj-m += mod1.o
#obj-m += mod2.o
obj-m += module3.o
obj-m += module3_mod.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
