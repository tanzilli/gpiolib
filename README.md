#gpiolib.c

Example library to manage the GPIO lines using the sysfs method

##Output example

	gpioexport(85);
	gpiosetdir(85,GPIO_OUT);
	for (;;) {
		gpiosetbits(85);
		gpioclearbits(85);
	}

##Input example

	gpioexport(84);
	for (;;) {
		printf("%d\n",gpiogetbits(84));
	}
 
