/* ----------------------------------------------------------------------------
 * gpiolib.c - Example library to manage the GPIO lines using
 *             the sysfs method
 *
 * Copyright (c) 2013 Sergio Tanzilli
 * All rights reserved.
 *
 * http://www.acmesystems.it
 * Sergio Tanzilli - tanzilli@acmesystems.it
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" IN THE SAME 
 * TERMS OF THE ORIGINAL DISCLAIMER LISTED BELOW.
 * PLAYING DIRECTLY WITH CPU REGISTER CAN RESULT IN UNPREDICTABLE RESULTS
 * AND CAN EVEN RESULT IN DAMAGE OF THE CPU AND/OR THE ATTACHED HARDWARE.
 * ----------------------------------------------------------------------------
 */

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int gpioexport(int gpioid) {
	FILE *filestream;
 
	if ((filestream=fopen("/sys/class/gpio/export","w"))==NULL) {
		printf("Error on export GPIO\n");
		return -1;
	}	
	fprintf(filestream,"%d",gpioid);
	fclose(filestream);
	return 0;
}
 
int gpiosetdir(int gpioid,int mode) {
	FILE *filestream;
	char filename[50];
 
	sprintf(filename,"/sys/class/gpio/gpio%d/direction",gpioid);
	if ((filestream=fopen(filename,"w"))==NULL) {
		printf("Error on direction setup\n");
		return -1;
	}	
	if (mode==GPIO_IN) {
		fprintf(filestream,"in");
	} else {
		fprintf(filestream,"out");
	}
	fclose(filestream);
	return 0;
}
 
int gpiogetbits(int gpioid) {
	FILE *filestream;
	char filename[50];
	char retchar;
 
	sprintf(filename,"/sys/class/gpio/gpio%d/value",gpioid);
	if ((filestream=fopen(filename,"r"))==NULL) {
		printf("Error on gpiogetbits %d\n",gpioid);
		return -1;
	}	
	retchar=fgetc(filestream);
	fclose(filestream);
	if (retchar=='0') return 0;
	else return 1;
}
 
int gpiosetbits(int gpioid) {
	FILE *filestream;
	char filename[50];
 
	sprintf(filename,"/sys/class/gpio/gpio%d/value",gpioid);
	if ((filestream=fopen(filename,"w"))==NULL) {
		printf("Error on setbits %d\n",gpioid);
		return -1;
	}	
	fprintf(filestream,"1");
	fclose(filestream);
	return 0;
}
 
int gpioclearbits(int gpioid) {
	FILE *filestream;
	char filename[50];
 
	sprintf(filename,"/sys/class/gpio/gpio%d/value",gpioid);
	if ((filestream=fopen(filename,"w"))==NULL) {
		printf("Error on clearbits %d\n",gpioid);
		return -1;
	}	
	fprintf(filestream,"0");
	fclose(filestream);
	return 0;
}

