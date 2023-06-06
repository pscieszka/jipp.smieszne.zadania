#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "my_student.h"
#include "my_group.h"


MY_GROUP* createGroup() {
	MY_GROUP* group = (MY_GROUP*)malloc(sizeof(MY_GROUP));
	size_t size2;
	char nazwa2[32];
	printf("Podaj nazwe grupy:");
	scanf_s("%s", nazwa2, sizeof(nazwa2));
	printf("Podaj wielkosc grupy:");
	scanf_s("%zu", &size2);
	strcpy_s(group->nazwa, strlen(nazwa2) + 1, nazwa2);
	group->size = size2;

	group->tab = (MY_STUDENT*)malloc(group->size * sizeof(MY_STUDENT));
	if (group->tab) {
		for (size_t i = 0; i < group->size; i++) {
			MY_STUDENT* stud = createStudent();
			group->tab[i] = *stud;
		}
	}
	else {
		free(group);
		return NULL;
	}
return group;
}


void printGroup(MY_GROUP* group) {
	if (group) {
		printf("\nNazwa grupy: %s ", group->nazwa);
		printf("\nRozmiar grupy: %zu ", group->size);
		printf("Studenci:\n");
		for (size_t i= 0; i < group->size; i++) {
			printf("Nazwisko: %s", group->tab[i].nazwisko);
			printf("\nRok rozpoczecia studiow: %d\n", group->tab[i].rok);

		}


	}
}

void freeGroup(MY_GROUP* group) {
	if (group) {
		for (size_t i = 0; i < group->size; i++) {
		free(group->tab[i].nazwisko);
		
		}
		free(group);
	}
	
}
