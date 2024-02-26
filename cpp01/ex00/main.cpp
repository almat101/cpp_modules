#include "Zombie.hpp"

int main(void)
{
	Zombie *zaz = newZombie("zaz");		//heap zombie
	zaz->announce();

	randomChump("bar");					//stack zombie
	delete zaz;

	return 0;
}
