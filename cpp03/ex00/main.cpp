#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap mario("mario");
	ClapTrap gigi("gigi");
	ClapTrap copy(mario);

	mario.setAttackDamage(-2);
	mario.attack("gigi");
	gigi.takeDamage(-2);
	mario.beRepaired(-2);

	mario.setAttackDamage(0);
	mario.attack("gigi");
	gigi.takeDamage(0);
	mario.beRepaired(1);

	mario.setAttackDamage(2);
	mario.attack("gigi");
	gigi.takeDamage(2);
	mario.beRepaired(1);

	// first test comment the second test energy point 0
	gigi.setAttackDamage(12);
	gigi.attack("mario");
	mario.takeDamage(12);

	// copy test like first test
	// copy.setAttackDamage(12);
	// std::cout << "----------copy of mario attack mario----------";
	// copy.attack("mario");
	// mario.takeDamage(12);

	// copy.setAttackDamage(12);
	// std::cout << "----------copy of mario attack gigi----------";
	// copy.attack("gigi");
	// gigi.takeDamage(12);

	// second test comment the first test
	// mario.setAttackDamage(42);
	// mario.attack("gigi");
	// gigi.takeDamage(42);

	// third test
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);

	// fourth test
	// gigi.beRepaired(1);
	// gigi.beRepaired(1);
	// gigi.beRepaired(13);
	// gigi.beRepaired(10);
	// gigi.beRepaired(4);
	// gigi.beRepaired(1);
	// gigi.beRepaired(1);
	// gigi.beRepaired(1);
	// gigi.beRepaired(1);
	// gigi.beRepaired(1);
	// gigi.beRepaired(1);
	// gigi.beRepaired(1);

	std::cout << std::endl;
	std::cout << "gigi hits point : " << gigi.getHitPoints() << std::endl;
	std::cout << "gigi energy points : " << gigi.getEnergyPoints() << std::endl;
	std::cout << "mario energy points : " << mario.getEnergyPoints() << std::endl;
	std::cout << "mario hit points : " << mario.getHitPoints() << std::endl;
	std::cout << std::endl;

	return 0;
}
