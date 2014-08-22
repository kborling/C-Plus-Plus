/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#include "crate_wood.h"

ostream& operator<<(ostream& out, const Crate_Wood& crate_wood) {
	out << "Wood Crate"
		<< "\nTracking Number: " << crate_wood.getTracking()
		<< "\nWeight: " << crate_wood.getWeight() << endl;
	return out;
}