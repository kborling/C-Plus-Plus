/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 3
 */
#ifndef PACKAGE_EXCEPTION_H
#define PACKAGE_EXCEPTION_H

#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

class PackageException : public exception {

private:
	const char* error;

public:
	PackageException(const char* error = "Unknown Error") { this->error = error; }
	const char* what() const throw() { return this->error; }
}; // End PackageException class

#endif
