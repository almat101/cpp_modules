#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	set_weapon(Weapon&); // reference to the weapon that is a pointer
	private:
	std::string	_name;
	Weapon*		_weapon;
};

#endif
