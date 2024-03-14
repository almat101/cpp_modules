#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

int main(void)
{
	AMateria *ic = new Ice();
	Ice *i = new Ice();

	Cure *g = new Cure();
	Cure *g2 = new Cure();
	// // i = g; not allowed because AMateria copy assign is private

	*g = *g2; // this is performing the copy assignment operator


	Ice *cloned = i->clone();

	ICharacter *pippo = new Character("pippo_inzaghi");
	ICharacter *me = new Character("me");

	ic->use(*pippo); // this is ok ic is a new Ice
	i->use(*me);
	g->use(*pippo);
	g2->use(*me);

	std::cout << pippo->getName() << std::endl;

	delete ic;
	delete i;
	delete cloned;
	delete pippo;
	delete me;
	delete g;
	delete g2;
}
