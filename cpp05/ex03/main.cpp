#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern someRandomIntern;

		AForm* ppf;
		ppf = someRandomIntern.makeForm("Presidential pardon", "Bender");
		(void)ppf;

		// Bureaucrat b("Bender", 1);
		// if (ppf != NULL)
		// 	b.executeForm(*ppf);
		// else
		// 	std::cout << "Cannot execute form: pointer is NULL" << std::endl;
		delete ppf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
