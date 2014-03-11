#gpiolib.c

Example library to manage the GPIO lines using the sysfs method

##Output example

	#define GPIO_IN  1
	#define GPIO_OUT 0

	gpioexport(80);
	gpiosetdir(80,GPIO_OUT);
	for (;;) {
		gpiosetbits(80);
		gpioclearbits(80);
	}

##Input example

	#define GPIO_IN  1
	#define GPIO_OUT 0

	gpioexport(80);
	for (;;) {
		printf("%d\n",gpiogetbits(84));
	}
 
