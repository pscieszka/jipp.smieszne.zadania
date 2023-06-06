// my_trip_zad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
#include "MY_TRIP.h"
#include "MY_STORAGE.h"



int main()
{
    MY_STORAGE* tab = createArray(1);
	
    for (size_t i = 0; i < 3; i++) {
		add(tab);

    }
	print(tab);
	//if(tab)
	//freeArray(&tab);


}

