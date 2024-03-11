#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << "Animal created!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructed!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	this->_type = copy._type;
}

Animal &Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal copy assignment operator = called!" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->_type;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "*Generic animal sound*" << std::endl;
}

void Animal::makeAnotherSound(void) const
{
	std::cout << "*Generic animal sound without virtual*" << std::endl;

}
