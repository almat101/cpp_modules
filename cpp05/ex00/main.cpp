#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *b = new Bureaucrat("Boro", 1);

	std::cout << "Bureacrat " << b->getName() << " grade " << b->getGrade() << std::endl;

	delete b;

	return 0;
}
