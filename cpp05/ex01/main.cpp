#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat Edward = Bureaucrat("Edward", 1);
		Form Green = Form("Green", 42, 42);

		Edward.signForm(Green);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Edward = Bureaucrat("Edward", 10);
		Form Black = Form("Black", 3, 42);

		Edward.signForm(Black);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
