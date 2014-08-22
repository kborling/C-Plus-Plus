/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 2
 * Compiled using g++ for Windows and Mac, and also the Microsoft cl compiler.
 * CBigInteger allows the user to multiply, add, subtract, check equality, <, >, <=, >= and assign values to eachother.
 * The user is required to enter two big integer values, one at a time.
 * The user is then presented with a menu of different options that print after each operation performed.
 * The solution is quite the conditional statement nightmare in some spots, but it was very difficult dealing with negatives and the large number of edge cases.
 * I did not attempt the extra credit for this assignment.
 */

#ifndef CBIGINTEGER_H
#define CBIGINTEGER_H

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

class CBigInteger {

friend ostream &operator<<(ostream &output, const CBigInteger& number);
friend istream &operator>>(istream &input, CBigInteger& number);

private:
	int sign;
	int size;
	int *digits;
public:
	CBigInteger(int sz = 0, int sg = 1);
	CBigInteger(const CBigInteger& original);
	~CBigInteger();

	bool operator==(const CBigInteger& rhs);
	bool operator!=(const CBigInteger& rhs) { return !(*this == rhs); }

	bool operator<(const CBigInteger& rhs);
	bool operator>(const CBigInteger& rhs) { return (!(*this < rhs) && (*this != rhs)); }
	bool operator<=(const CBigInteger& rhs) { return ((*this < rhs) || (*this == rhs)); }
	bool operator>=(const CBigInteger& rhs) { return ((*this > rhs) || (*this == rhs)); }

	CBigInteger& operator=(const CBigInteger& rhs);
	CBigInteger operator+(const CBigInteger& rhs) const;
	CBigInteger operator-(const CBigInteger& rhs) const;
	CBigInteger operator*(const CBigInteger& rhs) const;

}; // End class

	int menu();
	void doChoice(int choice, CBigInteger& num1, CBigInteger& num2);

#endif
