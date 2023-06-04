#pragma once
struct car
{
	char* model;
	int year;
	
};

void* carInit();
void carFree(void** ptr);
void carPrint(void* ptr);



