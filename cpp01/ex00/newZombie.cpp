#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	return new Zombie(name);
}

// Zombie*	newZombie(std::string name)
// {
// 	Zombie*	zombie = new Zombie();
// 	zombie->set_name(name);
// 	return zombie;
// }