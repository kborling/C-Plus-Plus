#include "cbiginteger.h"
/*
 * Kevin Borling
 * CSCD 305 | C++ Programming
 * Assignment 2
 * See cbiginteger.h for more information
 */

/*
 * Constructor for CBigInteger class
 */
CBigInteger::CBigInteger(int size, int sign) {
	this->size = size;
	this->sign = sign;
    this->digits = NULL;
}// End constructor

/*
 * Destructor for CBigInteger class
 */
CBigInteger::~CBigInteger() {
	delete [] digits;
	digits = NULL;
}// End destructor

/*
 * Copy Constructor for CBigInteger class
 */
CBigInteger::CBigInteger(const CBigInteger& original) {

	this->sign = original.sign;
	this->size = original.size;

	for(int i = 0; i < this->size; i++) {
		this->digits[i] = original.digits[i];
	}
} // End copy constructor

/*
 * Output operator for CBigInteger class
 */
ostream& operator<<(ostream &output, const CBigInteger& number) { 
	if(number.sign == -1)
		output << "-";
 	for(int i = 0; i < number.size; i++)
 		output << number.digits[i];

 	return output;
} // End output overload

/*
 * Input operator for CBigInteger class
 */
istream& operator>>(istream &input, CBigInteger& number) {
	string temp;
	int num;

    input >> temp;
    // Check negative
    if(temp.at(0) == '-') {
    	number.sign = -1;
    	temp.erase(0,1);
    }

    number.size = temp.length();
    number.digits = (int*)calloc(number.size, sizeof(int));

    for(int i = 0; i < number.size; i++) {
    	if(temp.at(i) >= '0' && temp.at(i) <= '9') {
    		num = temp.at(i) - '0';
        	number.digits[i] = num;
        }
        else {
        	cout << "Not a valid number";
        	exit(-1);
        }
 	}
 	return input;            
} // End input overload

/*
 * Equality operator overload for CBigInteger class
 */
bool CBigInteger::operator==(const CBigInteger& rhs) {

	if(this->sign != rhs.sign)
		return false;
	if(this->size != rhs.size)
		return false;
	// They are the same sign and same size..
	for(int i = 0; i < this->size; i++) {
		if(this->digits[i] != rhs.digits[i])
			return false;
	}
	return true;
} // End equality operator overload

/*
 * Less than operator overload for CBigInteger class
 */
bool CBigInteger::operator<(const CBigInteger& rhs) {
	if(*this == rhs)
		return false;
	if(this->sign == 1 && rhs.sign == -1)
		return false;
	if(this->size > rhs.size)
		return false;
	if(this->size == rhs.size)
	{
		for(int i = 0; i < this->size; i++) {
			if(this->digits[i] > rhs.digits[i])
				return false;
		}
	}
	return true;
} // End less than operator overload

/*
 * Assignment operator overload for CBigInteger class
 */
CBigInteger& CBigInteger::operator=(const CBigInteger& original) {

	if (this != &original)
	{
		this->sign = original.sign;
		
		if (this->size != original.size)
		{
			this->size = original.size;
			delete [] this->digits;		
			this->digits = new int[this->size];
		}
		for (int i = 0; i < this->size; i++)
			this->digits[i] = original.digits[i];
	}
	return *this;
} // End assignment operator overload

/*
 * Addition operator overload for CBigInteger class
 */
