#include "Zombie.hpp"

Zombie::Zombie()
{
	//std::cout << "constructor called\n";
}

Zombie::Zombie(std::string new_name) :_name(new_name)
{
	//std::cout << "constructor with parameter called\n";
}

Zombie::~Zombie()
{
	std::cout << "Destructor called and " << this->_name << " died :'(" << std::endl;
}

std::string Zombie::get_name(void) const
{
	return this->_name;
}

void	Zombie::set_name(std::string new_name)
{
	this->_name = new_name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}