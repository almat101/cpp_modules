#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // call the parent constructor with name
{
	//this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	// or with the setters
	// this->setName(name);
	// this->setHitPoints(100);
	// this->setEnergyPoints(50);
	// this->setAttackDamage(20);

	std::cout << "ScavTrap " << this->getName() << " constructed with " << this->getHitPoints() << " hits points, " << this->getEnergyPoints() << " energy points and " << this->getAttackDamage() << " attack damages" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy) // call the parent copy constructor
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	//*this = copy;
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

void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints = 0;
		std::cout << this->getName() << " energy point left " << this->_energyPoints << std::endl;
		std::cout << std::endl;
		return;
	}
	else if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << " has no energy point left :(" << std::endl;
		return;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		std::cout << this->getName() << " energy point left " << this->_energyPoints << std::endl;
		std::cout << std::endl;
	}
}

// Function to generate a random number
int getRandomNumber()
{
	return std::rand() % 3 + 1;
}

void ScavTrap::guardGate(void)
{
	int randomNum = getRandomNumber();
	if (randomNum == 1)
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode 1" << std::endl;
		this->_hitPoints /= 2;
		this->_attackDamage *= 2;
		std::cout << "ScavTrap " << this->getName() << " now has " << this->getHitPoints() << " hits points, " << this->getEnergyPoints() << " energy points and " << this->getAttackDamage() << " attack damages" << std::endl;
		std::cout << std::endl;
	}
	else if (randomNum == 2)
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode 2" << std::endl;
		this->_hitPoints /= 2;
		this->_energyPoints *= 2;
		std::cout << "ScavTrap " << this->getName() << " now has " << this->getHitPoints() << " hits points, " << this->getEnergyPoints() << " energy points and " << this->getAttackDamage() << " attack damages" << std::endl;
		std::cout << std::endl;
	}
	else if (randomNum == 3)
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode 3" << std::endl;
		this->_energyPoints /= 2;
		this->_attackDamage *= 5;
		std::cout << "ScavTrap " << this->getName() << " now has " << this->getHitPoints() << " hits points, " << this->getEnergyPoints() << " energy points and " << this->getAttackDamage() << " attack damages" << std::endl;
		std::cout << std::endl;
	}
}
