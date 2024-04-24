#include "whatever.hpp"
#include <iostream>

int main( void )
{
    int a = 2;
    int b = 3;
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
    return 0;
}

// int main (void)
// {
    // int a = 5;
    // int b = 10;
    // float c = 1.2e30;
    // float d = 1.2e10;
    // int e = ::max(a,b);
    // float f = ::max(c,d);
    // int g = ::min(a,b);
    // float h = ::min(c,d);



    // std::cout << "max " << a << " " << b << " is " <<  e << std::endl;
    // std::cout << "max " << c << " " << d << " is " <<  f << std::endl;
    // std::cout << "min " << a << " " << b << " is " <<  g << std::endl;
    // std::cout << "min " << c << " " << d << " is " <<  h << std::endl;
    // std::cout << "a is " << a <<  " b is " << b << std::endl;
    // std::cout << "swap a,b " << std::endl;
    // ::swap(a,b);
    // std::cout << "now swapped a is " << a << " and b is " << b << std::endl;

// }