#include <iostream>
#include <stdlib.h>
#include "car.h"



void* carInit() {
    car* samochod = (car*)malloc(sizeof(car));
    if (samochod) {
        char marka[128];
        int rok;
        printf("Podaj model samochodu: ");
        scanf_s("%s", marka, sizeof(marka));
        printf("Podaj rok samochodu: ");
        scanf_s("%d", &rok);
        samochod->model = (char*)malloc(strlen(marka) + 1);
        if (!samochod->model) {
            
            return NULL;
        }
        strcpy_s(samochod->model, strlen(marka) + 1, marka);
        samochod->year = rok;
    }
    return (void*)(samochod);
}

void carFree(void** ptr) {
    if (ptr && *ptr) {
        car* samochod = (car*)(*ptr);
        if (samochod->model) {
            free(samochod->model);
        }
        free(samochod);
        *ptr = NULL;
    }
}

void carPrint(void* ptr)
{
   car* ptr2 = (car*)ptr;

    printf("Marka samochodu: %s\n", ptr2->model);
    printf("Rok samochodu: %d\n", ptr2->year);
}