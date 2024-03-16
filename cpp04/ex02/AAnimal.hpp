#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal(); // virtual destructor is needed by compiler ---> deleting object of polymorphic class type ‘AAnimal’ which has non-virtual destructor might cause undefined behavior
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &rhs);
		std::string getType(void) const;
		void setType(std::string);
		void makeAnotherSound(void) const;
		virtual void makeSound(void) const = 0;
		// virtual void funcName() = 0 make Animal an ABSTRACT class.
		// this function is a pure virtual function that cannot be instantieted in the AAnimal class but need to have his own implementation in Cat and Dog

	protected:
		std::string _type;
};

#endif
