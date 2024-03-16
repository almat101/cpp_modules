#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource constructor with empty materiaSourceInventory" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_materiaSourceInventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	//destruct all materia stored
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaSourceInventory[i] != NULL)
			delete _materiaSourceInventory[i];
	}
}

MateriaSource::MateriaSource(MateriaSource &src)
{
	*this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materiaSourceInventory[i])
				delete _materiaSourceInventory[i];
			_materiaSourceInventory[i] = rhs._materiaSourceInventory[i];
		}
	}
	return *this;
}

// pure virtual methods of IMateriaSource that AMateria has to override

/*learnMateria(AMateria*)
Copies the Materia passed as a parameter and store it in memory so it can be cloned
later. Like the Character, the MateriaSource can know at most 4 Materias. They
are not necessarily unique.
*/
void MateriaSource::learnMateria(AMateria *m)
{
	// std::cout << "im in learnmateria " << std::endl;
	if (m == NULL)
	{
		std::cerr << "cannot learn no Materia" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaSourceInventory[i] == NULL)
		{
			this->_materiaSourceInventory[i] = m;
			// std::cout << "Materia type " << this->_materiaSourceInventory[i]->getType() << " cloned" << std::endl;
			return;
		}
	}
	std::cerr << "cannot learn a Materia" << std::endl;
}

/*createMateria(std::string const &)
Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
*/

AMateria *MateriaSource::createMateria(std::string const &type)
{

	// std::cout << "im in create materia" << std::endl;
	//   std::cout << this->_materiaSourceInventory[0]->getType() << std::endl;
	if (type == "ice" || type == "cure")
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_materiaSourceInventory[i] != NULL)
			{
				//	std::cout << this->_materiaSourceInventory[i]->getType() << std::endl;
				if (this->_materiaSourceInventory[i] != NULL && this->_materiaSourceInventory[i]->getType() == type)
					return this->_materiaSourceInventory[i]->clone();
			}
		}
		std::cerr << "cannot create Materia" << std::endl;
		return NULL;
	}
	else
	{
		std::cerr << "wrong type of Materia" << std::endl;
		return NULL;
	}
}
