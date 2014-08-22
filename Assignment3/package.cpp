/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#include "package.h"

void Package::print(ostream& out) const {
	out << *this << endl;
}

ostream& operator<<(ostream& out, const Package& package) {
	out << "\nTracking Number: " << package.getTracking()
		<< "\nWeight: " << package.getWeight();
	return out;
} // End Output Operator Overload