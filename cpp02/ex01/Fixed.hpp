#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();						 // default constructor
	~Fixed();						 // destructor
	Fixed(const Fixed &);			 // copy constructor
	Fixed &operator=(const Fixed &); // copy assignment operator overload
	int getRawBits(void) const;		 // getter
	void setRawBits(int const raw);	 // setter
	Fixed(const int n);				 // constructor int
	Fixed(const float f);			 // constructor float
	int toInt(void) const;			 // convert fixed point value to an int
	float toFloat(void) const;		 // convert fixed point value to a float

private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
// overload of the insertion operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter

#endif
