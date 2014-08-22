#include "cbiginteger.h"
/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 2
 * See cbiginteger.h for more information
 */
int main(void) {

	int choice = 0;
	CBigInteger num1, num2;

		cout << "Please enter two big integer values (one big integer values at a time)\n" << endl;
		cout << "Please enter first CBigInteger variable:" << endl;
		cin >> num1;
		cout << "Please enter second CBigInteger variable:" << endl;
		cin >> num2;

	do {
		choice = menu();
		doChoice(choice, num1, num2);
	}while(choice != 12);

	return EXIT_SUCCESS;
} // End main