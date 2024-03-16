#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &rhs);
		//abstract methods
		Cure* clone(void) const;
		void use(ICharacter& target);

};

#endif
