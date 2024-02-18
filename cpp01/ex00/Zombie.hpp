#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
	Zombie();
	Zombie(std::string);
	~Zombie();
	std::string get_name(void);
	void		set_name(std::string);

	private:
	std::string	name;
};

#endif
