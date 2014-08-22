/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#include "crate_metal.h"

ostream& operator<<(ostream& out, const Crate_Metal& crate_metal) {
	out << "Metal Crate" 
		<< "\nTracking Number: " << crate_metal.getTracking()
		<< "\nWeight: " << crate_metal.getWeight() << endl;
	return out;
} // End Output Operator Overload