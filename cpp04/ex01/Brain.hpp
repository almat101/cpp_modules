#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain & copy);
		Brain &operator=(const Brain &rhs);
		std::string getIdea(int) const;
		void setIdea(int,std::string);


	private:
		std::string _ideas[100];
};

#endif