CBigInteger CBigInteger::operator+(const CBigInteger& rhs) const {
	CBigInteger result;
	CBigInteger tempArray1;
	CBigInteger tempArray2;

	int t = this->size - 1;
	int r = rhs.size - 1;
	int c = 0;
	int carried = 0;
	int temp;
	int newSize;
	// Expands +1 if the first digit of each sum up >= 10 and are equal in size.
	if(this->size == rhs.size && this->digits[0] + rhs.digits[0] >= 10)
		newSize = max(this->size, rhs.size) + 1;
	else
		newSize = max(this->size, rhs.size);

	result.size = newSize;
	result.digits = (int*)calloc(newSize, sizeof(int));

	if((this->sign == 1 && rhs.sign == 1) || (this->sign == -1 && rhs.sign == -1))
	{
	for (; t >= 0 && r >= 0; t--, r--, c++) {
		result.digits[c] = (this->digits[t] + rhs.digits[r] + carried) % 10;
		carried = (this->digits[t] + rhs.digits[r] + carried) / 10;
	}
	if (this->size > rhs.size) {
		while (t >= 0) {
			result.digits[c++] = (this->digits[t] + carried) % 10;
			carried = (this->digits[t--] + carried) / 10;
		}
	} 
	else if (this->size < rhs.size) {
		while (r >= 0) {
			result.digits[c++] = (rhs.digits[r] + carried) % 10;
			carried = (rhs.digits[r--] + carried) / 10;
		}
	} 
	else {
		if (carried > 0)
			result.digits[c++] = carried;
	}
		for(int x = 0; x < result.size / 2; ++x) {
    		temp = result.digits[result.size-x-1];
    		result.digits[result.size-x-1] = result.digits[x];
    		result.digits[x] = temp;
		} // End reverse
	} // End if
	else
	{
		// If lhs is negative and rhs is positive: Just subtract rhs - lhs
		if(this->sign == -1 && rhs.sign == 1)
		{
			tempArray1 = *this;
			tempArray1.sign = 1;
			if(tempArray1 > rhs) {
				result = tempArray1 - rhs;
				result.sign = -1;
				return result;
			}
			else
			{
			result = rhs - tempArray1;
			return result;
			}
		} // End if
		// If lhs is positive and rhs is negative
		if(this->sign == 1 && rhs.sign == -1)
		{
			tempArray1 = rhs;
			tempArray2 = *this;
			tempArray1.sign = 1;
			if(tempArray2 < tempArray1)
			{
				result = tempArray1 - tempArray2;
				result.sign = -1;
			}
			else
			{
			result = tempArray2 - tempArray1;
			}
			return result;
		} // End if
	} // End else
	return result;
}// End addition operator overload

/*
 * Subtraction operator overload for CBigInteger class
 */
CBigInteger CBigInteger::operator-(const CBigInteger& rhs) const {

	CBigInteger result;
	CBigInteger tempArray1;
	CBigInteger tempArray2;
	int carried = 0;
	int temp;
	int newSize;

	newSize = max(this->size, rhs.size);
	result.size = newSize;
	result.digits = (int*)calloc(newSize, sizeof(int));
	if(this->sign == 1 && rhs.sign == -1 || this->sign == -1 && rhs.sign == -1)
	{
		tempArray2 = rhs;
		tempArray2.sign = 1;
		result = *this + tempArray2;
		return result;
	}
	else if(this->sign == -1 && rhs.sign == 1 || this->sign == 1 && rhs.sign == -1)
	{
		tempArray1 = *this;
		tempArray2 = rhs;
		tempArray1.sign = 1;
		if(tempArray1 < tempArray2)
			result = tempArray2 - tempArray1;
		else
		{
			tempArray2.sign = 1;
			result = tempArray1 - tempArray2;
			result.sign = -1;
		}
	}
    // Loop through all the digits
	for (int i = 0; i < newSize; i++) {
	  
	  temp = this->digits[i];

	  if (i < rhs.size)
	    temp -= rhs.digits[i];

	  temp -= carried;
	  
	  carried = 0;

	  if (temp < 0) {
	    temp = temp + 10;
	    carried = 1;
	  }
	  
	  result.digits[i] = temp;
	} // End for
	return result;
} // End subtraction operator overload

/*
 * Multiplication operator overload for CBigInteger class
 */
