#pragma once

#include "my_point.h"
struct poligon
{
	char figura[32];
	size_t dim;
	point* wierzcholki;
};

poligon* create();
void print(poligon* ob);
	



