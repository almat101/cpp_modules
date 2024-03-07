#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << this->_name << " has been constructed!!!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout << "copy constructor called" << std::endl;
	*this = copy;
}


ClapTrap &ClapTrap::operator=(ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(int hit)
{
	this->_hitPoints = hit;
}

void ClapTrap::setEnergyPoints(int energy)
{
	this->_energyPoints = energy;
}

void ClapTrap::setAttackDamage(int damage)
{
	if (damage >= 0)
		this->_attackDamage = damage;
	else
	{
		this->_attackDamage = 0;
		std::cerr << "error negative damage!" << std::endl;
	}
}

void ClapTrap::attack(const std::string &target)
{
	// if (this->getHitPoints() <= 0) // clap trap can attack with 0 hp
	// {
	// 	std::cout << this->getName() << " is dead, it can't attack is not a zombie :)" << std::endl;
	// 	return;
	// }
	// else
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << " has no energy point left :(" << std::endl;
		return;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		std::cout << this->getName() << " energy point left " << this->_energyPoints << std::endl;
		std::cout << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (static_cast<int>(amount) <= 0)
	{
		std::cout << this->getName() << " is enjoing 0 damage muahaha!" << std::endl;
		return;
	}
	else if (this->getHitPoints() == 0)
	{
		std::cout << this->getName() << " is already dead!" << std::endl;
		return;
	}
	else if (static_cast<int>(amount) > this->getHitPoints())
	{
		std::cout << this->getName() << " is dead too much damage!" << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		this->_hitPoints = _hitPoints - static_cast<int>(amount);
		std::cout << this->getName() << " hit points left " << this->_hitPoints << std::endl;
	}
	if (this->getHitPoints() == 0)
	{
		std::cout << this->getName() << " is dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (static_cast<int>(amount) <= 0)
	{
		std::cout << this->getName() << " can't repair with negative value :(" << std::endl;
		return;
	}
	if (this->getHitPoints() == 0)
	{
		std::cout << this->getName() << " is dead, it can't be repaired :(" << std::endl;
		return;
	}
	else if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << " has no energy left can't repair itself :(" << std::endl;
		return;
	}
	else
	{
		this->setHitPoints(static_cast<int>(amount) + _hitPoints);
		this->_energyPoints--;
		std::cout << this->getName() << " hit points repaired " << this->_hitPoints << std::endl;
		std::cout << this->getName() << " energy point left " << this->_energyPoints << std::endl;
	}
}
