#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();							// default constructor
	~Fixed();							// destructor
	Fixed(const Fixed &);				// copy constructor
	Fixed& operator=(const Fixed &);	// copy assignment operator overload.
	int getRawBits( void ) const;		//member function getRawBits (getter)
	void setRawBits( int const raw );	//member function setRawBits (setter)

private:
	int					_value;
	static const int	_FractionalBits = 8;
};

#endif
