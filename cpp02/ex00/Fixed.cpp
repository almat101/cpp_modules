#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	//this->_value = copy.getRawBits();
	//this->_value = copy._value;		//copy can access the private member _value because in the instance of a class is possible
	//setRawBits(copy.getRawBits());	//using the setter and getter togheter is ok is there is additional logic in the setter
	// this->operator=(copy);			//using the operator= method on copy
	*this = copy;						//using directly the = overloaded
}

// Fixed::Fixed(const Fixed &copy) : _value(copy._value)
// {
// 	// copy constructor with implementation directly in the initialization list
// 	std::cout << "Copy constructor called" << std::endl;
// }


Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this == &copy)			//check of self assignment
	{
		std::cout << "Copy assignment operator overload called (self assignment test)" << std::endl;
		return *this;
	}
	std::cout << "Copy assignment operator overload called" << std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
