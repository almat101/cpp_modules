#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &rhs);
		std::string getType(void) const;
		void setType(std::string);
		void makeSound(void) const; // no virtual no polymorphism

	protected:
		std::string _type;
};

#endif
