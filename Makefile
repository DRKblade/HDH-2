KDIR = /lib/modules/`uname -r`/build
.PHONY: all test clean install
all:
	make -C $(KDIR) M=`pwd`
clean:
	make -C $(KDIR) M=`pwd` clean
	rm test
install:
	sudo rmmod rand || sudo insmod rand.ko
test:
	gcc test.c -o test
