#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor called!" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat::WrongCat(WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat &rhs)
{
	std::cout << "WrongCat copy assignment operator called!" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "*WRONGMiaaaooo Miaaooo*" << std::endl;
}
