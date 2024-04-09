#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>

class AForm;

class Intern
{
	public :
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern & operator=(const Intern & rhs);

		AForm*  makeForm(std::string form_name, std::string target);
};

typedef AForm* (*FormCreator)(std::string);

#endif
