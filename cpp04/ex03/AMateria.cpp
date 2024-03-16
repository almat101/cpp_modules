#include "AMateria.hpp"

AMateria::AMateria()
{
	//std::cout << "Amateria default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	//std::cout << "Amateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	//std::cout << "Amateria constructed with " << this->_type << " type" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	//std::cout << "Amateria copy constructor called" << std::endl;
	this->_type = copy._type;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	//std::cout << "Amateria copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target; // this make no sense AMateria object cannot be instantiated because is Abstract
}
