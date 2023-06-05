#include <iostream>
#include <stdlib.h>
#include "vector.h"

vector* createVector() {
	vector* vec = (vector*)malloc(sizeof(vector));
	if (vec) {
		printf("Podaj nazwe wektora:");
		scanf_s("%s", vec->str, sizeof(vec->str));
		printf("Podaj wielkosc wektora:");
		scanf_s("%d", &(vec->dim));
		vec->buff = (double*)malloc(vec->dim * sizeof(double));
		if (vec->buff) {
			printf("Wpisz dane dla wektora %s :\n",vec->str);
			for (size_t i = 0; i < vec->dim; i++) {
				printf("Podaj wartosc nr %zu:", i);
				scanf_s("%lf", &(vec->buff[i]));
			}
		}
		else {
			free(vec);
			return NULL;
		}

	}

	return vec;
}
/*
void processVectors(vector* vecArray, size_t size) {
	// Przyk³adowa implementacja funkcji
	for (size_t i = 0; i < size; i++) {
		vector* vec = &vecArray[i];
		// Wykonaj operacje na vec
		printf("Wektor %s, wymiar: %d\n", vec->str, vec->dim);
		for (int j = 0; j < vec->dim; j++) {
			printf("Wartosc nr %d: %.2lf\n", j, vec->buff[j]);
		}
		printf("\n");
	}
}
*/
void dotProduct(vector* vecArray, size_t size) {
	if (size < 2) {
		printf("Tablica musi zawierac co najmniej dwa wektory.\n");
		return;
	}
	double result = 0.0;
	for (int i = 0; i < vecArray[0].dim; i++) {
		result += vecArray[0].buff[i] * vecArray[1].buff[i];
	}
	printf("Iloczyn skalarny dla pierwszego i drugiego wektora: %.2lf\n", result);
}
void freeVector(vector* vec) {
	if (vec) {
		if (vec->buff) {
			free(vec->buff); 
		}
	}
}