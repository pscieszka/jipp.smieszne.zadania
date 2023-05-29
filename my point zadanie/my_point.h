#pragma once
struct point
{
	char* name;
	double x, y;
};

point* createPoint();
void freePoint(point* ob);



