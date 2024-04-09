#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5)
{
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("Presidential", 25, 5)
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5)
{
	this->_target = target;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	/*
		Informs that <target> has been pardoned by Zaphod Beeblebrox.
	*/
	validation(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
