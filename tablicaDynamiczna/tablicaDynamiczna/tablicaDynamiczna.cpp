
#include <iostream>
#include <stdlib.h>
#include "array.h"
#include "train.h"
#include "menu.h"

int main()
{
	int n;
	int i;
	printf("Podaj wielkosc tablicy:");
	scanf_s("%d", &n);
	array* arr = createArray(n);
	while (1) {
		printf("\n 0 - DODAJ OBIEKT\n1-WYDRUKUJ TABLICE\n2-KONIEC\n");
		if (scanf_s("%d", &i) == 1) {
			switch (i) {
			case 0:
				add(arr);
				break;
			case 1:
				print(arr);
				break;
			case 2:
				if (arr)
				freeArray(&arr);
				return 0;
			default:
				printf("Zly wybor\n");
			};
		}
	}
}
