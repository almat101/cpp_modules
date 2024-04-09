#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat Edward = Bureaucrat("Edward", 135); // 137 is the grade required to execute the shrubbery form
		ShrubberyCreationForm home = ShrubberyCreationForm("home");

		Edward.signForm(home);
		Edward.executeForm(home);
		std::cout << home;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Fry = Bureaucrat("Fry", 47); // 45 is the grade required to execute the robotomy form
		RobotomyRequestForm robot = RobotomyRequestForm("robot");

		Fry.signForm(robot);
		Fry.executeForm(robot);
		std::cout << robot;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Bender = Bureaucrat("Bender", 1); // 5 is the grade required to execute the presidential form
		PresidentialPardonForm clinton = PresidentialPardonForm("clinton");

		Bender.signForm(clinton);
		Bender.executeForm(clinton);
		std::cout << clinton;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
