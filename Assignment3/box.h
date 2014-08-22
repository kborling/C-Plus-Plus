/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#ifndef BOX_H
#define BOX_H

#include "crate.h"

class Box : public Crate {

private:
	string name;
public:
	Box(int tracking, int weight, int type) : Crate(tracking, weight, type) {};

	virtual bool weightTest() { return this->getWeight() <= 40; };
	void print(ostream& out = cout) const { out << *this << endl; };
}; // End Box class

ostream& operator<<(ostream& out, const Box& box);

#endif