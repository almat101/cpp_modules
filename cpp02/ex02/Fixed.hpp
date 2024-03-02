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
	Fixed &operator=(const Fixed & rhs);
	int getRawBits(void) const;
	void setRawBits(int const);
	int toInt() const;
	float toFloat() const;
	Fixed operator+(const Fixed  & rhs) const;
	Fixed operator-(const Fixed & rhs) const;
	Fixed operator*(const Fixed & rhs) const;
	Fixed operator/(const Fixed & rhs) const;
	bool operator>(const Fixed & rhs) const;
	bool operator<(const Fixed & rhs) const;
	bool operator>=(const Fixed & rhs) const;
	bool operator<=(const Fixed & rhs) const;
	bool operator==(const Fixed & rhs) const;
	bool operator!=(const Fixed & rhs) const;

	static Fixed &min(Fixed &obj1, Fixed &obj2);

	static const Fixed &min(const Fixed &obj1, const Fixed &obj2);

	static Fixed &max(Fixed &obj1, Fixed &obj2);

	// I can declare the static member function in the hpp
	// here i can access directly the private _value
	// of the class because im in the class scope
	// if i define a static in the .cpp i have to use the getter to obtain
	// the private _value
	static const Fixed &max(Fixed const &obj1, Fixed const &obj2);
	// {
	// 	if (obj1._value > obj2._value)
	// 		return obj1;
	// 	else
	// 		return obj2;
	// }

private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
