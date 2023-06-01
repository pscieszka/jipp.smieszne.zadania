
#include <iostream>
#include <stdlib.h>


int main()
{
	int n;
	int i;
	printf("Podaj wielkosc tablicy:");
	scanf_s("%d", &n);
	while (1) {
		printf("\n 0 - DODAJ OBIEKT\n1-WYDRUKUJ TABLICE\n2-KONIEC\n");
		if (scanf_s("%d", &i) == 1) {
			switch (i) {
			case 0:
				int j;
				
			case 1:

			case 2:
				return 0;
			default:
				printf("Zly wybor\n");
			};
		}
	}
}

