/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#include "box.h"

ostream& operator<<(ostream& out, const Box& box) {

	out << "Box" 
		<< "\nTracking Number: " << box.getTracking()
		<< "\nWeight: " << box.getWeight() << endl;
	return out;
} // End Output Operator Overload