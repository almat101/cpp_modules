#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("",1);

		std::cout << b;
		b.decrement();
		std::cout << b;
		b.decrement();
		std::cout << b;
	}
	//this will catch std::exceptions only
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Cico", 1);

		std::cout << c;
		c.increment();
		std::cout << c;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Boro",150);

		std::cout << b;
		b.decrement();
		std::cout << b;
		b.decrement();
		std::cout << b;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		Bureaucrat e;

		std::cout << e;
		e.increment();
		std::cout << e;
		e.decrement();
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
