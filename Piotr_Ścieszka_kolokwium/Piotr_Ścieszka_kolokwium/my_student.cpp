#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "my_student.h"
#include "my_group.h"


MY_STUDENT* createStudent() {
	int rok2;
	char nazwisko2[64];
	printf("Podaj nazwisko studenta:");
	scanf_s("%s", nazwisko2, sizeof(nazwisko2));
	printf("Podaj rok rozpoczecia studiow:");
	scanf_s("%d", &rok2);
	MY_STUDENT* stud = (MY_STUDENT*)malloc(sizeof(MY_STUDENT));
	if (stud) {
		stud->nazwisko = (char*)malloc((strlen(nazwisko2) + 1) * sizeof(char));
		if (!stud->nazwisko) {
			free(stud->nazwisko);
			return NULL;
		}
		strcpy_s(stud->nazwisko, strlen(nazwisko2) + 1, nazwisko2);
		stud->rok = rok2;
	}
	return stud;
}




