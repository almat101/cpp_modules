#include "FragTrap.hpp"
#include "ScavTrap.hpp"
void seedRandomGenerator()
{
	std::srand((std::time(0)));
}

int main(void)
{

	FragTrap zaz("zaz");
	FragTrap ziz("ziz");
	ScavTrap gimbo("gimbo");

	seedRandomGenerator();

	gimbo.setAttackDamage(50);
	gimbo.guardGate();

	if (gimbo.isAlive())
		gimbo.attack("ziz");
	if (gimbo.isAlive())
		ziz.takeDamage(gimbo.getAttackDamage());

	if (zaz.isAlive())
		zaz.attack(gimbo.getName());
	if (zaz.isAlive())
		gimbo.takeDamage(zaz.getAttackDamage());

	ziz.beRepaired(10);
	ziz.highFivesGuys();

	zaz.beRepaired(10);

	ziz.setAttackDamage(50);
	if (ziz.isAlive())
		ziz.attack(gimbo.getName());
	if (ziz.isAlive())
		gimbo.takeDamage(ziz.getAttackDamage());

	if (gimbo.isAlive())
		gimbo.attack("ziz");
	if (gimbo.isAlive())
		ziz.takeDamage(gimbo.getAttackDamage());

	ziz.displayStats();
	zaz.displayStats();
	gimbo.displayStats();
	return 0;
}
