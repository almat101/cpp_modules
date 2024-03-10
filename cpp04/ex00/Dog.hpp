#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog & copy);
		Dog & operator=(const Dog & rhs);
		void makeSound(void) const;

};

#endif
