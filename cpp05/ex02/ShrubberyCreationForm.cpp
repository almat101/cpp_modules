#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("Shrubbery", 145, 137)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137)
{
	this->_target = target;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
	// You have to check that the form is signed and that the grade of the bureaucrat
	// attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
	validation(executor);
	std::string filename = this->getTarget() + "_shrubbery";

	std::ofstream ofs(filename.c_str());
	if (!ofs)
	{
		throw std::runtime_error("Unable to open file");
	}

	ofs << "         yc2ie\n"
		   "      gccee88ooc\n"
		   "   8O8O8Q8PoOb o8oo\n"
		   " OB69QO8PdUOpugoO9bD\n"
		   "CgggbU8OU qOp qOdoUOdc\n"
		   " 6OuU383/p u gcoUodpP\n"
		   "  obb9f ff0P /douUP\n"
		   "      6oo ccP dUP\n"
		   "       <0O()O0>\n"
		   "        |||||\n"
		   "        |||||\n"
		   "        |||||\n"
		   "        |||||\n"
		   ".......<|||||>.........\n";
	ofs.close();
}
