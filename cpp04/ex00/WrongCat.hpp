#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat & copy);
		WrongCat & operator=(const WrongCat & rhs);
		void makeSound(void) const;

};

#endif
