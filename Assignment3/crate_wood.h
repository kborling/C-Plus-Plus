/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#ifndef CRATE_WOOD_H
#define CRATE_WOOD_H

#include "crate.h"

class Crate_Wood : public Crate {

private:
	string name;
public:
	Crate_Wood(int tracking, int weight, int type) : Crate(tracking, weight, type) {};

	virtual bool weightTest() { return this->getWeight() <= 80; };
	void print(ostream& out = cout) const { out << *this << endl; };
}; // End Crate_Wood class

ostream& operator<<(ostream& out, const Crate_Wood& crate_wood);

#endif
