/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 1
 * I used the Mac and Windows version of g++ and the Microsoft cl compiler for this assignment.
 * The assignment took approximately 3 hours.. mainly dealing with syntax errors.
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Complex {

friend ostream &operator<<(ostream &output, const Complex& number);
friend istream &operator>>(istream &input, Complex& number);

private:
	int inum, rnum;

public:
	Complex(int r = 0, int i = 0);

	int getRnum() const { return rnum; }
	int getInum() const { return inum; }

	void setRnum(int r) { rnum = r; }
	void setInum(int i) { inum = i; }

	bool operator==(const Complex& rhs);
	bool operator!=(const Complex& rhs) { return !(*this == rhs); }

	Complex operator+(const Complex& rhs) const;
	Complex operator-(const Complex& rhs) const;
	Complex operator*(const Complex& rhs) const;

	Complex(const Complex& original);
	~Complex() { }
};

int menu();
void doChoice(int choice, Complex& nums1, Complex& nums2);


#endif
