#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed(const int n);
	Fixed(const float f);
	int toInt(void) const;
	float toFloat(void) const;

private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);

#endif
