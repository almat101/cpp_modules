#include "Fixed.hpp"
#include <cmath>

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
	int scalingFactor = 1 << this->_fractionalBits; // 100000000
	float scaledResult = f * scalingFactor;
	this->_value = roundf(scaledResult);
}

Fixed::Fixed(const Fixed & copy) : _value(copy._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed & rhs)
{
	if (this != &rhs) // check for self assignment
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
	int scalingFactor = 1 << this->_fractionalBits; // 1 << 8 or 100000000 or 2^8 or 256
	float f = static_cast<float>(this->_value) / scalingFactor;
	return f;
}


std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
