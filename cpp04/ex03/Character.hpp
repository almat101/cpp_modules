#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
	std::string _name;
	AMateria* _inventory[4]; // from subject at the construction the inv is empty so is NULL

	public:
		Character();
		Character(std::string); // from subject
		~Character();
		Character(const Character & copy);
		Character & operator=(const Character & rhs);
		//ICharacter methods
		std::string const & getName() const;


};

#endif
