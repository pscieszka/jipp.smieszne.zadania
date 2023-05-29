#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "my_vert.h"

MY_VERTEX* Init() {
	char nazwa[64];
	double x1, y1, z1;
	printf("Podaj nazwe my_vertex:\n");
	scanf_s("%s", nazwa, sizeof(nazwa)); // toutaj mozna jakie kominakty bledow se dodac
	printf("Podaj z,y,z:\n");
	scanf_s("%lf", &x1);
	scanf_s("%lf", &y1);
	scanf_s("%lf", &z1);
	MY_VERTEX* vert = (MY_VERTEX*)malloc(sizeof(MY_VERTEX)); //dynamiczne alokowanie obiektu
	
	if (vert) {
		vert->name = (char*)malloc((strlen(nazwa) + 1) * sizeof(char)); //dynamiczne alkowanie nazwy +1 bo chyba na koncu tablicy char jest \n czy cos takiego
		if (!vert->name) {
			free(vert);
			return NULL; // jezeli sie nie alokowalo 
		}
	}
	strcpy_s(vert->name, strlen(nazwa) + 1, nazwa);// kopiuje nazwe do zaalkowanej pamieci
	vert->len = strlen(nazwa); // dlugosc nazwy
	vert->x = x1;
	vert->y = y1;
	vert->z = z1; //przypisuje zmienne x,y,z

	return vert;
}

void vertFree(MY_VERTEX* vert) {
	if (vert)	free(vert);
}
void printVertexData(MY_VERTEX* vert) {
	if (vert) {
		printf("Name: %s\n", vert->name);
		printf("X: %f\n", vert->x);
		printf("Y: %f\n", vert->y);
		printf("Z: %f\n", vert->z);
	}
	else {
		printf("Vertex is NULL.\n");
	}
}
