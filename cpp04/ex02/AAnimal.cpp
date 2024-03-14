#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "AAnimal";
	std::cout << "AAnimal created!" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructed!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called!" << std::endl;
	this->_type = copy._type;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	std::cout << "AAnimal copy assignment operator = called!" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string AAnimal::getType(void) const
{
	return this->_type;
}

void AAnimal::setType(std::string type)
{
	this->_type = type;
}


/* the makeSound now is a pure virtual function */

// void AAnimal::makeSound(void) const
// {
// 	std::cout << "*Generic animal sound*" << std::endl;
// }

void AAnimal::makeAnotherSound(void) const
{
	std::cout << "*Generic animal sound without virtual*" << std::endl;

}
