/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#include "letter.h"

Letter::Letter(int tracking, int weight, int type) : Package("Letter") {
	this->setTracking(tracking);
	this->setWeight(weight);
	this->setType(type);
} // End Letter Constructor

ostream& operator<<(ostream& out, const Letter& letter) {
	out << "Letter"
		<< "\nTracking Number: " << letter.getTracking()
		<< "\nWeight: " << letter.getWeight() << endl;
	return out;
} // End Output Operator Overload