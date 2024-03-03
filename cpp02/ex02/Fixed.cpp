#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// constructor that takes a const int n as paramenter
// the left shift operation achieves the positioning of the binary point
// in the fixed-point representation.
// The binary point determines where the fractional part begins in a binary number.
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << this->_fractionalBits;
}

// Constructor that takes a const float f as parameter
// The scaling factor is a numerical value used for scaling when converting between
// floating-point and fixed-point representations.
// the value of scaling factor is 256 or 2^8 or 100000000 or 1 << 8
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	int scalingFactor = 1 << this->_fractionalBits;
	float scaledResult = f * scalingFactor;
	this->_value = roundf(scaledResult);
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = copy.getRawBits();
}

// in operator = the function is not const
// because the = operator is used for assignment the value of an object to another
// this assignment change the state of the current object(this) so it cant be const
// like the others operator + - * /
Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_value = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	int n = this->_value >> this->_fractionalBits;
	return n;
}

float Fixed::toFloat(void) const
{
	int scalingFactor = 1 << this->_fractionalBits; // 256 or 100000000
	float f = static_cast<float>(this->_value) / scalingFactor;
	return f;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

// operator + overload
// LHS + RHS
// left hand side + right hand side
// 1 + 2 = 3  for example
// LHS is the instance of the current object (this)
// RHS is the new parameter passed in the function
// 3 is a new object created from 1 + 2
// is const because it does not modify the state of the current object (this or LHF)
// the return value is a Fixed that contain the toFloat() representation of the
// this (LHF) + the RHS
Fixed Fixed::operator+(Fixed const &rhs) const
{
	std::cout << "Operator+ called" << std::endl;
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	std::cout << "Operator- called" << std::endl;
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	std::cout << "Operator* called" << std::endl;
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	std::cout << "Operator/ called" << std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator>(Fixed const &rhs) const
{
	std::cout << "Operator> called" << std::endl;
	if (this->_value > rhs.getRawBits())
		return true;
	else
		return false;
}

// all the operator > < >= <= const because they dont modify the state of the current object
// they return only a boolean
bool Fixed::operator<(Fixed const &rhs) const
{
	std::cout << "Operator< called" << std::endl;
	// if (this->_value < rhs.getRawBits())
	// 	return true;
	// else
	// 	return false;
	return (this->_value < rhs._value);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	std::cout << "Operator>= called" << std::endl;
	return (this->_value >= rhs._value);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	std::cout << "Operator<= called" << std::endl;
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	std::cout << "Operator== called" << std::endl;
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	std::cout << "Operator!= called" << std::endl;
	return (this->_value != rhs.getRawBits());
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj1;
	else
		return obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj1;
	else
		return obj2;
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj1;
	else
		return obj2;
}

const Fixed &Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj1;
	else
		return obj2;
}

//Pre-increment and pre-decrement operators (++obj, --obj):
//These operators are called with no parameters,
//and the overload is typically implemented with a return type of Fixed & (reference to the object).

Fixed &Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

//Post-increment and post-decrement operators (obj++, obj--):
//These operators are called with a dummy int parameter (though the name of the parameter doesn't matter).
//The overload is typically implemented with a return type of T (value, not a reference).
//The purpose of the dummy parameter is to distinguish between the pre-increment and post-increment forms

Fixed Fixed::operator++(int)
{
	// cppreference.com implementation
	Fixed old = *this;
	operator++();
	return old;
}

Fixed Fixed::operator--(int)
{
	// cppreference.com implementation
	Fixed old = *this;
	operator--();
	return old;
}



