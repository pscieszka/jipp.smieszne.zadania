#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "my_point.h"
#include "my_poligon.h"


poligon* create() {
	poligon* pol = (poligon*)malloc(sizeof(poligon));
	if (pol) {
		printf("Podaj nazwe poligonu:");
		scanf_s("%s", pol->figura, sizeof(pol->figura));
		printf("Podaj ilosc wierzcholkow:");
		scanf_s("%zu", &(pol->dim));
		pol->wierzcholki = (point*)malloc(pol->dim * sizeof(point));
		if (pol->wierzcholki) {
			for (size_t i = 0; i < pol->dim; i++) {
				point* pkt = createPoint();
				pol->wierzcholki[i] = *pkt ;
			}
		}
		else {
			free(pol);
			return NULL;
		}
		
	}
	return pol;
}
void print(poligon* ob) {
	if (ob) {
		printf("Nazwa poligonu: %s\n", ob->figura);
		printf("Ilosc wierzcholkow: %zu\n", ob->dim);

		printf("Wierzcholki:\n");
		for (size_t i = 0; i < ob->dim; i++) {
			printf("Wierzcholek %zu:\n", i + 1);
			printf("Nazwa: %s\n", ob->wierzcholki[i].name);
			printf("Punkt x: %lf\n", ob->wierzcholki[i].x);
			printf("Punkt y: %lf\n", ob->wierzcholki[i].y);
		}
	}
}
void free(poligon* ob) {
	if (ob) {
		if (ob->wierzcholki) {
			for (size_t i = 0; i < ob->dim; i++) {
				freePoint(&(ob->wierzcholki[i]));
			}
			free(ob->wierzcholki);
		}
		free(ob);
	}
}
