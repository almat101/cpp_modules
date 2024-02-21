#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
public:
	HumanA(std::string _name,Weapon& _weaponREF); // constructor weaponREF passed by reference
	~HumanA();
	void attack(void);

private:
	std::string			_name;
	Weapon&				_weaponREF; // reference
};

#endif
