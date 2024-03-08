#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &rhs)
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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	// this->_hitPoints = FragTrap::_hitPoints;
	// this->_attackDamage = FragTrap::_attackDamage;
	// this->_energyPoints = ScavTrap::_energyPoints; // cant work obtain the value from the last class constructor called so 100 not 50
	setHitPoints(100);
	setAttackDamage(30);
	setEnergyPoints(50);
	std::cout << "DiamondTrap " << name << " has been constructed" << std::endl;
}

void DiamondTrap::WhoAmI(void)
{
	std::cout << "DiamondTrap clap name is " << ClapTrap::_name << std::endl;
	std::cout << "DiamondTrap name is " << this->_name << std::endl;
	std::cout << "he has " << this->_hitPoints << " hit points and " << this->_attackDamage << " attack Damage like a FragTrap and " << this->_energyPoints << " energy points like a ScavTrap" << std::endl;
}
