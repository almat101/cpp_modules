#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{

	std::cout << std::endl;
	Weapon clubb = Weapon("crude spiked club");
	HumanA bob("Bob", clubb);
	bob.attack();
	clubb.set_type("some other type of club");
	bob.attack();

	std::cout << std::endl;
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.set_weapon(club);
	jim.attack();
	club.set_type("some other type of club");
	jim.attack();
	std::cout << std::endl;


	return 0;
}
