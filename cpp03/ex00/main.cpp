#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap mario("mario");
	ClapTrap gigi("gigi");
	ClapTrap gennaro("gennaro");

	gennaro.setAttackDamage(42);
	gennaro.setHitPoints(42);
	gennaro.setEnergyPoints(42);

	mario.setAttackDamage(10);

	if (mario.isAlive())
		mario.attack("gigi");
	else
		std::cout << "mario is dead can't attack" << std::endl;

	if (mario.isAlive())
		gigi.takeDamage(10);
	else
		std::cout << "gigi is dead can't take damage" << std::endl;

	if (gigi.isAlive())
		gigi.attack("mario");
	else
		std::cout << "gigi is dead can't attackkkkk" << std::endl;

	if (gigi.isAlive())
		mario.takeDamage(10);
	else
		std::cout << "mario is dead can't takeeee damageeeeeeee" << std::endl;

	gigi.beRepaired(10);

	if (gennaro.isAlive())
		gennaro.attack("mario");
	else
		std::cout << "gennaro is dead can't attack" << std::endl;

	if (mario.isAlive())
		mario.takeDamage(gennaro.getAttackDamage());
	else
		std::cout << "mario is dead can't take damage" << std::endl;

	gigi.displayStats();
	mario.displayStats();
	gennaro.displayStats();

	return 0;
}
