#pragma once
struct MY_TRIP
{
	char* str;
	int rok;
	double koszt;
};

void* tripInit();
void tripFree(void** ptr);
void tripPrint(void* ptr);

