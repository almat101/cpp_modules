#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice & copy) : AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
	//this->_type = copy._type;
}

Ice & Ice::operator=(const Ice & rhs)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

//pure function implementation in Ice
Ice* Ice::clone(void) const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
