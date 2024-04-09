#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("Robotomy", 72, 45)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45)
{
	this->_target = target;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	/*
	Makes some drilling noises. Then, informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, informs that the robotomy failed.
	*/
	validation(executor);
	std::cout << "*metal perforation soundsss*" << std::endl;
	srand(time(NULL)); // Seed for the random number generator
	if (rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " has failed to be robotomized" << std::endl;
}
