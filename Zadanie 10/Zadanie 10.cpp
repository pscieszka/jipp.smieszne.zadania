
#include <stdio.h>
#include "my_vert.h"
#include "my_piramid.h"

int main()
{
	// to  zadanie nie ma sensu nie rozumiemXD
	size_t dim = 2;
	MY_PIRAMID* arr = create(dim);
	add(arr, dim);
	printPyramid(arr, dim);
	freeMemory(arr, dim);
}


