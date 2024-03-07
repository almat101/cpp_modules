#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(ScavTrap & copy);
		ScavTrap &operator=(ScavTrap &rhs);
		ScavTrap(std::string name);
		// function override
		void attack(const std::string &taget);
		void guardGate(void);

};

#endif
