#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap rino("rino");
	ScavTrap gino("gino");
	ClapTrap mino("mino");

	rino = gino;
	return 0;
}
