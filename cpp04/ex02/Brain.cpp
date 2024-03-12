#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created!" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "I have no idea what im doing";
	//	std::cout << *this->_ideas << std::endl;
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructed!" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called!" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain copy assignment operator = called!" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdea(int i) const
{
	return this->_ideas[i];
}

void Brain::setIdea(int i,std::string idea)
{
	this->_ideas[i] = idea;
}
