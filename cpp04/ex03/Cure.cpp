#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	std::cout << "Cure copy constructor called" << std::endl;
	// this->_type = copy._type;
}

Cure &Cure::operator=(const Cure &rhs)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

Cure *Cure::clone(void) const
{
	return new Cure();
}
