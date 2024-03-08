#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap // virtual is used to obtain only one instance of the base class claptrap
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
