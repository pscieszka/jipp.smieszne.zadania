#include <iostream>
#include <stdlib.h>
#include "menu.h"
#include "train.h"
#include "array.h"
#include "car.h"


array* add(array* arr) {
	int j;
	array temp;
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
		temp.data = (void*)tr;
		temp.print = trainPrint;
		temp.free = trainFree;
		arr = push(arr, &temp);
	}
	return arr;
}
void print(array* arr) {
	printArray(arr);
}


