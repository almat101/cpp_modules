#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name) :_name(name) {}

Zombie::~Zombie()
{
	std::cout << "Destructor called and " << this->_name << " died :'(" << std::endl;
}

std::string Zombie::get_name(void) const
{
	return this->_name;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}



