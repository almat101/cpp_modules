#ifndef FIXED_HPP
#define FiXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &copy);
	Fixed & operator=(Fixed const & rhs);
	int getRawBits(void) const;
	void setRawBits(int const);
	int toInt() const;
	float toFloat() const;
	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;
	bool operator>(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;

private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
