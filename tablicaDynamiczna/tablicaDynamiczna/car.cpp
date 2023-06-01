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
            free(samochod);
            return NULL;
        }
        strcpy_s(samochod->model, strlen(marka) + 1, marka);
        samochod->year = rok;
    }
    return (void*)(samochod);
}

void carFree(void* ptr) {
    if(ptr){
        (car*)ptr;
        free(ptr->model);
        free(ptr);
    }
}