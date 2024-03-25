#include "Character.hpp"

Character::Character()
{
	// std::cout << "Character default constructor called" << std::endl;
	this->_name = "";
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}

	for (int i = 0; i < 100; i++)
	{
		this->_tmp[i] = NULL;
	}
}

Character::~Character()
{
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{	if (this->_inventory != NULL)
			delete this->_inventory[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->_tmp[i] != NULL)
			delete this->_tmp[i];
	}
}

Character::Character(const Character &copy)
{
	// std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character &Character::operator=(const Character &rhs)
{
	// std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i]; // with this line we perform a deep copy, if this line miss we perform a shallow copy
			this->_inventory[i] = rhs._inventory[i];
		}
		for (int i = 0; i < 100; i++)
		{
			if (this->_tmp[i])
				delete this->_tmp[i]; // with this line we perform a deep copy, if this line miss we perform a shallow copy
			this->_tmp[i] = rhs._tmp[i];
		}
	}
	return *this;
}

Character::Character(std::string name) : _name(name)
{
	//std::cout << "Character constructed with " << _name << " name and empty inventory!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		this->_tmp[i] = NULL;
	}
}

std::string const &Character::getCharacterAMateriaType(int idx) const
{
	return _inventory[idx]->getType();
}

// ICharacter methods
std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	//std::cout << " im in equip" << std::endl;
	if (m == NULL)
	{
		std::cerr << "No materia to equip " << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i ++)
	{
		if (this->_inventory[i] == NULL) // in modern c++ we can use nullptr, in c98 only NULL
		{
			this->_inventory[i] = m;
			std::cout << "Materia " << m->getType() << " equipped in slot " << i << std::endl;
			return;
		}
	}
	std::cerr << "full inventory, cannot equip!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx <= -1)
	{
		std::cerr << "Wrong index of Materia" << std::endl;
		return ;
	}
	static int j = 0;
	if (this->_inventory[idx])
	{
		std::cout << "Character " << this->getName() << " unequip " << this->getCharacterAMateriaType(idx) << " on slot " << idx << std::endl;
		// from subject we cant delete AMateria object in the unequip function, but now where is deleted the AMAteria?
		this->_tmp[j] = this->_inventory[idx];
		j++;
		this->_inventory[idx] = NULL;
	}
	else
		std::cerr << "cannot unequip" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 4 || idx <= -1)
	{
		std::cerr << "Wrong index of Materia" << std::endl;
		return ;
	}
	else if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
	{
		std::cerr << "cannot use" << std::endl;
		return ;
	}
}
