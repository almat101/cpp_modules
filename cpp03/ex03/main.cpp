#include "DiamondTrap.hpp"

void seedRandomGenerator()
{
	std::srand((std::time(0)));
}

int main(void)
{
	seedRandomGenerator();

	DiamondTrap diamond("diamondddzzz");
	FragTrap diocleziano("diocleziano");

	std::cout << std::endl;
	diamond.WhoAmI();
	std::cout << std::endl;

	diamond.setAttackDamage(50);
	diamond.guardGate(); //scavtrap method
	diamond.highFivesGuys(); //fragtrap method
	if (diamond.isAlive())
		diamond.attack("diocleziano"); //scavtrap attack method
	if (diamond.isAlive())
		diocleziano.takeDamage(diamond.getAttackDamage());

	diocleziano.beRepaired(50);
	diamond.beRepaired(10);
	diocleziano.setAttackDamage(80);
	if (diocleziano.isAlive())
		diocleziano.attack("diocleziano");
	if (diocleziano.isAlive())
		diamond.takeDamage(diocleziano.getAttackDamage());


	diocleziano.displayStats();
	diamond.displayStats();

	return 0;
}
