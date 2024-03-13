#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		virtual ~AMateria(); // AMateria need a virtual destructor to avoid leaks, ( deleting an AMateria * i = new Ice()  cause a compilation error and invoke the use of a virtual destructor)
		AMateria(std::string const & type);
		AMateria(const AMateria & copy);
		AMateria & operator=(const AMateria & rhs);
		//getter
		std::string const & getType() const; //Returns the materia type
		//pure virtual functions
		virtual AMateria* clone() const = 0;
		//virtual void use(ICharacter& target);
};

#endif
