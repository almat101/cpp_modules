#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "empty claptrap constructor" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "claptrap destructor called" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return this->_name;
}

ClapTrap::ClapTrap(ClapTrap & copy)
{
    *this = copy;
}

ClapTrap & ClapTrap::operator=(ClapTrap & rhs)
{
    if (this != &rhs)
        this->_name = rhs.getName();
    return *this;
}

ClapTrap::ClapTrap(std::string name ) : _name(name) , _hitPoints(10) , _energyPoints(10), _attackDamage(0)
{
    std::cout << "claptrap constructor called with name " << this->_name << ", hits " << this->_hitPoints << ", energy " << this->_energyPoints << " and attackDamage " << this->_attackDamage <<  std::endl;
}

void ClapTrap::attack(const std::string & target)
{
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
   //ClapTrap <name> attacks <target>, causing <damage> points of damage!
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints >= 10)
    {

    }   
        this->_hitPoints = _hitPoints - amount;
        this->_energyPoints--;
        std::cout<< this->getName() << " hit points left " << this->_hitPoints << std::endl;
        std::cout<< this->getName() << " energy point left " << this->_energyPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitPoints = amount + _hitPoints;
    this->_energyPoints--;
    std::cout<< this->getName() << " hit points repaired " << this->_hitPoints << std::endl;
    std::cout<< this->getName() << " energy point left " << this->_energyPoints << std::endl;
}

