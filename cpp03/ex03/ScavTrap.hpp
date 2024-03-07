#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>

class ScavTrap :virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap & copy);
		ScavTrap &operator=(ScavTrap &rhs);
		// function override
		void attack(const std::string &taget);
		void guardGate(void);

};

#endif
