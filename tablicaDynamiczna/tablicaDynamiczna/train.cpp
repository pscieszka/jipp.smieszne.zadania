#include <iostream>
#include <stdlib.h>

#include "train.h"

void* trainInit() {
	train* pociag = (train*)malloc(sizeof(train));
	if (pociag) {
		char trasa[128];
		printf("Podaj trase pociagu(format: miasto1->miasto2):");
		scanf_s("%s", trasa, sizeof(trasa));
		pociag->trace = (char*)malloc(strlen(trasa)+1);
		if (!pociag->trace) {
			free(pociag);
			return NULL;
		}
		strcpy_s(pociag->trace, strlen(trasa)+1, trasa);
	}
	return (void*)(pociag);
}

void trainFree(void** ptr) {
	if (ptr && *ptr) {
		train* pociag = (train*)(*ptr);
		if (pociag->trace) {
			free(pociag->trace);
			pociag->trace = NULL;
		}
		free(pociag);
		*ptr = NULL;
	}
}

void trainPrint(void* ptr)
{
	train* ptr2 = (train*)ptr;

	printf("Trasa pociagu: %s\n", ptr2->trace);
}