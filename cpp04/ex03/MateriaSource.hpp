#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria *_materiaSourceInventory[4];
		//std::string _type;

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource &src);
		MateriaSource &operator=(MateriaSource &rhs);

		// pure virtual function of the IMateriaSource that MateriaSource has to override
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
};

#endif
