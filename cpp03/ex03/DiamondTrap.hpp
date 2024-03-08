#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(DiamondTrap &copy);
	DiamondTrap &operator=(DiamondTrap &rhs);
	DiamondTrap(std::string name);
	void WhoAmI(void);
	using ScavTrap::attack;

private:
	std::string _name;
};

#endif
