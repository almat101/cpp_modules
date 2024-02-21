#include "HumanA.hpp"

HumanA::~HumanA() {}

HumanA::HumanA(std::string name, Weapon& weap) : _name(name), _weaponREF(weap) // constructor need to have the reference of thre weapon
{}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weaponREF.get_type() << ::std::endl;
}
