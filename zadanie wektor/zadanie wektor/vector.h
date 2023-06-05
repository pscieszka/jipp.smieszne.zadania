#pragma once
struct vector
{
	int dim;
	char str[64];
	double* buff;
};

vector* createVector();
void freeVector(vector* vec);
//void processVectors(vector* vecArray, size_t size);
void dotProduct(vector* vecArray, size_t size);

