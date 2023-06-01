#pragma once
struct car
{
	char* model;
	int year;
	
};

void* carInit();
void carFree(void* ptr);



