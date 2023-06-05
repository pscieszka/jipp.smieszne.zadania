
#include <iostream>
#include <stdlib.h>
#include "vector.h"
#define N 2
int main()
{
    vector* tab;
    tab = (vector*)malloc(N * sizeof(vector));
    for (size_t i = 0; i < N; i++) {
        tab[i] = *createVector();
    }


    dotProduct(tab, N);


    for (size_t i = 0; i < N; i++)
    {
        freeVector(&tab[i]); 
    }
    free(tab); 

    return 0;
}

