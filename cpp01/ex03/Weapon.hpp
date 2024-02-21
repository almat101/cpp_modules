#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	const std::string&	get_type(void) const;
	void				set_type(std::string);

	private:
	std::string	_type;

};

#endif
