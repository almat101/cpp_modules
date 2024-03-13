#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
	AMateria *ic = new Ice();
	Ice *i = new Ice();

	Ice *cloned = i->clone();

	Character *pippo = new Character("pippo_inzaghi");

	std::cout << pippo->getName() << std::endl;

	delete ic; // ic is deleted because
	delete i;
	delete cloned;
	delete pippo;
}
