#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called!" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called!" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "*Miaaaooo Miaaooo*" << std::endl;
}
