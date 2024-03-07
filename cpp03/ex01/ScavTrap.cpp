#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // this works if u want to use the constructor with name and not the default constructor
{
	// this->_name = name; the initialization list is already doing the job of initializing the name so i can so this line is useless
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

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy) // doesnt work if i remove this initialization list
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	//*this = copy; // this line is useless because the copy constructor of claptrap in the initialization list is already doing the job of copying the attributes
	// this line is required only if scavtrap has additional attributes !!!
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
		std::cout << "ScavTrap " << this->getName() << " can't attack because has 0 hit points" << std::endl;
		return;
	}
	else if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no energy point left :(" << std::endl;
		return;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->getName() << " now as " << this->_energyPoints << " energy points" << std::endl;
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
		this->_hitPoints *= 2;
		this->_attackDamage /= 2;
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
		this->_attackDamage *= 2;
		std::cout << "ScavTrap " << this->getName() << " now has " << this->getHitPoints() << " hits points, " << this->getEnergyPoints() << " energy points and " << this->getAttackDamage() << " attack damages" << std::endl;
		std::cout << std::endl;
	}
}
