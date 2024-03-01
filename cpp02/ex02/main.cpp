#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(4);
	Fixed b(3.14f);
	Fixed c(10);
	Fixed d(4);

	// a = Fixed(1234.4321f); // first call copy

	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;

	// chiamata ad una funzione statica Class::nomeFunzione()
	std::cout << "il maggiore tra a e b is " << Fixed::max(a, b) << std::endl;
	// Fixed f;
	// f = a * b + c * d;
	// std::cout << f << std::endl;
	if (a == b)
		std::cout << "a is double equal to b \n";
	else
		std::cout << "a is not double equal to b \n";

	if (a == d)
		std::cout << "a is double equal to d \n";
	else
		std::cout << "a is not double equal to d \n";

	if (b < c)
		std::cout << "b is minus than c \n";
	else
		std::cout << "b is not minus than c \n";

	return 0;
}
