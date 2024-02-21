#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type) : _type(type){}

Weapon::~Weapon(){}

const std::string&	Weapon::get_type(void) const
{
	return this->_type;
}

void	Weapon::set_type(std::string type)
{
		this->_type = type;
}
