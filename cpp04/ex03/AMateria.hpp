#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter; // this is needed by compiler for the virtual void use function

class AMateria
{
protected:
	std::string _type;

private:
	AMateria &operator=(const AMateria &rhs);

public:
	AMateria();
	virtual ~AMateria(); // AMateria need a virtual destructor to avoid leaks, ( deleting an AMateria * i = new Ice()  cause a compilation error and invoke the use of a virtual destructor)
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	// getter
	std::string const &getType() const; // Returns the materia type
	// pure virtual function
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
