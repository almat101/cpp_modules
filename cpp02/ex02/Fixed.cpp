#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	int scalingFactor = 1 << this->_fractionalBits; // binaryPoint
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
		std::cout << "Copy assignment operator called from " << this->_value << std::endl;
		std::cout << "to " << rhs.getRawBits() << std::endl;
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
	int scalingFactor = 1 << this->_fractionalBits;
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
	std::cout << "Operator+ called from this->toFloat() " << this->toFloat() << " + rhs.toFloat() " << rhs.toFloat() << std::endl;
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	std::cout << "Operator- called from this->toFloat() " << this->toFloat() << " - rhs.toFloat() " << rhs.toFloat() << std::endl;
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	std::cout << "Operator* called from this->toFloat() " << this->toFloat() << " * rhs.toFloat() " << rhs.toFloat() << std::endl;
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	std::cout << "Operator/ called from this->toFloat() " << this->toFloat() << " / rhs.toFloat() " << rhs.toFloat() << std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator>(Fixed const &rhs) const
{
	std::cout << "Operator> called from this->_value " << this->_value << " > rhs value " << rhs.getRawBits() << std::endl;
	if (this->_value > rhs.getRawBits())
		return true;
	else
		return false;
}

// this operator < and > are const because they dont modify the state of the current object
// they return only a boolean
bool Fixed::operator<(Fixed const &rhs) const
{
	std::cout << "Operator< called from this->_value " << this->_value << " < rhs value " << rhs.getRawBits() << std::endl;
	// if (this->_value < rhs.getRawBits())
	// 	return true;
	// else
	// 	return false;
	return (this->_value < rhs._value);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	std::cout << "Operator>= called from this->_value " << this->_value << " < rhs value " << rhs.getRawBits() << std::endl;
	return (this->_value >= rhs._value);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	std::cout << "Operator<= called from this->_value " << this->_value << " < rhs value " << rhs.getRawBits() << std::endl;
	return (this->_value <= rhs._value);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	std::cout << "Operator== called from this->_value " << this->_value << " < rhs value " << rhs.getRawBits() << std::endl;
	return (this->_value == rhs._value);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	std::cout << "Operator!= called from this->_value " << this->_value << " < rhs value " << rhs.getRawBits() << std::endl;
	return (this->_value != rhs.getRawBits());
}

Fixed & Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj1;
	else
		return obj2;
}

const Fixed & Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return obj1;
	else
		return obj2;
}

Fixed & Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj1;
	else
		return obj2;
}

const Fixed & Fixed::max(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return obj1;
	else
		return obj2;
}
