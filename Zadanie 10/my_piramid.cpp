#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "my_piramid.h"
#include "my_vert.h"

size_t MY_PIRAMID::last = 0;


MY_PIRAMID* create(size_t dim) {
	MY_PIRAMID* arr = (MY_PIRAMID*)malloc(dim *sizeof(MY_PIRAMID));
	if (arr) {
		memset(arr, 0, dim * sizeof(MY_PIRAMID));
	}
	return arr;
}
void add(MY_PIRAMID* arr, size_t dim) {
	if (arr && dim > 0) {
		for (size_t i = 0; i < dim; i++) {
			MY_VERTEX* vert = Init();
			arr[i].data = (MY_VERTEX*)malloc(sizeof(MY_VERTEX));
			if (arr[i].data) {
				memcpy(arr[i].data, vert, sizeof(MY_VERTEX));
				arr[i].last = ++MY_PIRAMID::last;
			}
			else {
				free(vert);
			}
			vertFree(vert);
		}
	}
}
void freeMemory(MY_PIRAMID* arr, size_t dim) {
	if (arr && dim > 0) {
		for (size_t i = 0; i < dim; i++) {
			if (arr[i].data) {
				vertFree(arr[i].data);
				arr[i].data = NULL;
			}
		}
		free(arr);
		MY_PIRAMID::last = 0;
	}
}
void printPyramid(MY_PIRAMID* arr, size_t dim) {
	if (arr && dim > 0) {
		for (size_t i = 0; i < dim; i++) {
			MY_VERTEX* vert= arr[i].data;
			
			printVertexData(vert);
		}
	}
}

