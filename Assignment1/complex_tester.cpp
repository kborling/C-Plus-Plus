/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 1
 */
#include "complex.h"

int main () {

	int choice = 0;
	Complex nums1, nums2;
	char letter;

		cout << "Please enter two values for each Complex Variable: a real number followed by an imaginary number (Ex. 3 3i)" << endl;
		cout << "Please enter first Complex Variable:" << endl;
		cin >> nums1 >> letter;
		cout << "Please enter second Complex Variable:" << endl;
		cin >> nums2 >> letter;
	do
	{
		choice = menu();
		doChoice(choice, nums1, nums2);

	}while(choice != 7);

return EXIT_SUCCESS;
} // End main