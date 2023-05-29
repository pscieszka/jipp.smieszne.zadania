#pragma once
#include "my_vert.h"

struct MY_PIRAMID{
	MY_VERTEX* data;
	static size_t last;
};

MY_PIRAMID* create(size_t dim);
void add(MY_PIRAMID* arr, size_t dim);
void freeMemory(MY_PIRAMID* arr, size_t dim);
void printPyramid(MY_PIRAMID* arr, size_t dim);