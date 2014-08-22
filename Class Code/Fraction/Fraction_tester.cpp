#include "Fraction.h"

int main(void)
{
	
	CFraction a(1, 2), b(3, 4), c;
	CFraction d(3);//3 is numerator, default denom
	CFraction e = a; //calls copy constructor
	CFraction f(b);

	c = a + b;

	cout << a << " + " << b << " = " << c << endl;

	cout << "\nMarch of the destructors: \nshould get 6 calls after this based on the 6 declarations in main..." 
		"\nDestructors are called in reverse order of constructors -- think about why\n" << endl;

	return 0;
}