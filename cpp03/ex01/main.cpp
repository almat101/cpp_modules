#include "ScavTrap.hpp"

void seedRandomGenerator()
{
	std::srand((std::time(0)));
}

int main(void)
{
	ScavTrap gimbo("gimbo");
	ScavTrap ringo("ringo");
	ScavTrap mingo("mingo");

	seedRandomGenerator();

	ringo.guardGate();
	mingo.guardGate();
	gimbo.guardGate();


	ringo.takeDamage(gimbo.getAttackDamage());
	gimbo.attack(ringo.getName());

	mingo.takeDamage(ringo.getAttackDamage());
	ringo.attack(mingo.getName());

	gimbo.takeDamage(mingo.getAttackDamage());
	mingo.attack(gimbo.getName());

	ringo.takeDamage(gimbo.getAttackDamage());
	gimbo.attack(ringo.getName());

	mingo.takeDamage(ringo.getAttackDamage());
	ringo.attack(mingo.getName());

	gimbo.takeDamage(mingo.getAttackDamage());
	mingo.attack(gimbo.getName());

	std::cout << std::endl;
	std::cout << ringo.getName() << " has " << ringo.getHitPoints() << " hits point and " << ringo.getEnergyPoints() << " energy point" << std::endl;
	std::cout << gimbo.getName() << " has " << gimbo.getHitPoints() << " hits point and " << gimbo.getEnergyPoints() << " energy point" << std::endl;
	std::cout << mingo.getName() << " has " << mingo.getHitPoints() << " hits point and " << mingo.getEnergyPoints() << " energy point" << std::endl;
	std::cout << std::endl;

	return 0;
}
