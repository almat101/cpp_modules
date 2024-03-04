#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
    ~ClapTrap();
    ClapTrap(std::string name);
    std::string getName(void) const;
    ClapTrap(ClapTrap &);
    ClapTrap & operator=(ClapTrap & rhs);
    void attack(const std::string & taget);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    private:
    ClapTrap(); // cant create a claptrap with default constructor is invalid
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
};

#endif