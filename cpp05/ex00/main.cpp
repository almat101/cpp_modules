#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Boro",1);
		Bureaucrat c("Cico", 150);
		Bureaucrat e;

		std::cout << c;
		c.increment();
		std::cout << c;

		std::cout << b;
		b.decrement();
		std::cout << b;
		b.decrement();
		std::cout << b;

		std::cout << e;
		e.increment();
		std::cout << e;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

// The thrown exceptions must be catchable using try and catch blocks:
// try
// {
// /* do some stuff with bureaucrats */
// }
// catch (std::exception & e)
// {
// /* handle exception - the `catch(std::exception &e)` block is handling any exceptions that are
// thrown within the `try` block, and printing a description of the exception to the console.
// e.what()` is called to get a string that describes the exception. /*
// }
