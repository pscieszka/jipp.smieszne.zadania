#pragma once
struct train
{
	char* trace;
};

void* trainInit();
void trainFree(void** ptr);
void trainPrint(void* ptr);

