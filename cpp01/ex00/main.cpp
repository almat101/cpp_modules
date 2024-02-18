#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = new Zombie;

	Zombie zombie2("pippo");

	std::cout << "hi my name is " << zombie2.get_name() << std::endl;
	zombie1->set_name("franco");
	std::cout << "hi my nnname is " << zombie1->get_name() << std::endl;
	delete (zombie1);

	return 0;
}
