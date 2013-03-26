/*
 * main.c
 *
 *  Created on: 26.03.2013
 *      Author: dev
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

/*char getch() {
	char c;
	scanf("%c",&c);
	return c;
}*/


float getfloat() {
	float ans=0;
	int *fp=malloc(sizeof(char));
	int *sp=malloc(sizeof(char));
	char c;
	int sg = 1;
	int cnt=1;
	printf("Enter float value\n");
	/*integer part*/
	while ((c=getchar()) && c != '.') {
		if (c == '-') {
			sg = -1;
			continue;
		}
		if (c >= '0' && c <= '9') {
			*fp = *fp * 10 + (c - '0');
		} else {
			printf("Incorrect data entered\n");
			exit(1);
		}

	}
	/*other part*/
	if (c == '.')
	{
		while ((c=getchar()) && c != ' '&& c != '\n' && c != EOF) {
			if (c >= '0' && c <= '9') {
						*sp = *sp * 10 + (c - '0');
						cnt*=10;
		} else {
			printf("Incorrect data entered\n");
			exit(1);
			}
		}
	}else {
		printf("The value is not float\n");
		exit(1);
	}
	ans=*fp+((float)*sp)/cnt;
	ans*=sg;
	return ans;

}

int main() {
	float f=getfloat();
	printf("%.4f\n",f);
	return 0;

}
