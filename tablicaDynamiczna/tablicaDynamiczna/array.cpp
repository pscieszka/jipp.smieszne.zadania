#include <iostream>
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


	arr[last].data = obj->data;
	arr[last].free = obj->free;
	arr[last].print = obj->print;
	arr[0].last = ++last;

	return arr;
}
void printArray(array* arr) {
	size_t it, size = arr[0].last;

	for (it = 0; it < size; it++) {
		(*arr[it].print)(arr[it].data);
	}
}
void freeArray(array** arr)
{
	if (arr)
	{
		if (*arr)
		{
			size_t it, no_items = (*arr)[0].last;
			for (it = 0; it < no_items; ++it)
			{
				if ((*arr)[it].data != NULL)  // SprawdŸ, czy wskaŸnik nie jest ju¿ NULL
				{
					(*(*arr)[it].free)(&(*arr)[it].data);
					(*arr)[it].data = NULL;  // Ustaw wskaŸnik na NULL tylko jeœli nie jest ju¿ NULL
				}
			}

			free(*arr);
			*arr = NULL;
		}

		array::last = 0;
	}
}
