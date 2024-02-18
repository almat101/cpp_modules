#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "constructor called\n";
}

Zombie::Zombie(std::string new_name) :name(new_name)
{
	std::cout << "constructor with parameter called\n";
}

Zombie::~Zombie()
{
	std::cout << "Destructor called\n";
}

std::string Zombie::get_name(void)
{
	return this->name;
}

void Zombie::set_name(std::string new_name)
{
	this->name = new_name;
}
