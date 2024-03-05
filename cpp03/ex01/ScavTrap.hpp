#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(ScavTrap & copy);
	ScavTrap &operator=(ScavTrap &rhs);

private:
	ScavTrap(); // private constructor
};

#endif
