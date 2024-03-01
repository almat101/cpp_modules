#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(4);
	Fixed b(2);
	Fixed c(10);
	Fixed d(b);

	// a = Fixed(1234.4321f); // first call copy

	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;

	// Fixed f;

	// f = a * b + c * d;
	if (a > b)
		std::cout << "a is greater than b \n";
	else
		std::cout << "a is not greater than b \n";

	if (b < c)
		std::cout << "b is minus than c \n";
	else
		std::cout << "b is not minus than c \n";
	// std::cout << f << std::endl;
	return 0;
}
