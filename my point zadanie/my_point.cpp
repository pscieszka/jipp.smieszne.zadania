#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "my_point.h"


point* createPoint() {
	point* pkt = (point*)malloc(sizeof(point));
	char str[32]="";
	double x2=0, y2=0;
	printf("Podaj nazwe punktu:");
	scanf_s("%s", str, sizeof(str));
	printf("Podaj punkty x i y:");
	scanf_s("%lf", &x2);
	scanf_s("%lf", &y2);


	if (pkt) {
		pkt->name = (char*)malloc((strlen(str) + 1) * sizeof(char));
		if (!pkt->name) {
			free(pkt);
			return NULL;
		}
		strcpy_s(pkt->name, strlen(str) + 1, str);
		pkt->x = x2;
		pkt->y = y2;


	}
	return pkt;
}
void freePoint(point* ob) {
	if (ob) free(ob);
}