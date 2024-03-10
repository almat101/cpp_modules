#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog & copy);
		Dog & operator=(Dog & rhs);
		void makeSound(void) const;

};

#endif
