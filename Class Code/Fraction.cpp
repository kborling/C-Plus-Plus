#include "Fraction.h"

CFraction::CFraction(int num, int den)
{
	cout << "->Default/explicit constructor called" 
		<< " num is: " << num << " denom is: " << den << endl;
	m_num = num;
	m_den = den;
}

CFraction CFraction::operator+(const CFraction& rhs) const
{
	CFraction result;

	result.m_num = m_num*rhs.m_den + rhs.m_num*m_den;
	result.m_den = m_den * rhs.m_den;

	return result;//return by value, copy constructor is called

}

ostream& operator<<(ostream& out, const CFraction& fraction)
{
	out << fraction.m_num << "/" << fraction.m_den;

	return out;

}

CFraction::CFraction(const CFraction& original) //must be pass by reference parameter to avoid recursive definition
{
	cout << "+++++>Copy constructor called!";
	cout << " original is: " << original << endl;

	m_num = original.m_num; //don't forget to copy the original values over
	m_den = original.m_den;
}

CFraction::~CFraction()
{
	cout << "!!!!DESTRUCTOR called, about to destroy: " << *this << endl;
}

CFraction& CFraction::operator=(const CFraction& original)
{
	cout << "Assignment operator overload executing -- whoo hoo!" << endl;
	if (this != &original)//make sure they are physically different objects
	{
		//copy contents -- deep copy as necessary
		this->m_num = original.m_num;
		this->m_den = original.m_den;
	}

	return *this; //for chaining


}

