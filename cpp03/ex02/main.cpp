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

	gimbo.guardGate();
	gimbo.attack("zaz");
	zaz.takeDamage(gimbo.getAttackDamage());

	zaz.beRepaired(10);
	zaz.highFivesGuys();

	zaz.beRepaired(10);

	ziz.setAttackDamage(50);
	ziz.attack("gimbo");
	gimbo.takeDamage(ziz.getAttackDamage());

	gimbo.attack("ziz");
	ziz.takeDamage(gimbo.getAttackDamage());

	//ziz.highFivesGuys();

	std::cout << std::endl;
	std::cout << "FragTrap " << ziz.getName() << " has " << ziz.getHitPoints() << " hits point and " << ziz.getEnergyPoints() << " energy point" << std::endl;
	std::cout << "FragTrap " << zaz.getName() << " has " << zaz.getHitPoints() << " hits point and " << zaz.getEnergyPoints() << " energy point" << std::endl;
	std::cout << "ScavTrap " << gimbo.getName() << " has " << gimbo.getHitPoints() << " hits point and " << gimbo.getEnergyPoints() << " energy point" << std::endl;

	std::cout << std::endl;

	return 0;
}
