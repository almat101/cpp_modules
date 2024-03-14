#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog & copy);
		Dog & operator=(const Dog & rhs);
		void makeSound(void) const;
		std::string getDogIdea(int) const;
		void setDogIdea(int,std::string);
	private:
		Brain* dogBrain; //Dog contain a Brain* object
};

#endif
