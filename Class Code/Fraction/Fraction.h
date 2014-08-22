#pragma once
#include <iostream>
using namespace std;

class CFraction
{
	friend ostream& operator<<(ostream& out, const CFraction& fraction);
public:
	CFraction(int num=0, int den=1);
	CFraction(const CFraction& original);//copy constructor

	~CFraction(); //destructor!!!!

	CFraction operator+(const CFraction& rhs) const;
private:
	int m_num, m_den;
};


