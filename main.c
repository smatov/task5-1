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

void getfloat(float *point) {
	int *fp = malloc(sizeof(char));
	int *sp = malloc(sizeof(char));
	int *tp = malloc(sizeof(char));
	int l=xgetfloat(point, fp, sp, tp);
	free(fp);
	free(sp);
	free(tp);
	if(l<0) exit(1);

}


char getintseq(int *fp, char c) {
	while (isdigit(c)) {
		*fp = *fp * 10 + (c - '0');
		if (!(c = getchar()))
			return c;
	}
	return c;
}

int xgetfloat(float *point, int *fp, int *sp, int *tp) {
	float ans = 0;
	char c;
	int f = 0;
	int sg = 1;
	float cnt = 1.0;
	*fp = 0;
	*sp = 0;
	*tp = 0;
	printf("Enter float value\n");
	/*integer part*/

	c = getchar();
	if (c == '-' || c == '+') {
		sg = c == '-' ? -1 : 1;
		c = getchar();
		c = getintseq(fp, c);

		if (c == '\n') {
			ans = *fp;
			ans *= sg;
			*point = ans;
			return 1;
		}
	} else
		c = getintseq(fp, c);

	if (c == '\n') {
		ans = *fp;
		ans *= sg;
		*point = ans;
		return 1;
	}

	if (c == '.') {
		c = getchar();
		while (isdigit(c)) {
			*sp = *sp * 10 + (c - '0');
			cnt *= 10;
			if (!(c = getchar()))
				break;
		}

	} else if (c == 'e' || c == 'E') {
		f = 1;
		c = getchar();
		if (c == '\n') {
			printf("Incorrect data entered\n");
			return -1;
		}
		if (c == '-' || c == '+') {
			sg = c == '-' ? -1 : 1;
			c = getchar();
			while (isdigit(c)) {
				c = getintseq(tp, c);
				if (c == '\n') {
					int x = *tp;
					int st = 1;
					int i;
					for (i = 0; i < x; i++)
						st *= 10;
					ans = *fp;
					ans = (sg > 0) ? (ans * st) : (ans / st);
					*point = ans;

					return 1;
				} else {
					printf("Incorrect data entered\n");
					return -1;
				}
			}
		}
		c = getintseq(tp, c);
		if (c != '\n') {
			printf("Incorrect data entered\n");
			return -1;
		}

	}
	if(c!='\n')
	{
		printf("Incorrect data entered\n");
		return -1;
	}

	if (f == 0) {
		ans = *fp + ((float)*sp)/cnt;
		ans *= sg;
		*point = ans;
		return 1;
	} else {
		int x = *tp;
		int st = 1;
		int i;
		for (i = 0; i < x; i++)
			st *= 10;
		ans = *fp;
		ans *= st;
		*point = ans;
		return 1;

	}
}

int main() {
	float *f = malloc(sizeof(char));
	getfloat(f);
	float x;
	x = *f;
	printf("%.6f\n", x);
	free(f);
	return 0;
}
