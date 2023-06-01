#pragma once
typedef void (*ptr_print)(void* pdat);
typedef void (*ptr_free)(void** pdat); // wskaznik do wskaznika, a nie danych
struct array
{
	void* data;
	ptr_free free;
	ptr_print print;
	static int last;
};

array* createArray(size_t dim);
array* push(array* arr, array* obj);
void printArray(array* arr);
