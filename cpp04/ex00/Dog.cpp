#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called!" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(Dog &rhs)
{
	std::cout << "Dog copy assignment operator called!" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "*WOOOF WOOOF*" << std::endl;
}
