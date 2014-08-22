/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#include "crate.h"

Crate::Crate(int tracking, int weight, int type) : Package("Crate") {
	this->setTracking(tracking);
	this->setWeight(weight);
	this->setType(type);
} // End Crate Constructor

ostream& operator<<(ostream& out, const Crate& crate) {
	out << "\nTracking Number: " << crate.getTracking()
		<< "\nWeight: " << crate.getWeight() << endl;
	return out;
} // End Output Operator Overload