#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat Edward = Bureaucrat("Edward", 1);
		Form Green = Form("Green", 42, 42);

		Edward.signForm(Green);
		std::cout << Green;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat Edward = Bureaucrat("Edward", 9);
		Form Black = Form("Black", 1 , 42);

		Edward.signForm(Black);
		std::cout << Black;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
