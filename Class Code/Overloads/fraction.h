#include <iostream>

using namespace std;

class Fraction
{
	//friend ostream& operator<<(ostream& out, const  Fraction& f);
private:
	int num, den;
public:
	Fraction(int n=0, int d=1);
	~Fraction() {cout << "Destroying..." << num << '/' << den << endl;}
	Fraction(const Fraction& orig);

	int getNum() const {return num;}
	int getDen() const {return den;}

	void setNum(int n);
	void setDen(int d);

	bool operator==(const Fraction& rhs);
	bool operator!=(const Fraction& rhs) {return !(*this == rhs);}

	const Fraction& operator=(const Fraction& orig);

	

};

ostream& operator<<(ostream& out, const  Fraction& f);

Fraction operator+(const Fraction& left, const Fraction& right);