#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <limits>
class ClapTrap
{
public:
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &);
	ClapTrap &operator=(ClapTrap &rhs);
	// getter methods
	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;
	// setter methods
	void setName(std::string);
	void setHitPoints(int);
	void setEnergyPoints(int);
	void setAttackDamage(int);
	// public member function
	void attack(const std::string &taget);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	ClapTrap(); // now is protected child class can access this constructor
private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};

#endif
