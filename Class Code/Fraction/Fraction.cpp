#include "Fraction.h"

CFraction::CFraction(int num, int den)
{
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

CFraction::CFraction(const CFraction& original)
{
	cout << "Copy constructor called!" << endl;
	cout << "original is: " << original << endl;

	m_num = original.m_num;
	m_den = original.m_den;
}

CFraction::~CFraction()
{
	cout << "Destructor called, about to destroy: " << *this << endl;
}

