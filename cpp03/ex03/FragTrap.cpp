#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	//*this = copy;
}

FragTrap &FragTrap::operator=(FragTrap &rhs)
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

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	// this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->getName() << " constructed with " << this->getHitPoints() << " hits points, " << this->getEnergyPoints() << " energy points and " << this->getAttackDamage() << " attack damages" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << std::endl;
		std::cout << "FragTrap " << this->getName() << " has no hit points left :(" << std::endl;
		std::cout << std::endl;
		std::cout << "FragTrap request a positive Hight Five" << std::endl;
		this->setHitPoints(100);
		this->setEnergyPoints(0);
		std::cout << "FragTrap " << this->getName() << " has now " << this->getHitPoints() << " hit points restored!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "FragTrap " << this->getName() << " request a negative Hight Five" << std::endl;
		std::cout << std::endl;
	}
}
