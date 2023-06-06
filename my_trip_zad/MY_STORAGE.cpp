#include <iostream>
#include<stdlib.h>
#include "MY_TRIP.h"
#include "MY_STORAGE.h"


size_t MY_STORAGE::last = 0;

MY_STORAGE* createArray(size_t dim) {
	MY_STORAGE* arr = (MY_STORAGE*)malloc(dim * sizeof(MY_STORAGE));
	if (arr) {
		memset((void*)arr, 0, dim * sizeof(MY_STORAGE)); //ustawienie pamieci na 0
	}
	return arr;
}

MY_STORAGE* push(MY_STORAGE* arr, MY_STORAGE* obj) {
	size_t last;
	size_t size = sizeof(arr) / sizeof(arr[0]);
	last = arr[0].last;
	if (last >= size - 1) {
		// Oblicz nowy rozmiar tablicy (2 razy większy)
		size_t newSize = size * 2;

		// Reallokuj pamięć dla nowej tablicy o większym rozmiarze
		MY_STORAGE* newArr = (MY_STORAGE*)realloc(arr, newSize * sizeof(MY_STORAGE));
		if (newArr == NULL) {
			// Obsłuż błąd alokacji pamięci
			printf("Błąd alokacji pamięci.");
			return arr;  // Zwróć oryginalną tablicę bez zmian
		}

		// Przypisz nową tablicę do wskaźnika arr
		arr = newArr;

		// Aktualizuj rozmiar tablicy
		size = newSize;
	}

	arr[last].data = obj->data;
	arr[last].free = obj->free;
	arr[last].print = obj->print;
	arr[0].last = ++last;

	return arr;
}
void printArray(MY_STORAGE* arr) {
	size_t it, size = arr[0].last;

	for (it = 0; it < size; it++) {
		(*arr[it].print)(arr[it].data);
	}
}
void freeArray(MY_STORAGE** arr)
{
	if (arr)
	{
		if (*arr)
		{
			size_t it, no_items = (*arr)[0].last;
			for (it = 0; it < no_items; ++it)
			{
				if ((*arr)[it].data != NULL)
				{
					(*(*arr)[it].free)(&(*arr)[it].data);
					(*arr)[it].data = NULL;
				}

				free(*arr);
				*arr = NULL;
			}

			MY_STORAGE::last = 0;
		}
	}
}

MY_STORAGE* add(MY_STORAGE* arr) {
	MY_STORAGE temp;
	MY_TRIP* tr = NULL;
	tr = (MY_TRIP*)malloc(sizeof(MY_TRIP));
	if (!tr) {
		printf("Memory allocation error\n");
	}
	tr = (MY_TRIP*)tripInit();
	temp.data = (void*)tr;
	temp.print = tripPrint;
	temp.free = tripFree;
	arr = push(arr, &temp);
	return arr;
}
void print(MY_STORAGE* arr) {
	printArray(arr);
}