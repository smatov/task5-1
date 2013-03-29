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

void addstr(char *s, char *t){
	while(*s++!='\0');
	while((*s++=*t++)!='\0');
}

void getfloat(float *point) {
	float ans = 0;
	int *fp = malloc(sizeof(char));
	int *sp = malloc(sizeof(char));
	int *tp = malloc(sizeof(char));
	char c;
	int f = 0;
	int sg = 1;
	int cnt = 1;
	printf("Enter float value\n");
	/*integer part*/

	c = getchar();
	if (c == '-' || c == '+') {
		sg = c == '-' ? -1 : 1;
		c = getchar();
		if (c >= '0' && c <= '9')
			while (c >= '0' && c <= '9') {
				*fp = *fp * 10 + (c - '0');
				if (!(c = getchar()))
					break;

				if (c == '\n') {
					ans = *fp;
					ans *= sg;
					*point = ans;
					free(fp);
					free(sp);
					free(tp);
					return;
				}
			}
	} else if (c >= '0' && c <= '9')
		while (c >= '0' && c <= '9') {
			*fp = *fp * 10 + (c - '0');
			if (!(c = getchar()))
				break;

			if (c == '\n') {
				ans = *fp;
				ans *= sg;
				*point = ans;
				free(fp);
				free(sp);
				free(tp);
				return;
			}
		}
	else {
		printf("Incorrect data entered\n");
		exit(1);
	}

	if (c == '\n') {
		ans = *fp;
		ans *= sg;
		*point = ans;
		free(fp);
		free(sp);
		free(tp);
		return;
	}
	if (c == '.') {
		c = getchar();
		if (c >= '0' && c <= '9')
			while (c >= '0' && c <= '9') {
				*sp = *sp * 10 + (c - '0');
				cnt *= 10;
				if (!(c = getchar()) || c == '\n')
					break;

			}

	} else if (c == 'e') {
		f = 1;
		c = getchar();
		if (c == '\n') {
			printf("Incorrect data entered\n");
			exit(1);
		}
		if (c == '-' || c == '+') {
			sg = c == '-' ? -1 : 1;
			c = getchar();
			if (c >= '0' && c <= '9')
				while (c >= '0' && c <= '9') {
					*tp = *tp * 10 + (c - '0');
					if (!(c = getchar()))
						break;

					if (c == '\n') {

						int x = *tp;
						int st = 1;
						int i;
						for (i = 0; i < x; i++)
							st *= 10;
						ans = *fp;
						ans = (sg > 0) ? (ans * st) : (ans / st);
						*point = ans;
						free(fp);
						free(sp);
						free(tp);
						return;
					} else {
						printf("Incorrect data entered\n");
						exit(1);
					}
				}
		}

		if (c >= '0' && c <= '9')
			while (c >= '0' && c <= '9') {
				*tp = *tp * 10 + (c - '0');
				if (!(c = getchar()) || c == '\n')
					break;

			}
		if (c != '\n') {
			free(fp);
			free(sp);
			free(tp);
			printf("Incorrect data entered\n");
			exit(1);
		}

	} else {
		free(fp);
		free(sp);
		free(tp);
		printf("Incorrect data entered\n");
		exit(1);
	}

	if (f == 0) {
		ans = *fp + ((float) *sp) / cnt;
		ans *= sg;
		free(fp);
		free(sp);
		free(tp);
		*point = ans;
		return;
	} else {
		int x = *tp;
		int st = 1;
		int i;
		for (i = 0; i < x; i++)
			st *= 10;
		ans = *fp;
		ans *= st;
		free(fp);
		free(sp);
		free(tp);
		*point = ans;
		return;

	}
}

int main() {
	/*float *f = malloc(sizeof(char));
	getfloat(f);
	float x;
	x = *f;
	printf("%.9f\n", x);
	free(f);*/
	char *a="abc";
	char *b="123";
	addstr(a,b);
	*a='1';
	return 0;

}
