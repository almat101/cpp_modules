#include "whatever.hpp"
#include <iostream>

int main( void )
{
	int a = 2;
	int b = 3;
	float g = -1.2e18f;
	float f = -1.2e37f;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	::swap(g, f);
	std::cout << "g = " << g << ", f = " << f << std::endl;
	std::cout << "min( g, f ) = " << ::min( g, f ) << std::endl;
	std::cout << "max( g, f ) = " << ::max( g, f ) << std::endl;
	return 0;
}
