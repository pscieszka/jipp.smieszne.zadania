
#include <iostream>
#include <stdlib.h>
#include "array.h"
#include "train.h"
array* add(array* arr);

int main()
{
	int n;
	int i;
	array* arr = createArray(4);
	printf("Podaj wielkosc tablicy:");
	scanf_s("%d", &n);
	while (1) {
		printf("\n 0 - DODAJ OBIEKT\n1-WYDRUKUJ TABLICE\n2-KONIEC\n");
		if (scanf_s("%d", &i) == 1) {
			switch (i) {
			case 0:
				
				
			case 1:

			case 2:
				return 0;
			default:
				printf("Zly wybor\n");
			};
		}
	}
}
array* add(array* arr) {
	int j;
	printf("\n0 - CAR\n1 - TRAIN\n");
	scanf_s("%d", &j);
	if (j == 0) {

	}

	else {
		train* tr = NULL;
		tr = (train*)malloc(sizeof(train));
		if (!tr) {
			printf("Memory allocation error\n");
		}
		tr = (train*)trainInit();
	}
}


