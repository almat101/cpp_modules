#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap();
	~FragTrap();
	FragTrap (FragTrap & copy);
	FragTrap & operator= (FragTrap & rhs);
	FragTrap(std::string);

	void highFivesGuys(void);
};

#endif
