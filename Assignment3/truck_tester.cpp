/*
* Kevin Borling
* CSCD 305 | C++ Programming
* Assignment 3
* See truck.h for more information
*/
#include "truck.h"

int main(void) {

	Truck *theTruck = new Truck("manifest.txt");
	theTruck->load();
	theTruck->drive();
	theTruck->unload();

	return EXIT_SUCCESS;
} // End main