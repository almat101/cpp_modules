#include "Fixed.hpp"
#include <iostream>

// int main(void)
// {
// 	Fixed const a(4);
// 	Fixed b(3.14f);
// 	Fixed const c(10);
// 	Fixed d(4);

// 	std::cout << std::endl;
// 	std::cout << b.getRawBits();
// 	std::cout << "   const a value is " << a << std::endl;
// 	std::cout << "b value is " << b << std::endl;
// 	std::cout << "const c value is " << c << std::endl;
// 	std::cout << "d value is " << d << std::endl;
// 	std::cout << std::endl;

// 	// call to static function is Class::nomeFunzione()
// 	std::cout << "max value from d and b with static function " << Fixed::max(d, b) << std::endl;
// 	std::cout << "max value from a and c with const static function " << Fixed::max(a, c) << std::endl;
// 	std::cout << "min value from d and b with static function " << Fixed::min(d, b) << std::endl;
// 	std::cout << "min value from c and z with static function " << Fixed::min(c, a) << std::endl;
// 	std::cout << std::endl;
// 	std::cout << std::endl;

// 	if (a == b)
// 		std::cout << " a is double equal to b \n";
// 	else
// 		std::cout << " a is not double equal to b \n";

// 	if (a == d)
// 		std::cout << " a is double equal to d \n";
// 	else
// 		std::cout << " a is not double equal to d \n";

// 	if (b < c)
// 		std::cout << " b is minus than c \n";
// 	else
// 		std::cout << " b is not minus than c \n";

// 	if (c != d)
// 		std::cout << " c is not double equal to d \n";
// 	else
// 		std::cout << " c is double equal than c \n";

// 	Fixed m = b + c - d;

// 	std::cout << std::endl;
// 	std::cout << " m ( b + c - d) value is " << m << std::endl;
// 	std::cout << std::endl;

// 	Fixed f;
// 	f = a * b - c * d;

// 	std::cout << std::endl;
// 	std::cout << " f value (a * b - c * d) is " << f << std::endl;
// 	std::cout << std::endl;

// 	return 0;
// }

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// Fixed c(2);
	// Fixed b = ++c;
	// std::cout << c << std::endl;
	// std::cout << b << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
