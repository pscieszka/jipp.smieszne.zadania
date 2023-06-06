#pragma once
#include "my_student.h"
struct MY_GROUP
{ 
	char nazwa[32];
	size_t size;
	MY_STUDENT* tab;
};

MY_GROUP* createGroup();
void printGroup(MY_GROUP* group);
void freeGroup(MY_GROUP* group);
