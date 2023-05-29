#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


#include "my_point.h"
#include "my_poligon.h"

int main()
{
    //stworz trojkat
    printf("Wpisz trojkat:\n");
    poligon* trojkat = create();
    //stworz  czworakat
    printf("Wpisz czworokat:\n");
    poligon* czworokat = create();
    //printuje 2 figury
    print(trojkat);
    printf("\n\n\n\n");
    print(czworokat);
    //zwalniam pamiec
    free(trojkat);
    free(czworokat);
}

