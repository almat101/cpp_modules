#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed const a(4);
	Fixed b(3.14f);
	Fixed const c(10);
	Fixed d(4);

	// a = Fixed(1234.4321f); // first call copy

	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;

	// chiamata ad una funzione statica Class::nomeFunzione()
	std::cout << "a value is " << a << " b value is " << b << " c value is " << c << " d value is " << d << std::endl;
	std::cout << " il maggiore tra a e b con la static " << Fixed::max(a, b) << std::endl;
	std::cout << " il maggiore tra a e c con la static const " << Fixed::max(a, c) << std::endl;
	std::cout << " il minore tra d e b con la static " << Fixed::min(d, b) << std::endl;
	std::cout << " il minore tra c e a con la static const " << Fixed::min(c, a) << std::endl;

	// Fixed f;
	// f = a * b + c * d;
	// std::cout << f << std::endl;
	if (a == b)
		std::cout << " a is double equal to b \n";
	else
		std::cout << " a is not double equal to b \n";

	std::cout << "a value is " << a << " d value is " << d << std::endl;
	if (a == d)
		std::cout << " a is double equal to d \n";
	else
		std::cout << " a is not double equal to d \n";

	std::cout << "b value is " << b << " c value is " << c << std::endl;
	if (b < c)
		std::cout << " b is minus than c \n";
	else
		std::cout << " b is not minus than c \n";

	std::cout << "c value is " << c << " d value is " << d << std::endl;
	if (c != d)
		std::cout << " c is not double equal to d \n";
	else
		std::cout << " c is double equel than c \n";

	return 0;
}
