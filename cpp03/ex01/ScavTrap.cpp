#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);

	std::cout << "ScavTrap " << this->getName() << " constructed with " << this->getHitPoints() << " hits points, " << this->getEnergyPoints() << " energy points and " << this->getAttackDamage() << " attack damages" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
}

ScavTrap &ScavTrap::operator=(ScavTrap &rhs)
{
	if (this != &rhs)
	{
		std::cout << "operator = called\n";
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}
