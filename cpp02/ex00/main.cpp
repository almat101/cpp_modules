#include "Fixed.hpp"

int main(void)
{
	Fixed a;

	Fixed b(a); // copy constructor
	Fixed c;

	c = a;		// copy assignment operator overload

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	a = a;			//self assignment

	return 0;
}
