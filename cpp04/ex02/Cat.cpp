#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Cat constructor called!" << std::endl;
	this->_type = "Cat";
	this->catBrain = new Brain(); // upon construction the Cat has is own Brain
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete this->catBrain; //upon destruction Cat delete his Brain
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	this->catBrain = new Brain(*copy.catBrain);
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called!" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		delete this->catBrain; // this delete is crucial to avoid memory leaks, you have to delete the old Brain before assigning the new one
		this->catBrain = new Brain(*rhs.catBrain);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "*Miaaaooo Miaaooo*" << std::endl;
}

std::string Cat::getCatIdea(int i) const
{
	return this->catBrain->getIdea(i);
}

void Cat::setCatIdea(int i, std::string catIdea)
{
	this->catBrain->setIdea(i, catIdea);
}