CBigInteger CBigInteger::operator*(const CBigInteger& rhs) const {
	CBigInteger result;
	int carried = 0;
	int offset = 0;
	int last;
	int total;
	int newSize;
	// Add both sizes and subtract one to get new size
	if((this->size < 2 || rhs.size < 2) || (this->digits[0] == 1 || rhs.digits[0] == 1))
	{
		newSize = (this->size + rhs.size) - 1;
	}
	else
		newSize = (this->size + rhs.size);
	result.size = newSize;
	result.digits = (int*)calloc(newSize, sizeof(int));

    for (int t = this->size - 1; t >= 0; t--) {
        	last = result.size - 1 - offset;
        for (int r = rhs.size - 1; r >= 0; r--) {
            total = result.digits[last] + (this->digits[t] * rhs.digits[r]) + carried;
            result.digits[last] = total % 10;
            carried = total / 10;
            last--;
        }
        if (carried > 0) {
            result.digits[last] += carried;
        	while (result.digits[last] >= 10) {
            	carried = result.digits[last] / 10;
            	result.digits[last] = result.digits[last] % 10;
            	result.digits[--last] += carried;
        	}
            carried = 0;
        }
        offset++;
    }
    // Change to positive sign if both are negative
	if(this->sign == -1 && rhs.sign == -1)
		result.sign = 1;
	if((this->sign == -1 && rhs.sign == 1) || (rhs.sign == -1 && this->sign == 1))
		result.sign = -1;

	return result;
} // End multiplication operator overload

/*
 * Presents menu to user after they have enter two big integer variables
 */
int menu() {
	int choice = 0;

	cout << "\nPlease choose from 1-12\n"
	<< "1) Perform Addition (+)\n"
	<< "2) Perform Subtraction (-)\n"
	<< "3) Perform Multiplication (*)\n"
	<< "4) Perform Assignment (=)\n"
	<< "5) Print Big Integer Values(<<)\n"
	<< "6) Check Equalilty (==)\n"
	<< "7) Check Inequliaty (!=)\n"
	<< "8) Check Less Than (<)\n"
	<< "9) Check Greater Than (>)\n"
	<< "10) Check Less Than or Equal To (<=)\n"
	<< "11) Check Greater Than or Equal To (>=)\n"
	<< "12) Exit"
	<< endl;

	cin >> choice;

	return choice;
} // End menu

/*
 * Takes the user's choice as input, along with the two big integer variables.
 * Makes a call to the appropriate operation based on the choice given.
 */
void doChoice(int choice, CBigInteger& num1, CBigInteger& num2) {

	CBigInteger result;

	if(choice == 1)
	{
		cout << num1 << " + " << num2 << " = ";
		result = num1 + num2;
		cout << result << endl;
		return;
	}
	else if(choice == 2)
	{
		cout << num1 << " - " << num2 << " = ";
		result = num1 - num2;
		cout << result << endl;
		return;
	}
	else if(choice == 3)
	{
		cout << num1 << " * " << num2 << " = ";
		result = num1 * num2;
		cout << result << endl;
		return;
	}
	else if(choice == 4)
	{
		cout << "Assigning: num1 = num2"<< endl;
		num1 = num2;
		return;
	}
	else if(choice == 5)
	{
		cout << "First: " << num1 << endl;
		cout << "Second: " << num2 << endl;
		return;
	}
	else if(choice == 6)
	{
		if (num1 == num2)
			cout << num1 << " equals " << num2 << endl;
		else
			cout << num1 << " doesn't equal " << num2 << endl;
		return;
	}
	else if(choice == 7)
	{
		if (num1 != num2)
			cout << num1 << " doesn't equal " << num2 << endl;
		else
			cout << num1 << " equals " << num2 << endl;
		return;
	}
	else if(choice == 8)
	{
		if (num1 < num2)
			cout << num1 << " is less than " << num2 << endl;
		else
			cout << num1 << " is not less than " << num2 << endl;
		return;
	}
	else if(choice == 9)
	{
		if (num1 > num2)
			cout << num1 << " is greater than " << num2 << endl;
		else
			cout << num1 << " is not greater than " << num2 << endl;
		return;
	}
	else if(choice == 10)
	{
		if (num1 <= num2)
			cout << num1 << " is less than or equal to " << num2 << endl;
		else
			cout << num1 << " is not less than or equal to " << num2 << endl;
		return;
	}
	else if(choice == 11)
	{
		if (num1 >= num2)
			cout << num1 << " is greater than or equal to " << num2 << endl;
		else
			cout << num1 << " is not greater than or equal to " << num2 << endl;
		return;
	}
	else
		return;

} // End doChoice
