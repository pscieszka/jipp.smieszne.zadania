#include <iostream>
#include <stdlib.h>
#include "MY_TRIP.h"


void* tripInit() {
    MY_TRIP* trip = (MY_TRIP*)malloc(sizeof(trip));
    if (trip) {
        char str2[128];
        printf("Podaj wiersz tekstowy: ");
        scanf_s("%s", str2, sizeof(str2));
        printf("Podaj rok podrozy: ");
        scanf_s("%d", &(trip->rok));
        printf("Podaj koszt podrozy: ");
        scanf_s("%lf", &(trip->koszt));
        trip->str = (char*)malloc((strlen(str2) + 1) * sizeof(char));
        if (!trip ->str) {

            return NULL;
        }
        strcpy_s(trip->str, strlen(str2) + 1, str2);

    }
    return (void*)(trip);
}

void tripFree(void** ptr) {
    if (ptr && *ptr) {
        MY_TRIP* trip = (MY_TRIP*)(*ptr);
        if (trip->str) {
            free(trip->str);
        }
        free(trip);
        *ptr = NULL;
    }
}

void tripPrint(void* ptr)
{
    MY_TRIP* ptr2 = (MY_TRIP*)ptr;

    printf("Tekst: %s\n", ptr2->str);
    printf("Koszt: %lf\n", ptr2->koszt);
    printf("Rok: %d\n", ptr2->rok);

}