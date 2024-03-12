#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal(); // virtual destructor is needed by compiler ---> deleting object of polymorphic class type ‘Animal’ which has non-virtual destructor might cause undefined behavior
	Animal(const Animal &copy);
	Animal &operator=(const Animal &rhs);
	std::string getType(void) const;
	void setType(std::string);
	void makeAnotherSound(void) const;
	virtual void makeSound() const = 0; 
	// virtual void funcName() = 0 make Animal an ABSTRACT class.
	// this function is a pure virtual function that cannot be instantieted in the Animal class but need to have his own implementation in Cat and Dog 

protected:
	std::string _type;
};

#endif
