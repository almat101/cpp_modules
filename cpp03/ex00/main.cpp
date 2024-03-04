#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap Mario("mario");
    ClapTrap Gigi("gigi");

    std::cout << Mario.getName() << std::endl;
    std::cout << Gigi.getName() << std::endl;

    Mario.attack("gigi");
    Gigi.takeDamage(8);
    Gigi.beRepaired(6);
    Gigi.takeDamage(10);


    return 0;
}