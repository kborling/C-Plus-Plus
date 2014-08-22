/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 * Compiled using g++ for Windows and Mac, and also the Microsoft cl compiler.
 * I have created a makefile for your convienience. Please see README if you want to use it.
 * The major issue that I had was printing the values from the unique pointers. I ended up printing from the vector, so unfortunately
 * the output overload isn't used.
 * After battling several syntax errors, I have ended up with a working but not ideal solution.
 * 
 */

#ifndef TRUCK_H
#define TRUCK_H

#include "package_exception.h"
#include "package.h"
#include "letter.h"
#include "crate.h"
#include "crate_metal.h"
#include "crate_wood.h"
#include "box.h"

#include <fstream>
#include <iostream>
#include <iomanip>

class Truck {

private:
	string driver;
	string startCity;
	string endCity;

	int truckWeight;
	int maxPackages;
	int PackageNum;
	int crateWeight, letterWeight;
	double cost;

	vector<unique_ptr<Package>> packages;
	unique_ptr<Package> pPackage;

public:
	ifstream Instream;
	ofstream Outstream;

	Truck(string input);

	void load();
	void drive();
	void unload();
	int findType(int tnum);

}; // End Truck class

#endif