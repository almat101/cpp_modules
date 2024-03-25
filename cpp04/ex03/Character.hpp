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

		AMateria* _tmp[100]; // inventory of Amateria that are unequipped!

	public:
		Character();
		Character(std::string); // from subject
		~Character();
		Character(const Character &copy);
		Character &operator=(const Character &rhs);
		std::string const & getCharacterAMateriaType(int idx) const;
		// ICharacter methods
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
