#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &rhs);
		void makeSound(void) const;
		std::string getCatIdea(int) const;
		void setCatIdea(int,std::string);
	private:
		Brain *catBrain; // Cat contain a Brain* object
};

#endif
