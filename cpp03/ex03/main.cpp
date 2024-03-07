#include "DiamondTrap.hpp"

void seedRandomGenerator()
{
	std::srand((std::time(0)));
}

int main(void)
{
	DiamondTrap diamond;

	diamond.setName("diamond");

	std::cout << "DiamondTrap name " << diamond.getName() << std::endl;


	return 0;
}
