#include "Zombie.hpp"

int main(void)
{
	Zombie *zaz = newZombie("zaz");
	zaz->announce();

	randomChump("bar");
	delete zaz;

	return 0;
}
