#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice &copy);
	Ice &operator=(const Ice &rhs);
	Ice* clone(void) const;
};

#endif
