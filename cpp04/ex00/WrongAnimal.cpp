#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal created!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructed!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &rhs)
{
	std::cout << "WrongAnimal copy assignment operator = called!" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "*Generic WrongAnimal sound*" << std::endl;
}

