#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap mario("mario");
	ClapTrap gigi("gigi");
	ClapTrap gennaro("gennaro");

	gennaro.setAttackDamage(42);
	gennaro.setHitPoints(42);
	gennaro.setEnergyPoints(42);

	// test 4 comment the others
	mario.setAttackDamage(10);
	gigi.takeDamage(10); // only way is to take damage before attacking
	mario.attack("gigi");
	mario.takeDamage(10);
	gigi.attack("mario");

	mario.takeDamage(gennaro.getAttackDamage());
	gennaro.attack("mario");

	std::cout << "gigi hits point : " << gigi.getHitPoints() << std::endl;
	std::cout << "gigi energy points : " << gigi.getEnergyPoints() << std::endl;
	std::cout << "mario hit points : " << mario.getHitPoints() << std::endl;
	std::cout << "mario energy points : " << mario.getEnergyPoints() << std::endl;
	std::cout << "gennaro hits point : " << gennaro.getHitPoints() << std::endl;
	std::cout << "gennaro energy points : " << gennaro.getEnergyPoints() << std::endl;

	return 0;
}
