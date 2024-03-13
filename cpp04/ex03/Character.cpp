#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "";
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;

}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = copy._inventory[i];
	}
}

Character &Character::operator=(const Character &rhs)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			this->_inventory[i] = rhs._inventory[i];
		}
	}
	return *this;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character constructed with " << _name << " name and empty inventory!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

//ICharacter methods
std::string const & Character::getName() const
{
	return _name;
}

