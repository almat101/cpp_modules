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
	virtual void makeSound(void) const; // virtual enable polymorphism

protected:
	std::string _type;
};

#endif
