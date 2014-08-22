/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#ifndef LETTER_H
#define LETTER_H

#include "package.h"

class Letter : public Package {

private:
	string name;
public:
	Letter(int tracking, int weight, int type);

	virtual bool weightTest() { return this->getWeight() <= 32; };
	void print(ostream& out = cout) const { out << *this << endl; };
}; // End Letter class

ostream& operator<<(ostream& out, const Letter& letter);

#endif
