#pragma once
typedef void (*ptr_print)(void* pdat);
typedef void (*ptr_free)(void** pdat);
struct MY_STORAGE
{
	void* data;
	ptr_free free;
	ptr_print print;
	static size_t last;

};


MY_STORAGE* createArray(size_t dim);
MY_STORAGE* push(MY_STORAGE* arr, MY_STORAGE* obj);
MY_STORAGE* add(MY_STORAGE* arr);
void print(MY_STORAGE* arr);
void printArray(MY_STORAGE* arr);
void freeArray(MY_STORAGE** arr);

