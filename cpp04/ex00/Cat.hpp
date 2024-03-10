#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(Cat & copy);
		Cat & operator=(Cat & rhs);
		void makeSound(void) const;

};

#endif
