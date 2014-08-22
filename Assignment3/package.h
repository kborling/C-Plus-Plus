/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 * Please see truck.h for more information.
 */
#ifndef PACKAGE_H
#define PACKAGE_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <new>
#include <memory>

using namespace std;

class Package {
private:
	string name;
	int tracking, weight, type;
	double price;
public:

	Package(string name = "Unknown") { this->name = name; };

	/* Get Methods */
	string getName() const { return this->name; };
	int getTracking() const { return this->tracking; }
	int getWeight() const { return this->weight; }
	int getType() const { return this->type; }
	/* Set Methods */
	void setName(string name = "Unknown") { this->name = name; };
	void setTracking(int tracking = 0) { this->tracking = tracking; };
	void setWeight(int weight = 0) { this->weight = weight; };
	void setType(int type = -1) { this->type = type; };
	/* Virtual Functions */
	virtual bool weightTest() { return false; };
	virtual void print(ostream& out = cout) const;
}; // End Package class

ostream& operator<<(ostream& out, const Package& package);

#endif