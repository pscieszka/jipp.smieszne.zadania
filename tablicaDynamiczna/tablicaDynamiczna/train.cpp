
#include<stdlib.h>
#include "train.h"

void* trainInit() {
	train* pociag = (pociag*)malloc(sizeof(train));
	if (pociag) {
		char trasa[128];
		printf("Podaj trase pociagu:");
		scanf_s("%s", trasa, sizeof(trasa));
		pociag->trace = (char*)malloc(strlen(trasa) + 1, trasa);
		if (!pociag->trace) {
			free(pociag);
			return NULL;
		}
		strcpy_s(pociag->trace, strlen(trasa), trasa);
	}
	return (void*)(pociag);
}

void trainFree(void* ptr) {
	if (ptr) {
		(train*)ptr;
		free(ptr->trace);
		free(ptr);
	}
}
