#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat Edward = Bureaucrat("Edward", 138); // 137 is the grade required to execute the shrubbery form
		ShrubberyCreationForm home = ShrubberyCreationForm("home");

		Edward.executeForm(home);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Fry = Bureaucrat("Fry", 45); // 45 is the grade required to execute the robotomy form
		RobotomyRequestForm robot = RobotomyRequestForm("robot");

		Fry.executeForm(robot);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Bender = Bureaucrat("Bender", 5); // 5 is the grade required to execute the presidential form
		PresidentialPardonForm clinton = PresidentialPardonForm("clinton");

		Bender.executeForm(clinton);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
