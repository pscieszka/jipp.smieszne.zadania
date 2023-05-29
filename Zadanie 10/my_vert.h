#pragma once

struct MY_VERTEX{
	char* name;
	size_t len;
	double x, y, z;
};

MY_VERTEX* Init(); // tworzenie obiektu
void vertFree(MY_VERTEX* vert); //zwolnienie pamieci
void printVertexData(MY_VERTEX* vert);


