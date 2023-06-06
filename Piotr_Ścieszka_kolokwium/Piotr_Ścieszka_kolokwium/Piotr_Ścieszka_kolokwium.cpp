#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "my_student.h"
#include "my_group.h"
int main()
{
	//utworzyc 2 grupy studentow
	printf("WCZYTAJ PIERWSZA GRUPE:\n\n");
	MY_GROUP* grupaJeden = createGroup()
		;
	printf("WCZYTAJ DRUGA GRUPE:\n\n");
	MY_GROUP* grupaDwa = createGroup();

	//printuje 2 grupy

	printGroup(grupaJeden);
	printGroup(grupaDwa);

	//zwalniam pamiec
	freeGroup(grupaJeden);
	freeGroup(grupaDwa);


  
}
