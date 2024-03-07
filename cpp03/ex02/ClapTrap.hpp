#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <limits>

class ClapTrap
{
	public:
		ClapTrap();
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
		virtual void attack(const std::string &target);  // function override in father class u use virtual then in the child cpp u can modify this method
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		//protected attribute can be accessed by child class
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
		// private attribute cant be accessed by outside, only with getters method
};

#endif
