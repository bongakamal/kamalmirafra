#obj-m += mod1.o
#obj-m += mod2.o
#obj-m += module3.o
obj-m += t.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
