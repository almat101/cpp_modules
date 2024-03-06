#include "ClapTrap.hpp"

void printStats(ClapTrap & gigi, ClapTrap & mario, ClapTrap & copy, ClapTrap & gennaro)
{
	std::cout << std::endl;
	std::cout << "gigi hits point : " << gigi.getHitPoints() << std::endl;
	std::cout << "gigi energy points : " << gigi.getEnergyPoints() << std::endl;
	std::cout << "mario energy points : " << mario.getEnergyPoints() << std::endl;
	std::cout << "mario hit points : " << mario.getHitPoints() << std::endl;
	std::cout << "copy of mario hits point : " << copy.getHitPoints() << std::endl;
	std::cout << "copy of mario energy points : " << copy.getEnergyPoints() << std::endl;
	std::cout << "gennaro hits point : " << gennaro.getHitPoints() << std::endl;
	std::cout << "gennaro energy points : " << gennaro.getEnergyPoints() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	ClapTrap mario("mario");
	ClapTrap gigi("gigi");
	ClapTrap copy(mario);
	ClapTrap gennaro;


	gennaro.setName("gennaro");
	gennaro.setEnergyPoints(10);
	gennaro.setHitPoints(10);

	// //test 1
	// gennaro.setAttackDamage(42);
	// gennaro.attack("copy");
	// copy.takeDamage(42);

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

	// //test 2 comment the others
	gigi.setAttackDamage(12);
	gigi.attack("mario");
	mario.takeDamage(12);

	// // test 3 with copy comment the others
	// copy.setAttackDamage(12);
	// std::cout << std::endl;
	// std::cout << "----------copy of mario attack mario----------";
	// copy.attack("mario");
	// mario.takeDamage(12);
	// copy.setAttackDamage(12);
	// std::cout << std::endl;
	// std::cout << "----------copy of mario attack gigi----------";
	// copy.attack("gigi");
	// gigi.takeDamage(12);

	// test 4 comment the others
	// mario.setAttackDamage(42);
	// mario.attack("gigi");
	// gigi.takeDamage(42);

	// //test 5
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);
	// mario.beRepaired(1);

	// //test 6
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
	// gigi.beRepaired(42);

	printStats(gigi, mario, copy, gennaro);

	return 0;
}
