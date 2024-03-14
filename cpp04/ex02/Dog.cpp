#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog constructor called!" << std::endl;
	this->_type = "Dog";
	this->dogBrain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete dogBrain;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	this->dogBrain = new Brain(*copy.dogBrain);
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete this->dogBrain;
		this->dogBrain = new Brain(*rhs.dogBrain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "*WOOOF WOOOF*" << std::endl;
}

std::string Dog::getDogIdea(int i) const
{
	return this->dogBrain->getIdea(i);
}

void Dog::setDogIdea(int i, std::string dogIdea)
{
	 this->dogBrain->setIdea(i, dogIdea);
}
