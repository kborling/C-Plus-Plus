#include "fraction.h"

Fraction::Fraction(int n, int d)
{
	setNum(n);
	setDen(d);
	cout << "Default/explicit constructor called" << endl;
}

Fraction::Fraction(const Fraction& orig)
{
	setNum(orig.getNum());
	setDen(orig.den);
	cout << "copy constructor called" << endl;
}

void Fraction::setNum(int n)
{
	num = n;
}

void Fraction::setDen(int d)
{
	den = (d == 0) ? 1: d;
	/* if (d == 0)
		den = 1;
	   else
	    den = d;
	*/
}

ostream& operator<<(ostream& out,const Fraction& f)
{
	out << f.getNum() << '/' << f.getDen();

	return out;
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction temp;

	temp.setNum(left.getNum()*right.getDen() + left.getDen()*right.getNum());
	temp.setDen(left.getDen()*right.getDen());

	return temp;

	/*or
	 return Fraction(left.getNum()*right.getDen() + left.getDen()*right.getNum(),
				left.getDen()*right.getDen());
	*/
}

bool Fraction::operator==(const Fraction& rhs)
{
	return (this->num == rhs.num && den == rhs.den);
}

const Fraction& Fraction::operator=(const Fraction& orig)
{
	if (this != &orig) //check for self assignment
	{
		num = orig.num;
		den = orig.den;
	}
	return *this;//for  chaining =
}
