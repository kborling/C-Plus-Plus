/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#ifndef CRATE_METAL_H
#define CRATE_METAL_H

#include "crate.h"

class Crate_Metal : public Crate {

private:
	string name;
public:
	Crate_Metal(int tracking, int weight, int type) : Crate(tracking, weight, type) {} ;

	virtual bool weightTest() { return this->getWeight() <= 100; };
	void print(ostream& out = cout) const { out << *this << endl; };
}; // End Crate_Metal class

ostream& operator<<(ostream& out, const Crate_Metal& crate_metal);

#endif
