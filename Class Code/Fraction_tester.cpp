#include "Fraction.h"

int main(void)
{
	
	CFraction a(1, 2), b(3, 4), c;
	CFraction d(3);//3 is numerator, default denom
	CFraction e = a; //calls copy constructor
	CFraction f(b);
	CFraction g = 2; //conversion done for us -- compiler looks for a constructor
					// that accepts a single integer as a parameter and calls it implicitly!
	CFraction *pFrac = new CFraction(22, 7);
	c = a + b;

	cout << a << " + " << b << " = " << c << endl;

	cout << "\nMarch of the destructors: \nshould get 7 calls after this based on the 7 declarations in main..." 
		"\nDestructors are called in reverse order of constructors -- think about why\n" << endl;
	delete pFrac;
	return 0;
}