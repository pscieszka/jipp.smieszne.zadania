#include <stdlib.h>
#include "array.h"

size_t array::last = 0;

array* createArray(size_t dim) {
	array* arr = (array*)malloc(dim * sizeof(array));
	if (arr) {
		memset((void*)arr, 0, dim * sizeof(array)); //ustawienie pamieci na 0
	}
	return arr;
}

array* push(array* arr, array* obj) {
	size_t last;
	size_t size = sizeof(arr) / sizeof(arr[0]);
	last = arr[0].last;

	if (last >= size) { // jesli jest za duzo elemeentow w tablicy , trzeba ja zwiekszyc
		arr = (array*)realloc(arr, 2 * size * sizeof(array));
		if (!arr) {
			return NULL;
		}
		memset((void*)(arr + size), 0, size * sizeof(array)); // zerujemy nowo zaalokowana pamiec
	}
	arr[last].data = obj->data;
	arr[last].ptr_free = obj->ptr_free;
	arr[last].ptr_print = obj->ptr_print;
	arr[0].last = ++last;

	return arr;
}
void printArray(array* arr) {
	size_t it, size = arr[0].last;

	for (it = 0; it < size; it++) {
		(*arr[it].ptr_print)(arr[it].data);
	}
}
