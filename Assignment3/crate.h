/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#ifndef CRATE_H
#define CRATE_H

#include "package.h"

class Crate : public Package {

private:
	string name;
public:
	Crate(int tracking, int weight, int type);

	virtual bool weightTest() { return this->getWeight() <= 100; };
	void print(ostream& out = cout) const { out << *this << endl; };
}; // End Crate class

ostream& operator<<(ostream& out, const Crate& crate);

#endif