/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 1
 */

#include "complex.h"

/*
 * Constructor for Complex class
 */
Complex::Complex(int r, int i) {
	setRnum(r);
	setInum(i);
}// End constructor

/*
 * Addition overload for Complex class
 */
Complex Complex::operator+(const Complex& rhs) const {
	Complex result;

	result.rnum = this->rnum + rhs.rnum;
	result.inum = this->inum + rhs.inum;

	return result;
} // End addition overload

/*
 * Subtraction overload for Complex class
 */
Complex Complex::operator-(const Complex& rhs) const {
	Complex result;
	
	result.rnum = this->rnum - rhs.rnum;
	result.inum = this->inum - rhs.inum;

	return result;
} // End subtraction overload

/*
 * Multiplication overload for Complex class
 */
Complex Complex::operator*(const Complex& rhs) const {
	Complex result;

	result.rnum = ((this->rnum * rhs.rnum) - (this->inum * rhs.inum));
	result.inum = ((this->inum * rhs.rnum) + (this->rnum * rhs.inum));

	return result;
} // End multiplication overload

/*
 * Equality overload for Complex class
 */
bool Complex::operator==(const Complex& rhs) {
	return (this->rnum == rhs.rnum && this->inum == rhs.inum);
} // End equality overload


/*
 * Output operator for Complex class
 */
ostream& operator<<( ostream &output, const Complex& number)
{ 
 output << number.rnum << " " << number.inum << "i";
 return output;            
} // End output overload

/*
 * Input operator for Complex class
 */
istream& operator>>( istream  &input, Complex& number)
{ 
 input >> number.rnum >> number.inum;
 return input;            
} // End input overload

/*
 * Copy constructor for Complex class
 */
Complex::Complex(const Complex& original) {
	rnum = original.rnum;
	inum = original.inum;
} // End copy constructor



/*
 * Presents menu to user after they have enter two complex variables
 */
int menu() {
	int choice = 0;

	cout << "\nPlease choose from 1-7\n"
	<< "1) Perform Addition (+)\n"
	<< "2) Perform Subtraction (-)\n"
	<< "3) Perform Multiplication (*)\n"
	<< "4) Print Complex Variables(<<)\n"
	<< "5) Check Equalilty (==)\n"
	<< "6) Check Inequliaty (!=)\n"
	<< "7) Exit"
	<< endl;

	cin >> choice;

	return choice;
} // End menu

/*
 * Takes the user's choice as input, along with the two complex variables.
 * Makes a call to the appropriate operation based on the choice given.
 */
void doChoice(int choice, Complex& nums1, Complex& nums2) {

	Complex result;

	if(choice == 1)
	{
		result = nums1 + nums2;
		cout << nums1 << " + " << nums2 << " = " << result << endl;
		return;
	}
	else if(choice == 2)
	{
		result = nums1 - nums2;
		cout << nums1 << " - " << nums2 << " = " << result << endl;
		return;
	}
	else if(choice == 3)
	{
		result = nums1 * nums2;
		cout << nums1 << " * " << nums2 << " = " << result << endl;
		return;
	}
	else if(choice == 4)
	{
		cout << "First: " << nums1 << endl;
		cout << "Second: " << nums2 << endl;
		return;
	}
	else if(choice == 5)
	{
		if (nums1 == nums2)
			cout << nums1 << " equals " << nums2 << endl;
		else
			cout << nums1 << " doesn't equal " << nums2 << endl;
		return;
	}
	else if(choice == 6)
	{
		if (nums1 != nums2)
			cout << nums1 << " doesn't equal " << nums2 << endl;
		else
			cout << nums1 << " equals " << nums2 << endl;
		return;
	}
	else
		return;

} // End doChoice