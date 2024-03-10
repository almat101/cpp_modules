#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat & copy);
		WrongCat & operator=(WrongCat & rhs);
		void makeSound(void) const;

};

#endif
