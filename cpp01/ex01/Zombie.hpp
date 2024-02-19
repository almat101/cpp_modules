#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
	Zombie();
	Zombie(std::string);
	~Zombie();
	std::string get_name(void) const;
	void		set_name(std::string);
	void		announce(void);

	private:
	std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
